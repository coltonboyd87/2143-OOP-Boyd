#include <iostream>
#include "myVector.h"

using namespace std;

/*
*   Default constructor initilizes size of vector to 10.
*
*   @param {none}: no argument. 
*   @return {none}:doesnt return anything. 
*/
myVector::myVector() {
	theVector = new int[10];
	vSize = 10;
	minSize = 10;
	index = -1;
	for (int i = 0; i<10; i++) {
		theVector[i] = 0;
	}
}



/**
*   Customized constructor where user can input their own size of vector to start with. 
*
*   @param {int} size : size of vector user wants to start with. 
*   @return {none} : doesnt return anything. 
*/
myVector::myVector(int size) {
	vSize = size;
	minSize = vSize;
	index = -1;		//Sets index of array to -1 so we can check for empty vector later.

	theVector = new int[vSize];
	for (int i = 0; i<vSize; i++) {
		theVector[i] = 0;	//Fills vector with 0's until items are pushed on. 
	}
}



/**
*   Method Name: pop_back
*   Method that pops int off int vector, if percent full gets to 0.4 or 
*   below then the vector shrinks by shrink method. 
*   @param {none}: doesnt pass anything in. 
*   @return {int} : int popped off vector. 
*/
int myVector::pop_back() {
	int tempVal;

	if (index == -1) {	//Check for empty vector. 
		return 0;
	}
	else {
		tempVal = theVector[index];
		index--;
	}

	double tempPer = percentFull();
	if (tempPer <= 0.4 && vSize > minSize) {
		shrinkArr();	//shrink method. 
	}
	else{}

	return tempVal;
}



/**
*   Method Name: push_back 
*   Method that pushes int onto the back  of the vector. Think of 
*   grocery line. (Queue). Includes a grow method that resizes 
*   the vector by 1.5 whenever it reaches full capacity. 
*   @param {int} val : int being pushed onto vector. 
*   @return {void} : doesn't return anything. 
*/
void myVector::push_back(int val) {
	double tempPer = percentFull();
	if (tempPer == 1.0) {
		growArr();	//Grow method. 
	}

	index++;
	theVector[index] = val;

}



/**
*   Method Name: percentFull 
*	Keeps track of how full the vector is. 
*
*   @param {none}: doesnt pass in anything.
*   @return {double} : percent : the percent full of vector. 
*/
double myVector::percentFull() {
	double percent, dIndex;

	dIndex = index + 1;
	percent = dIndex / vSize;
	return percent;
}



/**
*   Method Name:growArr
*	Method called in push_back method in case the vector is full. 
*
*   @param {none} : doesnt pass in anything.
*   @return {void} : doesnt return naything. 
*/
void myVector::growArr() {
	int newSize;

	newSize = vSize * 1.5;	//resize vector by 1.5

	int *tempVector = new int[newSize];

	for (int i = 0; i<newSize; i++) {
		tempVector[i] = 0;
	}
  
	for (int i = 0; i<vSize; i++) {
		tempVector[i] = theVector[i];
	}

	delete theVector;
	vSize = newSize;
	theVector = tempVector;
}



/**
*   Method Name: shrinkArr
*   Method called in pop_back to shrink vector down so there's not unused space. 
*
*   @param {none}: doesnt pass in anything.
*   @return {void}: doesnt return anything. 
*/
void myVector::shrinkArr() {

	int newSize;
	int truncSize;

	truncSize = vSize / 3;	//Shrink vector by a 1/3.
	newSize = vSize - truncSize;	//Vector size cannot go underneath starting size. 

	int *tempVector = new int[newSize];

	for (int i = 0; i<newSize; i++) {
		tempVector[i] = theVector[i];
	}
	delete theVector;

	vSize = newSize;
	theVector = tempVector;
}



/**
*   Method Name:print
*   Prints the elements of the current vector.
*
*   @param {none}: doesn't pass in anything.
*   @return {void}: doesn't return anything. 
*/
void myVector::print() {
	for (int i = 0; i<vSize; i++) {
		cout << theVector[i] << " ";
	}
}



/**
*   Method Name: size
*   Prints the current size of the vector.
*
*   @param {none}: doesnt pass in anything.
*   @return {int} Vsize: the current size of the vector. 
*/
int myVector::size() {
	return vSize;
}
