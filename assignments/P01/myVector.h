#include <iostream>

using namespace std;

/****************************
*                           *
*        Class              *
*     Implementation        *
*                           *
*                           *
****************************/
class myVector {
private:
	int *theVector;
	int vSize;		//Private variables
	int minSize;
	int index;
	double percentFull();
	void growArr();		//Private methods 
	void shrinkArr();
public:
	myVector();		//Constructors
	myVector(int size);
	void print();		//Public Methods 
	int pop_back();
	void push_back(int val);
	int size();
};
