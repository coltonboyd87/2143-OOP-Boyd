/**


*  Course: CMPS 2143 - OOP


*  Assignment: A02


*  Purpose: Learn to comment effectively.


*


*  @author Colton Boyd 


*  @version 1.1 9/5/18


*/


#include <iostream>



using namespace std;



int A[100];



//Struct Implmentation


struct Node


{


	int x;


	Node *next;


	Node()


	{


		x = -1;


		next = NULL;


	}


	Node(int n)


	{


		x = n;


		next = NULL;


	}


};


//Class Implementation


class List


{


private:


	Node *Head;


	Node *Tail;


	int Size;



public:


	List()


	{


		Head = Tail = NULL;


		Size = 0;


	}



	/**


	*   Pushes new int and creates new node


	*


	*   @param {int} val : val being inputted to node 


	*   @return {void} : nothing 


	*/



	void Push(int val)


	{


		// allocate new memory and init node


		Node *Temp = new Node(val);



		if (!Head && !Tail)


		{


			Head = Tail = Temp;


		}


		else


		{


			Tail->next = Temp;


			Tail = Temp;


		}


		Size++;


	}



	/**


	*   Pushes new int and creates new node from the back


	*


	*   @param {int} val : val being inputted to node from back


	*   @return {void} : nothing


	*/


	void Insert(int val)


	{


		// allocate new memory and init node


		Node *Temp = new Node(val);



		// figure out where it goes in the list



		Temp->next = Head;


		Head = Temp;


		if (!Tail)


		{


			Tail = Head;


		}


		Size++;


	}


	/**


	*   prints tail pointer 


	*


	*   @param {} 


	*   @return {void} : nothing


	*/


	void PrintTail()


	{


		cout << Tail->x << endl;


	}



　


	/**


	*   Converts val to string and prints the number.


	*


	*   @param 


	*   @return {string} : val converted to string 


	*/


	string Print()


	{


		Node *Temp = Head;


		string list;



		while (Temp != NULL)


		{


			list += to_string(Temp->x) + "->";


			Temp = Temp->next;


		}



		return list;


	}



	// not implemented 


	int Pop()


	{


		Size--;


		return 0; //


	}



	List operator+(const List &Rhs)


	{


		// Create a new list that will contain both when done


		List NewList;



		// Get a reference to beginning of local list


		Node *Temp = Head;



		// Loop through local list and Push values onto new list


		while (Temp != NULL)


		{


			NewList.Push(Temp->x);


			Temp = Temp->next;


		}



		// Get a reference to head of Rhs


		Temp = Rhs.Head;



		// Same as above, loop and push


		while (Temp != NULL)


		{


			NewList.Push(Temp->x);


			Temp = Temp->next;


		}



		// Return new concatenated version of lists


		return NewList;


	}



	// Implementation of [] operator.  This function returns an


	// int value as if the list were an array.


	int operator[](int index)


	{


		Node *Temp = Head;



		if (index >= Size)


		{


			cout << "Index out of bounds, exiting";


			exit(0);


		}


		else


		{



			for (int i = 0; i < index; i++)


			{


				Temp = Temp->next;


			}


			return Temp->x;


		}


	}



	friend ostream &operator<<(ostream &os, List L)


	{


		os << L.Print();


		return os;


	}


};



//Main Function 


int main(int argc, char **argv)


{


	List L1;


	List L2;



	for (int i = 0; i < 25; i++)


	{


		L1.Push(i);


	}



	for (int i = 50; i < 100; i++)


	{


		L2.Push(i);


	}



	//cout << L1 << endl;


	L1.PrintTail();


	L2.PrintTail();



	List L3 = L1 + L2;


	cout << L3 << endl;



	cout << L3[5] << endl;


	return 0;


}
