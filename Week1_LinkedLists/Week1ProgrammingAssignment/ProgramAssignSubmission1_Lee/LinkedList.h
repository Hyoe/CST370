/*---------------------------------------------------------------------
Programming Assignment 1 Submission
Linked Lists -- Asks a user to enter a text string and display the
number of substrings that start with A and end with B.
Created by Hyo Lee
Student ID: 002292770
01/12/2016
----------------------------------------------------------------------*/

//----- LinkedList.h -----
#ifndef LINKEDLIST
#define LINKEDLIST

#include <iostream>
using namespace std;

typedef char ElementType;



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

	void insertString(string userString);
	/*--------------------------------------------------------------------
	Inserts user string array input into linked list.
	--------------------------------------------------------------------*/

	int findABSubstring();
	/*--------------------------------------------------------------------
	Finds the substrings that start with 'A' and end with 'B' of string
	from insertString function.
	--------------------------------------------------------------------*/

	

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