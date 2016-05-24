/*---------------------------------------------------------------------
Programming Assignment 1 Submission
Linked Lists -- Asks a user to enter a text string and display the
number of substrings that start with A and end with B.
Created by Hyo Lee
Student ID: 002292770
01/12/2016
----------------------------------------------------------------------*/

#include <iostream>
using namespace std;

#include <iostream>
#include <string>


#include "LinkedList.h"

int main()
{
	/*
   // Test the class constructor
   LinkedList intList;
   cout << "Constructing intList\n";

   // Test insert()
   intList.insert(100, 0);
   intList.display(cout);
   cout << endl;

   intList.insert(200, 0);
   intList.display(cout);
   cout << endl;
   
   intList.insert(300, 1);
   intList.display(cout);
   cout << endl;
   
   intList.insert(400, 1);
   intList.display(cout);
   cout << endl;
   
   intList.insert(500, 3);
   intList.display(cout);
   cout << endl;

   // Test destructor
   {
      LinkedList anotherList;
      for (int i = 0; i < 10; i++)
      {
	anotherList.insert(100*i, i);
      }
      cout << "\nThis is another list\n";
      anotherList.display(cout);
   }

   // Test erase
   intList.erase(1);
   intList.erase(1);
   cout << "\n\nTwo items are erased from the first list\n";
   intList.display(cout);
   cout << endl;
   
   */


   {
	LinkedList stringList;

	string userString;
	cout << "Enter a string: ";
	cin >> userString;
	stringList.insertString(userString);
	stringList.findABSubstring();
   }

}