#include <iostream>
#include <string>

using namespace std;

int main(){
  int len;
  cin >> len;
  cin.ignore();
  string poem[len];

  for(int i = 0; i < len; i++){
    getline(cin, poem[i]);
  }
  // cout << "--------------------------" << endl;

  for(int i = 0; i < len; i++){
    int flag_right {0}, flag_left {0};
    string str = poem[i];

    int sep_index_left {0};
    for(; str[sep_index_left] != ','; sep_index_left++);
    if(str[sep_index_left - 3] == 'o' && str[sep_index_left - 2] == 'n' && str[sep_index_left - 1] == 'g'){
      flag_left = 1;
    }

    int sep_index_right {0};
    for(; str[sep_index_right] != '.'; sep_index_right++);
    if(str[sep_index_right - 3] == 'o' && str[sep_index_right - 2] == 'n' && str[sep_index_right - 1] == 'g'){
      flag_right = 1;
    }

    if(flag_left && flag_right){
      int space_sum {0}, end_index {0};
      for(int now_index {str.size()}; now_index >= 0; now_index --){
        if(str[now_index] == ' '){
          space_sum++;
          if(space_sum == 3){
            end_index = now_index;
          }
        }
      }
      for(int j {0}; j <= end_index; j++){
        cout << str[j];
      }
      cout << "qiao ben zhong." << endl;
      }else{
      cout << "Skipped" << endl;
      }
    }
  return 0;
}