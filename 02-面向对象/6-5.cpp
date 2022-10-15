#include <iostream>
using namespace std;

class A{
  public:
  A(int _x, int _y){
    x = _x;
    y = _y;
  }
  virtual int op () =0;
  
  int x;
  int y;
};
ostream& operator<<(ostream &os, A &a){
  return os << "(" << a.x << "," << a.y << ")";
};


class B:public A
{
    public:
        B(int _x, int _y):A(_x,_y){    };
        int op(){return (x+y)*2;};
};

class C:public A
{
    public:
        C(int _x, int _y):A(_x,_y){    };
        int op(){return x+y+20;};
};

int main()
{
    int i,j;
    cin>>i>>j;    
    A *b,*c;
    b=new B(i,j);
    c=new C(i,j);
    
    if(b->op()>=c->op()) 
        cout<<"b:"<<*b<<":"<<b->op();
    else
        cout<<"c:"<<*c<<":"<<c->op();
    
    free(b);
    free(c);
    return 0;    
} 
