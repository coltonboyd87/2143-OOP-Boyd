#include <iostream>
using namespace std; 

//Class - Triangle 
class Triangle 
{
  //Private members 
  private:
  double length;
  double width; 

//Public member functions
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
  Triangle Tri;
  Tri.setLength(56);
  Tri.setWidth(68);
  cout << Tri.getAreaTri();
  return 0;
}
