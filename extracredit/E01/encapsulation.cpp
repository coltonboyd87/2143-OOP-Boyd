#include <iostream>
using namespace std; 

//Class Rectangle 
class Rectangle 
{
  //Private data memebrs 
  private:
  double length;
  double width; 

  //Pubic functions to manipulate private data members
  //Include setters and getters 
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

//Main function 
int main()
{
  Rectangle Rec;
  Rec.setLength(5.0);
  Rec.setWidth(7.0);
   cout << Rec.getArea();
  return 0;
}
