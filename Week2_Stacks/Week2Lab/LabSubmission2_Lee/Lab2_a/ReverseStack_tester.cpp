/*---------------------------------------------------------------------
Lab 2 (a) Submission
Stacks -- Read a string from user input and reverse the sequence
of characters using stacks.
Created by Hyo Lee
Student ID: 002292770
01/19/2016
----------------------------------------------------------------------*/


/*---------------------------------------------------------------------
               Driver program to test reverse push / pop function
			   using the Stack class.
  ----------------------------------------------------------------------*/

#include <iostream>
#include <string>

using namespace std;

#include "Stack.h"


Stack s;								// Global variable to create empty stack.

// Reverse function
void pushRev(char *userString, int n)
{
	for (int i = 0; i < n; i++)			// Loop through length of string.
	{
		s.push(userString[i]);			// Push each char element onto stack.
	}

	for (int i = 0; i < n; i++)			// Loop through array.
	{
		userString[i] = s.top();		// Set top of stack.
		s.pop();						// Pop each element from the stack.
	}
}


int main()
{
	cout << "Enter a string => ";
	char userString[STACK_CAPACITY];
	cin.getline(userString, strlen(userString));
	cout << "You entered " << userString << endl;
	cout << "Reverse is ";
	pushRev(userString, strlen(userString));
	cout << userString << endl;

	return 0;

}