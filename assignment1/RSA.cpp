#include <iostream>
#include <math.h>
using namespace std;

// finds GCD of two numbers a and b
int gcd(int a , int b)
{
   if(b==0) return a;
   a%=b;
   return gcd(b,a);
}

// calculate mod inverse of e (e*i ≡ 1 mod (p-1*q-1))
int modInverse(int e, int phi){
    e = e % phi;
    int i = 1;
    for(; i<phi;i++)
        if((e*i) % phi == 1)
            return i;
    return i;
}

// encrypts the given data and returns Cipher text
int encrypt(int plain_text, int e, int n){
    int cipher_text = plain_text;
    for(int i = 1; i< e;i++){
        cipher_text = ((cipher_text%n)*(plain_text%n))%n;
    }
    return cipher_text; // return cipher text
}

// decrypts the cipher and returns plain text
int decrypt(int cipher_text, int d, int n){
  int plain_text = cipher_text;
  for(int i = 1 ;i<d;i++){
    plain_text = ((plain_text % n)*(cipher_text%n))%n;
  }
  return plain_text;
}

int main(){
    // Selection of two prime numbers
    int p = 17;
    int q = 11;
    // Calculate n
    int n = p*q;
    // calculate phi
    int phi = (p-1)*(q-1);
    // calculate the relative prime number of phi
    // cout<<"Phi value is "<<phi<<endl;
    int e = 7; // temporary value of e (prime)
    // cout<<"e is "<<e<<endl;
    int track = 0;
    // find e such that is is replatively prime to n
    while(e < phi){
        track = gcd(e, phi);
        if(track == 1)
            break;
        else
            e++;
    }

    // calculate d such that d*e ≡ 1 mod (p-1 * q-1)
    int d = modInverse(e, phi);

    cout<<"p = "<<p<<endl<<"q = "<<q<<endl<<"N = (p*q) = "<<n<<endl;
    cout<<"phi = (p-1)*(q-1) = "<<phi<<endl;
    cout<<"VALUES of e AND d such that e*d equals 1 mod (phi)"<<endl<<"e = "<<e<<endl<<"d = "<<d<<endl;

    cout<<"Public key -> {e, n} is {"<<e<<", "<<n<<"}"<<endl;
    cout<<"Private key -> {d, n} is {"<<d<<", "<<n<<"}"<<endl;

    int plain_text;
    cout<<"Enter the data to encrypt :: ";
    cin>>plain_text;
    int cipher_text = encrypt(plain_text,e,n); //encrypting using public key
    cout<<"Cipher text is "<<cipher_text<<endl;

    int returned_decrypted_data = decrypt(cipher_text, d, n); //decryption using private key
    cout<<"Decrypted text is "<<returned_decrypted_data<<" !!"<<endl;
    return 0;
}
