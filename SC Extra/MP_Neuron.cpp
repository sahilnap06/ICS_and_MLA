#include <iostream>
#include <vector>
using namespace std;

int main() {
  int choice;
  int number_input, threshold = 0;
  std::vector<int> inputs;
  std::vector<float> weights;
  cout<<"Enter 1 for AND gate \n Enter 2 for OR gate \n Your choice :: ";
  cin>>choice;
  cout<<"Enter the number of inputs to the perceptron :: ";
  cin>>number_input;
  int value = 0;
    bool hasZero = false;      bool hasOne = false;
  switch (choice) {
    // AND gate
    case 1:
    {
        threshold = number_input;
        int temp1;
        float temp2;
        cout<<"For AND gate, give "<<number_input<<"inputs :: ";
        for(int i = 0;i < number_input; i++){
          cin>>temp1;
          if(temp1 == 0)
            hasZero = true;
          inputs.push_back(temp1);
        }
        cout<<"For AND gate, give "<<number_input<<"weights :: ";
        for(int i = 0;i < number_input; i++){
          cin>>temp2;
          weights.push_back((float)temp2);
        }
        for(int i = 0;i < number_input;i++){
          value += inputs[i] * weights[i];
        }
        if(hasZero)
          cout<<"Output :: 0"<<endl;
        else{
          if(value >= threshold){
            std::cout << "Output :: 1" << '\n';
          }
          else
            cout<<"Output :: 0"<<endl;
        }
        break;
      }
      //
      case 2:
      {
          threshold = 1;
          int temp1;
          cout<<"For OR gate, give "<<number_input<<"inputs :: ";
          for(int i = 0; i < number_input; i++){
            cin>>temp1;
            if(temp1 == 1)
              hasZero = true;
            inputs.push_back(temp1);
          }
          if(hasOne)
            cout<<"Output :: 1"<<endl;
          else{
              cout<<"Output :: 0"<<endl;
          }
          break;
        }
      default:
        cout<<"Wrong choice"<<endl;
        break;
  }

  return 0;
}
