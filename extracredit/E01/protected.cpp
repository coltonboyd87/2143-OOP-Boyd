#include <iostream>
using namespace std; 

//Base Class - Rectangle 
class Rectangle 
{
  protected:
  double length;
  double width;   //protected members of Rectangle that are accessed by Triangle

};

//Derived Class - Triangle
class Triangle: public Rectangle
{
  public:
  void setLength(double l)
  {
    length = l;
  }

  void setWidth(double w)
  {
    width = w;
  }
  double getAreaTri()
  {
    return (length*width)/2;
  }
};

//Main function 
int main()
{
  Rectangle Rec;
  Triangle Tri;
  Tri.setLength(5);
  Tri.setWidth(6);
  cout << Tri.getAreaTri();
  return 0;
}
