#include <iostream>
#include <iomanip>

using namespace std;

int main(){
  int num1, num2, num3;
  cin >> num1 >> num2 >> num3;

  cout << "Sum is " << num1 + num2 + num3 << endl;
  cout << "Average is " << fixed << setprecision(1) << (num1 + num2 + num3) / 3.0 << endl;
  cout << "Product is " << num1 * num2 * num3 << endl;

  int small_num = num1;
  if(num2 < small_num){
    small_num = num2;
  }
  if(num3 < small_num){
    small_num = num3;
  }
  
  cout << "Smallest is " << small_num << endl;

  int large_num = num1;
  if(num2 > large_num){
    large_num = num2;
  }
  if(num3 > large_num){
    large_num = num3;
  }

  cout << "Largest is " << large_num;

  return 0;
}