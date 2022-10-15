#include <iostream>

using namespace std;

class Date{
  protected:
  int month;
  int day;
  int year;
  string month_en;
  void changeMonth(int _month){
    string m[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    month_en = m[_month - 1];
  }

  public:
  Date(){};
  Date(int _year, int _month, int _day){
    year = _year;
    month = _month;
    day = _day;
    changeMonth(_month);
  }
  void print_1(){
    cout << month << "--" << day << "--" << year << endl;
  }
  void print_2(){
    cout << month_en << " " << day << ", " << year << endl;
  }
  void print_3(){
    cout << day << " " <<  month_en << " " << year;
  }
};

int main(){
  int year, month, day;
  cin >> year >> month >> day;
  Date date(year, month, day);
  date.print_1();
  date.print_2();
  date.print_3();
  return 0;
}