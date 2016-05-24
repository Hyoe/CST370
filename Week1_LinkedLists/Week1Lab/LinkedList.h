/*------------------------------------------------------------------
Lab 1 Submission
Linked Lists -- Find max element and if list is in ascending order
Created by Hyo Lee
Student ID: 002292770
01/12/2016
-------------------------------------------------------------------*/

//----- LinkedList.h -----
#ifndef LINKEDLIST
#define LINKEDLIST

#include <iostream>
using namespace std;

typedef int ElementType;

class LinkedList
{ 
public:
	LinkedList();   // constructor
	~LinkedList();  // destructor
	LinkedList(const LinkedList & original); //copy constructor
	void insert(ElementType item, int pos);
	void erase(ElementType item);

	void display(ostream & out) const;
	/*--------------------------------------------------------------------
	Display the contensts of this LinkedList.
	Precondition: ostream out is open
	Postcondition: Elements of this LinkedList have been output to out.
	--------------------------------------------------------------------*/

	ElementType maxItem();
	/*-------------------------------------------------------------
	Determines the maximum value among the elements in the list.
	-------------------------------------------------------------*/

	bool isAscendingOrder();
	/*----------------------------------------------------------------
	Checks if all elements in the list are in ascending order or not.
	-----------------------------------------------------------------*/

private:
	class Node
	{
	public:
		ElementType data;
		Node * next;
		//------ Node OPERATIONS
		//-- Default constrctor: initializes next member to
		Node()
			: next(NULL)
		{ }
		//-- Explicit-value constructor: initializes data member to dataValue
		//-- and next member to 0
		Node(ElementType dataValue)
			: data(dataValue), next(NULL)
		{ }
	};
	Node * first;
	int mySize;
};

#endif