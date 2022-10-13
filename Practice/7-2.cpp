#include <iostream>
#include <iomanip>

using namespace std;

int main(){
  int original_price, discount;
  cin >> original_price >> discount;

  cout << fixed << setprecision(2) << original_price * discount / 10.0 << endl;

  return 0;
}