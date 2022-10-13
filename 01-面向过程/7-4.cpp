#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

void split(string str, vector<string> &res, char flag) {
  res.clear();
  stringstream ss(str);
  string temp;
  while(getline(ss, temp, flag)) {
    res.push_back(temp);
  }
}

int main() {
  int weeks[20] {0}, fit_week, to_week;
  vector<string> weeks_string;
  string str;

  getline(cin, str);
  split(str, weeks_string, ' ');
  cin >> fit_week >> to_week;

  for(auto it : weeks_string) {
    if(it.find('-') != string::npos) {
      vector<string> two_weeks;
      split(it, two_weeks, '-');
      int start_week = stoi(two_weeks.at(0));
      int end_week = stoi(two_weeks.at(1));
      for(int j {start_week}; j <= end_week; j++){
        weeks[j - 1] = j;
      }
    }else {
      weeks[stoi(it) - 1] = stoi(it);
    }
  }

  if(weeks[fit_week - 1] && !weeks[to_week - 1]) {
    weeks[fit_week - 1] = 0;
    weeks[to_week - 1] = to_week;

    vector<int> road;
    string result {""};
    for(int i {0}; i < 20; i ++) {
      int week = weeks[i];
      if(week) {
        road.push_back(week);
      }
      if(!week || i == 19) {
        if(road.size() > 1) {
          result += to_string(road.at(0)) + "-" + to_string(road.at(road.size() - 1)) + " ";
          road.clear();
        }else if(road.size() == 1){
          result += to_string(road.at(0)) + " ";
          road.clear();
        }
      }
    }
    result.erase(result.find_last_not_of(" ") + 1);
    cout << result;
  }else {
    cout << "not available";
  }

  return 0;
}