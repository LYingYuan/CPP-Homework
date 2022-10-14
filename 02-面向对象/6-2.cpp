#include <iostream>
#include <string>
using namespace std;

class Animal{
  private:
    int m_nWeightBase;
  protected:
    int m_nAgeBase;
  public:
    void set_weight(int weight);
    int get_weight();
    void set_age(int age);
};
void Animal::set_weight(int weight){
  m_nWeightBase = weight;
}
int Animal::get_weight(){
  return m_nWeightBase;
}
void Animal::set_age(int age){
  m_nAgeBase = age;
}

class Cat : private Animal{
  private:
    string m_strName;
  public:
    Cat(string name);
    void set_print_age();
    void set_print_weight();
};
Cat::Cat(string name){
  m_strName = name;
}
void Cat::set_print_age(){
  set_age(5);
  cout << m_strName << ", age = " << m_nAgeBase << endl;
}
void Cat::set_print_weight(){
  set_weight(6);
  cout << m_strName << ", weight = " << get_weight() << endl;
}


int main()
{
    Cat cat("Persian");     //定义派生类对象cat
    cat.set_print_age();
    cat.set_print_weight(); //派生类对象调用自己的公有函数
    return 0;
}
