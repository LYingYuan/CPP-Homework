#include  <iostream>
#define PI 3.14159
using namespace std;

class Shape{
public:
    double getArea(){return 0;}
    double getPerimeter(){return 0;}
};

class Rectangle: public Shape {
protected:
    double  height;
    double  width;
public:
    Rectangle() {};
    Rectangle(double _height, double _width) {
        height = _height;
        width = _width;
    }
    double getArea(){
        return  height * width;
    }
    double getPerimeter(){
        return  2 * (height + width);
    }
    void Print(){
        cout << "Width=" << width << ",Height=" << height << endl;
    }
};


class Square: public Rectangle{
  protected:
  double side;
  public:
  Square(){}
  Square(double _side){
    side = _side;
  }
  double getArea(){
    return side * side;
  }
  double getPerimeter(){
    return side * 4;
  }
  void Print(){
    cout << "Side=" << side << endl;
  }
};

class Circle: public Shape{
  protected:
  double center[2];
  double radius;

  public:
  Circle(){}
  Circle(double _center_1, double _center_2, double _radius){
    center[0] = _center_1;
    center[1] = _center_2;
    radius = _radius;
  }
  double getArea(){
    return radius * radius * PI;
  }
  double getPerimeter(){
    return 2 * radius * PI;
  }
  void Print(){
    cout << "Center=[" << center[0] << "," << center[1] << "],Adius=" << radius << endl;
  }
};


int  main()  {
    double  ra,  rb;
    cin  >>  ra  >>  rb;
    Rectangle  r1(ra,  rb);
    double  sa;
    cin  >>  sa;
    Square  s1(sa);
    double  ca,  cb,  cc;
    cin  >>  ca  >>  cb  >>  cc;
    Circle  c1(ca,  cb,  cc);
    cout  <<  "Rectangle"  <<  endl;
    r1.Print();
    cout  <<  "Area="  <<  r1.getArea()  <<  endl;
    cout  <<  "Perimeter="  <<  r1.getPerimeter()  <<  endl  ;
    cout  <<  "Square"  <<  endl;
    s1.Print();
    cout  <<  "Area="  <<  s1.getArea()  <<  endl;
    cout  <<  "Perimeter="  <<  s1.getPerimeter()  <<  endl;
    cout  <<  "Circle"  <<  endl;
    c1.Print();
    cout  <<  "Area="  <<  c1.getArea()  <<  endl;
    cout  <<  "Perimeter="  <<  c1.getPerimeter()  <<  endl;
    return  0;
}
