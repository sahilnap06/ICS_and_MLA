#include <iostream>
#include <math.h>
using namespace std;

int gcd(int a , int b)
{
   if(b==0) return a;
   a%=b;
   return gcd(b,a);
}

int modInverse(int e, int phi){
    e = e % phi;
    int i = 1;
    for(; i<phi;i++)
        if((e*i) % phi == 1)
            return i;
    return i;
}

int encrypt(int plain_text, int e, int n){
    int temp = plain_text;
    for(int i = 0; i< e;i++){
        plain_text = ((plain_text%n)*(temp%n))%n;
    }
    return plain_text; // return cipher text
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
    int e = 7;
    int track = 0;
    while(e < phi){
        track = gcd(e, phi);
        if(track == 1)
            break;
        else 
            e++;
    }
    cout<<"e is "<<e<<endl;
    // calculate d such that d*e ≡ 1 mod (13*19)
    
    int d = modInverse(e, phi);

    cout<<"d value is "<<d<<endl;
    cout<<"Public key -> {"<<e<<","<<n<<"}"<<endl;
    cout<<"Private key -> {"<<d<<","<<n<<"}"<<endl;

    int plain_text;
    cout<<"Enter the data to encrypt :: ";
    cin>>plain_text;
    int cipher_text = encrypt(plain_text,e,n); //encrypting using public key
    cout<<"Cipher text is "<<cipher_text<<endl;

    return 0;
}