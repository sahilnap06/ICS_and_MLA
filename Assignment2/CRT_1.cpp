#include<bits/stdc++.h>
using namespace std;

int modInverse(int n, int m)
{
    n = n % m;
    for(int i = 1; i < m; i++)
        if((n * i) % m == 1)
            return i;
	return -1;
}

int main(){
	int n, M, x;
	cout<<"Enter the number of equations : ";
	cin>>n;
	int remainder[n], divisor[n], indi_modulus[n], m_inverse[n];	// indi_modulus is i
	for(int i=0;i<n;i++){
		cout<<"\nEnter equation no. "<<i+1<<" :\n";
		cout<<"For x = a (mod b), input a and b"<<endl;
		cout<<"Enter a : ";
		cin>>remainder[i];
		cout<<"Enter b : ";
		cin>>divisor[i];
	}

	// common modulus (product of all the divisors)
	M = 1;
	for(int i=0;i<n;i++)
		M = M * divisor[i];
		
	for(int i=0;i<n;i++)
		indi_modulus[i] = M/divisor[i];
		
	for(int i=0;i<n;i++)
		m_inverse[i] = modInverse(indi_modulus[i],divisor[i]);
		
	x = 0;
	for(int i=0;i<n;i++){
		x = x + (remainder[i]*indi_modulus[i]*m_inverse[i]);
	}
	x = x % M;
		
	cout<<"\nThe Equations you input are :\n";
	for(int i=0;i<n;i++)
		cout<<"x = "<<remainder[i]<<" (mod "<<divisor[i]<<")"<<endl;
		
	cout<<"\nM = "<<M<<"\n\n";
	for(int i=0;i<n;i++)
		cout<<"M"<<i+1<<" = M / m"<<i+1<<" = "<<indi_modulus[i]<<endl;
	for(int i=0;i<n;i++)
		cout<<"\ny"<<i+1<<" = "<<m_inverse[i];
	cout<<"\n\nx = "<<x<<"\n";

	// for (int j = 0; j < n; j++)
	// 		if (x % divisor[j] != remainder[j])
	// 			break;

	// 	if (j == a.size()){
	// 		printf("Solution of the given equations is x=%d(mod %d)", x, M);
	// 		return 0;
	// 	}
}


/**
 * Output:
 * PS G:\College\CL7\assignment2> g++ .\CRT_1.cpp 
 * PS G:\College\CL7\assignment2> .\a.exe
 * Enter the number of equations : 3 
 * Enter equation no. 1 :
 * For x = a (mod b), input a and b
 * Enter a : 2
 * Enter b : 3
 * 
 * Enter equation no. 2 :
 * For x = a (mod b), input a and b
 * Enter a : 3
 * Enter b : 4
 * 
 * Enter equation no. 3 :
 * For x = a (mod b), input a and b
 * Enter a : 1
 * Enter b : 5
 * 
 * The Equations you input are :
 * x = 2 (mod 3)
 * x = 3 (mod 4)
 * x = 1 (mod 5)
 * 
 * M = 60
 * 
 * M1 = M / m1 = 20
 * M2 = M / m2 = 15
 * M3 = M / m3 = 12
 * 
 * y1 = 2
 * y2 = 3
 * y3 = 3
 * 
 * x = 11
 * 
 **/
