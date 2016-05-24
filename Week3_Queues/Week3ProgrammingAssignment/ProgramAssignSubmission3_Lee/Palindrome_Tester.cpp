/*------------------------------------------------------------------
Programming Assigment 3 Submission
Queues -- Use a Queue and Stack to test if a string is a Palindrome.
Created by Hyo Lee
Student ID: 002292770
01/26/2016
-------------------------------------------------------------------*/

/*---------------------------------------------------------------------
                  Driver program to test the Palindrome.
  ----------------------------------------------------------------------*/

#include <iostream>
#include <string>
using namespace std;
	
#include "Queue.h"
#include "Stack.h"

int main()
{
	char inputChar[STACK_CAPACITY];
	string userString;
	bool palindrome = true;
	Stack s;
	Queue q;
	char stackChar;
	char queueChar;

	cout << "Enter a string: ";
	getline(cin, userString);

	if (userString.empty())										// No input condition.
	{
		cout << "No string entered." << endl;
	}
	else
	{
		cout << "You entered: " << userString;
		for (size_t i = 0; i < userString.length(); i++)
		{
			inputChar[i] = userString[i];
			if (isalnum(inputChar[i]))							// Only check alphabet letters and numbers.
			{
				inputChar[i] = tolower(inputChar[i]);			// Ignore case (upper and lower).
				s.push(inputChar[i]);							// Insert char into stack.
				q.enqueue(inputChar[i]);						// Insert char into queue.
			}
		}

		while (palindrome && !q.empty())						// Compare each stack char to queue char.
		{
			stackChar = s.top();
			s.pop();											// Stack coming out in reverse order (LIFO).

			queueChar = q.front();
			q.dequeue();										// Queue coming out in line order (FIFO).

			if (stackChar != queueChar)
			{
				palindrome = false;
			}
		}

		if (palindrome)
		{
			cout << "\n*** Your string is a palindrome! ***" << endl;
		}
		else
		{
			cout << "\n*** Sorry, your string is NOT a palindrome. ***" << endl;
		}
	}

	return 0;
}
