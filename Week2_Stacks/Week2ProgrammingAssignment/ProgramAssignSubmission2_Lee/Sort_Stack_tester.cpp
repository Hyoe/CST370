/*---------------------------------------------------------------------
Programming Assignment 2 Submission
Stacks -- Use two stacks to display numbers in descending order
		  by sorting the numbers from stack 1 into stack 2 in
		  ascending order.
Created by Hyo Lee
Student ID: 002292770
01/19/2016
----------------------------------------------------------------------*/


/*---------------------------------------------------------------------
               Driver program to test the sort ascending from stack 1
			   to stack 2 program using the Stack class.
  ----------------------------------------------------------------------*/

#include <iostream>
using namespace std;

#include "Stack.h"

// Global variables to create empty stacks.
Stack s1;
Stack s2;

// Function to hold sort algorithm.
void sortAscendStacks(const Stack & stack)
{
	StackElement temp;

	// First loop for stack 1.
	while (!s1.empty())
	{
		temp = s1.top();							// Store top value in temp variable.
		s1.pop();									// Pop off top element from stack 1.

		// Second inner loop for stack 2.
		while (!s2.empty() && s2.top() > temp)
		{
			s1.push(s2.top());						// Push top element from stack 2 to stack 1.
			s2.pop();								// Pop off top element from stack 2.
		}
		s2.push(temp);								// Push temp value to top of stack 2.
	}

	if (!s2.empty())
	{
		cout << s2.top();							// Print out first value (work around so no comma after last value).
		s2.pop();									// Pop off top element in stack 2.

		// Loop through stack 2
		while (!s2.empty())
		{
			cout << ", " << s2.top();				// Print out comma in front and the values in stack 2.
			s2.pop();								// Pop off top element in stack 2.
		}
	}
	cout << endl;
}


int main()
{
	// Listed all sample inputs at once for easier testing.
	// Comment out or delete two sample inputs to view just one sample test at a time.

	{
		// Sample input 1
		s1.push(1);
		s1.push(5);
		s1.push(3);
		s1.push(-3);
		s1.push(4);
		s1.push(8);
		s1.push(10);
		s1.push(-5);
		cout << "Sample output 1\n";
		sortAscendStacks(s1);
		cout << endl;
	}

	{
		// Sample input 2
		s1.push(1);
		s1.push(5);
		s1.push(-4);
		s1.push(6);
		s1.push(2);
		cout << "Sample output 2\n";
		sortAscendStacks(s1);
		cout << endl;
	}
	
	{
		// Sample input 3
		s1.push(-1);
		s1.push(-4);
		s1.push(-4);
		s1.push(6);
		s1.push(6);
		s1.push(9);
		cout << "Sample output 3\n";
		sortAscendStacks(s1);
		cout << endl;
	}

	return 0;

}
