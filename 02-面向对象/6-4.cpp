#include <iostream>
using namespace std;

template <class T>
class Vector {
  private:
    int index;
    int size;
    T* data;

  public:
    Vector(){
      index = 0;
      size = 100;
      data = new T[size];
    }
    int add(int i){
      data[index] = i;
      index ++;
      return index - 1;
    }
    int get_size(){
      return index;
    }
    void remove(int _index){
      for(int i {_index}; i < 99; i++){
        data[i] = data[i + 1];
      }
      index --;
    }
    // TODO:怎么确定前面是T&的？
    T operator[](int i) const{
      return data[i];
    }
};


int main()
{
    Vector<int> vint;
    int n,m;
    cin >> n >> m;
    for ( int i=0; i<n; i++ ) {
        //    add() can inflate the vector automatically
        vint.add(i);    
    }
    //    get_size() returns the number of elements stored in the vector
    cout << vint.get_size() << endl;
    cout << vint[m] << endl;
    //    remove() removes the element at the index which begins from zero
    vint.remove(m);
    cout << vint.add(-1) << endl;
    cout << vint[m] << endl;
    Vector<int> vv = vint;
    cout << vv[vv.get_size()-1] << endl;
    vv.add(m);
    cout << vint.get_size() << endl;
}
