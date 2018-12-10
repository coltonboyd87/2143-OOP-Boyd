#include <iostream>
using namespace std; 

class Rectangle 
{
  private:
  double length;
  double width; 

  public:
  void setLength(double l)
  {
    length = l;
  }

  void setWidth(double w)
  {
    width = w;
  }

  double getArea()
  {
    return length *width;
  }
};

int main()
{
  Rectangle Rec;
  Rec.setLength(5.0);
  Rec.setWidth(7.0);
   cout << Rec.getArea();
  return 0;
}
