#include <iostream>

using namespace std;


/********************************
*								                *
*		 Class	 			              *
*		Implementation		          *
*                               *
*                               *
********************************/
class myVector {
private:
	int *vPtr;      // int pointer to array
	int maxSize;    // max size of array
	int minSize;    // min size of array
	int index;      // current location to insert or remove
	int* _resize(int);

public:
	myVector(int size);
	void push_Back(int item);
	void push_Back(int *array, int size);
	int popBack();
	double percentFull();	//Public methods/variables
	int* resize(double);
	int* resize(int);

	void print();
	int size();
	void size(int);
	int vSize();

　
	// Implementation of [] operator.  This function must return a 
	// refernce as array element can be put on left side 
	int& operator[](int i)
	{
		if (i >= maxSize)
		{
			cout << "Array index out of bound, exiting\n";
			exit(0);
		}
		else if (i >= index) {
			cout << "Warning: vector[" << i << "] is undefined ...\n";
		}
		return vPtr[i];
	}


	// Implementation of << operator.  This function must return a 
	// ostream object called os by address. 
	friend ostream& operator<<(ostream& os, myVector V) {
		for (int i = 0; i<V.index; i++) {
			os << V.vPtr[i] << " ";
		}
		return os;
	}


	// Implementation of + operator.  This function must return a 
	// myVector called newVector.  
	myVector operator+(const myVector& rhs) {

		//rhs = vector on the right of the + sign
		//lhs = THIS vector (the one were in)
		int rhsSize = rhs.index;
		int lhsSize = index;
		int max = 0;
		int min = 0;

		// which vector is bigger?
		if (rhsSize > lhsSize) {
			max = rhsSize;
		}
		else {
			max = lhsSize;
		}

		// create a new vector with the bigger size
		myVector newVector(max);

		// which vector is smaller?
		if (rhsSize < lhsSize) {
			min = rhsSize;
			newVector.index = index;
		}
		else {
			min = lhsSize;
			newVector.index = rhs.index;
		}

		if (max == rhsSize) {
			for (int i = 0; i < max; i++) {
				newVector.vPtr[i] = rhs.vPtr[i];
			}
			for (int i = 0; i < min; i++) {
				newVector.vPtr[i] += vPtr[i];
			}
		}
		else {
			for (int i = 0; i < max; i++) {
				newVector.vPtr[i] = vPtr[i];
			}
			for (int i = 0; i < min; i++) {
				newVector.vPtr[i] += rhs.vPtr[i];
			}
		}

		return newVector;
	}


　
	// Implementation of - operator.  This function must return a 
	// myVector called newVector. 
	myVector operator-(const myVector& rhs) {

		//rhs = vector on the right of the - sign
		//lhs = THIS vector (the one were in)

		int rhsSize = rhs.index;
		int lhsSize = index;
		int max = 0;
		int min = 0;

		// which vector is bigger?
		if (rhsSize > lhsSize) {

			max = rhsSize;
		}
		else {
			max = lhsSize;
		}

		// create a new vector with the bigger size
		myVector newVector(max);

		// which vector is smaller?
		if (rhsSize < lhsSize) {
			min = rhsSize;
			newVector.index = index;
		}
		else {
			min = lhsSize;
			newVector.index = rhs.index;
		}

		if (max == rhsSize) {
			for (int i = 0; i < max; i++) {
				newVector.vPtr[i] = rhs.vPtr[i];
			}
			for (int i = 0; i < min; i++) {
				newVector.vPtr[i] -= vPtr[i];
			}
		}
		else {
			for (int i = 0; i < max; i++) {
				newVector.vPtr[i] = vPtr[i];
			}
			for (int i = 0; i < min; i++) {
				newVector.vPtr[i] -= rhs.vPtr[i];
			}
		}

		return newVector;
	}



	// Implementation of * operator.  This function must return a 
	//  myVector called newVector.
	myVector operator*(int num) {
		int lhsSize = index;
		int max = lhsSize;

		myVector newVector(max);
		newVector.index = index;

		for (int i = 0; i < max; i++) {
			newVector.vPtr[i] = vPtr[i];
		}
		for (int i = 0; i < max; i++) {
			newVector.vPtr[i] *= num;
		}
		return newVector;
	}



	// Implementation of * operator.  This function must return a 
	// myVector called newVector.
	myVector operator*(const myVector& rhs) {

		//rhs = vector on the right of the * sign
		//lhs = THIS vector (the one were in)
		int rhsSize = rhs.index;
		int lhsSize = index;
		int max = 0;
		int min = 0;


		// which vector is bigger?
		if (rhsSize > lhsSize) {
			max = rhsSize;
		}
		else {
			max = lhsSize;
		}

		// create a new vector with the bigger size
		myVector newVector(max);

		// which vector is smaller?
		if (rhsSize < lhsSize) {
			min = rhsSize;
			newVector.index = index;
		}
		else {
			min = lhsSize;
			newVector.index = rhs.index;
		}

		if (max == rhsSize) {
			for (int i = 0; i < max; i++) {
				newVector.vPtr[i] = rhs.vPtr[i];
			}
			for (int i = 0; i < min; i++) {
				newVector.vPtr[i] *= vPtr[i];
			}
		}
		else {
			for (int i = 0; i < max; i++) {
				newVector.vPtr[i] = vPtr[i];

			}
			for (int i = 0; i < min; i++) {
				newVector.vPtr[i] *= rhs.vPtr[i];
			}
		}
		return newVector;
	}



	// Implementation of / operator.  This function must return a 
	// myVector called newVector.
	myVector operator/(const myVector& rhs) {

		//rhs = vector on the right of the / sign
		//lhs = THIS vector (the one were in)
		int rhsSize = rhs.index;
		int lhsSize = index;
		int max = 0;
		int min = 0;


		// which vector is bigger?
		if (rhsSize > lhsSize) {
			max = rhsSize;
		}
		else {
			max = lhsSize;
		}

		// create a new vector with the bigger size
		myVector newVector(max);

		// which vector is smaller?
		if (rhsSize < lhsSize) {
			min = rhsSize;
			newVector.index = index;
		}
		else {
			min = lhsSize;
			newVector.index = rhs.index;
		}

		if (max == rhsSize) {
			for (int i = 0; i < max; i++) {
				newVector.vPtr[i] = rhs.vPtr[i];
			}
			for (int i = 0; i < min; i++) {
				newVector.vPtr[i] /= vPtr[i];
			}
		}
		else {
			for (int i = 0; i < max; i++) {
				newVector.vPtr[i] = vPtr[i];
			}
			for (int i = 0; i < min; i++) {
				newVector.vPtr[i] /= rhs.vPtr[i];
			}
		}
		return newVector;
	}


　
	// Implementation of = operator.  This function returns void.
	// But it assings new values in original vector passed in. 
	void operator=(const myVector& rhs) {

		index = rhs.index;

		for (int i = 0; i < index; i++) {
			vPtr[i] = rhs.vPtr[i];
		}
	}


　
	// Implementation of == operator.  This function returns bool.
	// But it checks for equality of values in 2 vectors.
	bool operator==(const myVector& rhs) {
		if (index != rhs.index) {
			return false;
		}

		for (int i = 0; i < index; i++) {
			if (vPtr[i] != rhs.vPtr[i]) {
				return false;
			}
		}

		return true;
	}
};



