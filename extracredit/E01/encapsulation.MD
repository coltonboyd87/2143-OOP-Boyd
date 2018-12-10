# Encapsulation 
- Can be described as the process of wrapping data members and functions in a single unit. 
- The main objective of this is to prevent access to data directly. Access is provided by functions of the class. 
- Encapsulation is an umportant feature called data hiding. 

## This is achieved by: 
- Declaring data members private. 
- Make public setter and getter methods for each data memeber to set and get values of our data members. 

## Example: 

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

## Output: 
35
