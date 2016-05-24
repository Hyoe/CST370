/*---------------------------------------------------------------------
Programming Assignment 1 Submission
Linked Lists -- Asks a user to enter a text string and display the
				number of substrings that start with A and end with B.
Created by Hyo Lee
Student ID: 002292770
01/12/2016
----------------------------------------------------------------------*/

#include <iostream>
#include <string>

using namespace std;



#include "LinkedList.h"

//-- Default constructor
LinkedList::LinkedList()
{ 
	mySize = 0;
	first = NULL;
}


//-- Definition of the copy constructor
LinkedList::LinkedList(const LinkedList & origList)
{
	mySize = origList.mySize;
	first = NULL;
	
	if (mySize == 0) 
		return;

	Node * origPtr, * lastPtr;
	first = new Node(origList.first->data); // copy first node
	lastPtr = first;
	origPtr = origList.first->next;
	while (origPtr != NULL)
	{
		lastPtr->next = new Node(origPtr->data);
		origPtr = origPtr->next;
		lastPtr = lastPtr->next;
	}
}

/*
//-- Definition of the string constructor
LinkedList::LinkedList(string someString)
{

}
*/

//-- Definition of the destructor
LinkedList::~LinkedList()
{
	Node * prev = first;
	Node * ptr;

	while (prev != NULL)
	{
		ptr = prev->next;
		delete prev;
		prev = ptr;
	}
}


//-- Definition of insert()
void LinkedList::insert(ElementType dataVal, int index)
{
	if (index < 0 || index > mySize)
	{
		cerr << "Illegal location to insert -- " << index << endl;
		return;
	}

	mySize++;
	Node * newPtr = new Node(dataVal);
	Node * predPtr = first;
	if (index == 0)
	{
		newPtr->next = first;
		first = newPtr;
	}
	else
	{
		for(int i = 1; i < index; i++)
			predPtr = predPtr->next;
		newPtr->next = predPtr->next;
		predPtr->next = newPtr;
	}
}


//-- Definition of erase()
void LinkedList::erase(ElementType index)
{
	if (index < 0 || index >= mySize)
	{
		cerr << "Illegal location to delete -- " << index << endl;
		return;
	}

	mySize--;
	Node * ptr;
	Node * predPtr = first;
	if (index == 0)
	{
		ptr = first;
		first = ptr->next;
		delete ptr;
	}
	else
	{
		for(int i = 1; i < index; i++)
			predPtr = predPtr->next;
		ptr = predPtr->next;
		predPtr->next = ptr->next;
		delete ptr;
	}
}


//-- Definition of display()
void LinkedList::display(ostream & out) const
{
	Node * ptr = first;
	while (ptr != 0)
	{
		out << ptr->data << " ";
		ptr = ptr->next;
	}
}

//-- Definition of insertString()
void LinkedList::insertString(string userString)
{
	Node * ptr = new Node(userString[0]);
	first = ptr;
	ptr = first;
	Node * temp;

	for (size_t i = 1; i < userString.length(); i++)
	{
		temp = new Node(userString[i]);
		ptr->next = temp;
		ptr = ptr->next;
		mySize++;
	}
}


//-- Definition of findABSubString(string userString)
int LinkedList::findABSubstring()
{
	Node * aPtr = first;
	int counter = 0;

	while (aPtr != NULL)											// Traverse pointer for 'A'
	{
		Node * bPtr = aPtr->next;

		while (bPtr != NULL)										// Traverse pointer for 'B'
		{
			if (aPtr->data == 'A' && bPtr->data == 'B')				// Look for 'A' and 'B' chars.
			{
				Node * aSubstringPtr = aPtr;						// New 'A' pointer to create substring.
				Node * bSubstringPtr = bPtr->next;					// New 'B' pointer to create substring.
				counter++;
				cout << "\nSubstring " << counter << ": ";

				while (aSubstringPtr != bSubstringPtr)				// Traverse from pointer A to pointer B.
				{
					cout << aSubstringPtr->data;
					aSubstringPtr = aSubstringPtr->next;			// Move pointer over to next node.	
				}
			}
			bPtr = bPtr->next;										// Move 'B' pointer to next node.
		}
		aPtr = aPtr->next;											// Move 'A' pointer to next node.
	}
	cout << "\nTotal " << counter << " substrings" << endl;
	return counter;
}

