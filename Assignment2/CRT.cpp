#include <iostream>
#include <vector>
using namespace std;

// Calculate GCD recursively
int GCD(int first, int second){
  if(second == 0)
    return first;

  return GCD(second, first % second);
}

// calculate LCM of all divisors, using GCD
int LCM(int gcd, std::vector<int> b){
  int total = 1;
  for(auto it: b){
    total *= (it);
  }
  return total/gcd;
}

// Implements CRT
int evaluate(std::vector<int> a, std::vector<int> b){
  // calculate the product of all the numbers
  int c = 1;
  for(auto it: b){
    c *= (it);
  }

  //calculate GCD of all the numbers
  int gcd = 0;
  for(int i = 0; i<b.size(); i++){
    gcd = GCD(gcd, b[i]);
  }

  // Calculate LCM of all divisors
  int lcm = LCM(gcd, b);

  // for all numbers (x) in the range of LCM, if x != a (mod b), then that cannot be solution
  for (int k = 0; k < lcm; k++){
		int j;
		for (j = 0; j < a.size(); j++)
			if (k % b[j] != a[j])
				break;

		if (j == a.size()){
			printf("Solution of the given equations is x=%d(mod %d)", k, c);
			return 0;
		}
	}

	return -1;	 // no solution
}

int main(){
  std::vector<int> a; std::vector<int> b;
  for(int i = 0;i<3;i++){
    int remainder; int divisor;
    cout<<"For x = a (mod b), input a and b"<<endl;
    cout<<"a = "; cin>>remainder;
    cout<<"b = "; cin>>divisor; cout<<endl;
    a.push_back(remainder);
    b.push_back(divisor);
    std::cout << "The equation you entered is x = "<<a[i]<<" (mod "<<b[i]<<")\n";
  }
  int result = evaluate(a,b);
  if(result == -1){
    cout<<"The given equations have no result"<<endl;
  }
  return 0;
}
