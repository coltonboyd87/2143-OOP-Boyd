/**
*  Course: CMPS 2143 - OOP
*
*  Purpose: To redefine operators in an vector array class, by overloading.
*  @author Colton Boyd
*  @version 1.1 09/30/18
   @github username: coltonboyd87
*/
#include <iostream>
#include "myVector.h"

using namespace std;

　


/********************************
*								                *
*		 Main	 			                *
*		Function			              *
*                               *
*                               *
********************************/
int main() {



	myVector v1(10);	//Create vector with size 10
	myVector v2(20);    //Create vector with size 20
  
  
	v1.push_Back(8);    // v1 contains: [8]


	

	v2.push_Back(10);
	v2.push_Back(20);   // v2 contains: [10,20,30]
	v2.push_Back(30);
	



	int A[] = { 1,2,3,4,5 };   // Declare some int array

	v1.push_Back(A, 5);   // v1 contains: [8,1,2,3,4,5]

  

	
	//Demonstration of addition operator 
	v1 = v1 + v2;     // v1 contains: [18,21,32,3,4,5]


	

	//Demonstration of cout operator 
	cout << v1 << endl;   // would print: [18,21,32,3,4,5] to standard out.

						  


	//Demonstration of [] operator 
	cout << v1[2] << endl;   // would print: 32 to standard out.

	

　
	//Demonstration of mult operator
	v2 = v2 * 3;   // v2 contains: [30,60,90]
	cout << v2 << endl; 



　
	//Demonstration of mult operator
	v2 = v2 * v1;   // v2 contains: [540,1260,2880,3,4,5]
	cout << v2 << endl; 


  
  
	//Demonstration of [] operator and assignment operator 
	v2[2] = 100;   // v2 contains: [540,1260,100,3,4,5]
	cout << v2 << endl; 



　
	//Demonstration of div operator
	v2 = v2 / v1;
	cout << v2 << endl;    //v2 contains {0,0,0,1,1,1}


  
	//Demonstration of equality operator
	if (v1 == v2){
		cout << "Vectors equal" << endl; 
	}
	else {
		cout << "Vectors Not equal" << endl; //Displays this
	}

　
	system("pause");
}
