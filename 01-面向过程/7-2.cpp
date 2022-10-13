#include <iostream>
#include <cmath>
#include <string>

using namespace std;

bool isPrimeNumber(int x) {
  if(x < 2) return 0;
	for (int i = 2; i <= sqrt(x); i++)
		if (x % i == 0) return 0;
	return 1;
}

int main(){
  int len, num_len, num;
  string str, result {"404"};
  cin >> len >> num_len;
  cin >> str;

  int right = 0;
  while(right + num_len <= len){
    num = stoi(str.substr(right, num_len));
    if(isPrimeNumber(num)){
      result = str.substr(right, num_len);
      break;
    }
    right ++;
  }
    cout << result;

  return 0;
}