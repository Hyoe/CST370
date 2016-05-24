/*---------------------------------------------------------------------
Lab 2 (b) Submission
Stacks -- Covert a positive integer to a binary representation.
Created by Hyo Lee
Student ID: 002292770
01/19/2016
----------------------------------------------------------------------*/


/*---------------------------------------------------------------------
               Driver program to test decimal to binary conversion
			   using the Stack class.
  ----------------------------------------------------------------------*/

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

#include "Stack.h"

// Decimal to binary conversion function
StackElement decimalToBinary()
{
	Stack stackOfRemainders;
	int number, remainder;
	string mystr;

	// Check for char and positive number.
	do
	{
		cout << "Enter a positive number: ";
		getline(cin, mystr);
		stringstream(mystr) >> number;
	}
	while (number < 0);

	// Valid input is entered.
	if (number >= 0)
	{
		cout << "Decimal: " << number << endl;
		if (number == 0)						// Automatically return 0 for 0 number.
		{
			cout << "Binary: 0\n";
			return 0;
		}
		while (number != 0)						// Find binary number
		{
			remainder = number % 2;				// Get each remainder from modulo 2 (0 or 1).
			number = number / 2;				// Get the whole number after division of 2.
			stackOfRemainders.push(remainder);	// Push each remainder on the stack.
		}
		cout << "Binary: ";

		// Display remainders as binary number by popping each top remainder off the stack
		while (!stackOfRemainders.empty())
		{
			remainder = stackOfRemainders.top();
			stackOfRemainders.pop();
			cout << remainder;
		}
		cout << endl;
	}
	else
	{
		cout << "Invalid value\n";
	}
	return 0;
}


int main()
{
	decimalToBinary();

	return 0;
}



