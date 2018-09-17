/**
*  Course: CMPS 2143 - OOP
*
*  Purpose: To immilate a vector using an array container, by pushing back and popping back values,
*  and growing and shrinking the array to accomadate for empty space in the array. 
*  @author Colton Boyd 
*  @version 1.1 09/13/18
*/

#include <iostream>
#include "myVector.h" //myVector header file

using namespace std;

/********************************
*								                *								  
*		 Main	 			                *									  
*		Function			              *			
*                               *
*                               *
********************************/
int main() {

	int val;	// int variable to hold our popped values
	myVector test; //Instance of our myVector class to Test values.

	val = test.pop_back();
	cout << val << endl;

	test.push_back(13);
	test.push_back(31);	//Test data 
	test.push_back(73);

	test.print();	//Print Test Data

	cout << endl;

	for (int i = 0; i < 1000; i++) {	//Push 1000 items on vector
		test.push_back(rand());
	}

	cout << test.size() << endl;	//Print the size of vector 

	for (int i = 0; i < 998; i++) {
		val = test.pop_back();		//Pop off 998 items from vector 
	}

	cout << test.size() << endl;	//Print the size of the vector 

	test.print();	//Print Test Data
	cout << endl;
	system("pause");
}
