/*------------------------------------------------------------------------------------
Lab 6 Submission
Searching - Search for user input number using Linear search and Iterative and Binary
			search functions.
Created by Hyo Lee
Student ID: 002292770
02/16/2016
-------------------------------------------------------------------------------------*/


#include <iostream>
#include <limits>
#include <string>
#include <sstream>
#include <regex>
using namespace std;


/*---------- Declarations ----------*/
bool LinearSearch(int [], int, int);
// Linear search for an integer.
// @Param int [] - input array A.
// @Param int - size of array A.
// @Param int - user input search number.

bool IterBinarySearch(int[], int, int);
// Iterative Binary Search for an integer.
// @Param int [] - input array B.
// @Param int - size of array B.
// @Param int - user input search number.

bool RecursiveBinarySearch(int[], int, int, int);
// Recursive Binary Search for an integer.
// @Param int [] - input array B.
// @Param int - start of search.
// @Param int - end of search.
// @Param int - user input search number.



int main()
{
	int userInput1 = 0;
	int userInput2 = 0;
	int userInput3 = 0;
	string strInput = "";
	bool isValid = false;
	cout << boolalpha;
	regex integer("-?[[:digit:]]+");

	/*----------------- Linear search test ---------------*/
	int A[] = { 4, 2, 10, 13, 2, 5, 6, 1, 0, -3 };					// Initialize array A.
	int nA = sizeof(A) / sizeof(A[0]);								// Get size of array A.

	do
	{
		cout << "Enter an integer for Linear Search: ";
		getline(cin, strInput);
		stringstream myStream(strInput);

		if (regex_match(strInput, integer))							// Validate input for only integers and digits.
		{
			myStream >> userInput1;
			isValid = true;
		}
		else
		{
			isValid = false;
		}
		if (!isValid)
		{
			cerr << "Invalid entry" << endl;
		}
		else
		{
			cout << LinearSearch(A, nA, userInput1) << endl;		// Linear Search function call.
		}
	} while (!isValid);
	/*-----------------------------------------------------*/

	/*--------------- Iterative Binary Search Test --------------*/
	int B[] = { 2, 4, 5, 7, 13, 14, 15, 23 };						// Initialize array B.
	int nB = sizeof(B) / sizeof(B[0]);								// Get size of array B.

	do
	{
		cout << "Enter an integer for Iterative Binary Search: ";
		getline(cin, strInput);
		stringstream myStream(strInput);

		if (regex_match(strInput, integer))							// Validate input for only integers and digits.
		{
			myStream >> userInput2;
			isValid = true;
		}
		else
		{
			isValid = false;
		}
		if (!isValid)
		{
			cerr << "Invalid entry" << endl;
		}
		else
		{
			cout << IterBinarySearch(B, nB, userInput2) << endl;	// Iterative Binary Search function call.
		}
	} while (!isValid);
	/*------------------------------------------------------------*/

	/*----------------- Recusive Binary Search Test ------------------*/
	// Test uses same array B above.
	do
	{
		cout << "Enter an integer for Recursive Binary Search: ";
		getline(cin, strInput);
		stringstream myStream(strInput);

		if (regex_match(strInput, integer))									// Validate input for only integers and digits.
		{
			myStream >> userInput3;
			isValid = true;
		}
		else
		{
			isValid = false;
		}
		if (!isValid)
		{
			cerr << "Invalid entry" << endl;
		}
		else
		{
			cout << RecursiveBinarySearch(B, 0, nB, userInput3) << endl;	// Recursive Binary Search function call.
		}
	} while (!isValid);
	/*------------------------------------------------------------------*/
}	// end main


/*--------------- Definitions --------------*/
// Linear Search function
bool LinearSearch(int A [], int n, int x)
{
	for (int i = 0; i < n; i++)
	{
		if (A[i] == x)
		{
			return true;						// Found x, return true (exit).
		}
	}
	return false;								// x not found, return false.
}

// Iterative Binary Search function
bool IterBinarySearch(int A[], int n, int x)
{
	int low = 0;
	int high = n - 1;
	
	while (low <= high)
	{
		int mid = low + (high - low) / 2;		// (low + high)/2  may overflow.
		if (x == A[mid])
		{
			return true;						// Found x, return true (exit).
		}
		else if (x < A[mid])
		{
			high = mid - 1;						// x lies before mid.
		}
		else
		{
			low = mid + 1;						// x lies after mid.
		}
	}
	return false;
}

// Recursive Binary Search function
bool RecursiveBinarySearch(int A [], int low, int high, int x)
{
	if (low > high)												// Base Condition, x not found exit.
	{
		return false;
	}

	int mid = low + (high - low) / 2;							// (low + high)/2  may oferflow.
	if (x == A[mid])											// Base Condition, x found at mid, exit.
	{
		return true;
	}
	else if (x < A[mid])
	{
		return RecursiveBinarySearch(A, low, mid - 1, x);		// Recursive call, x lies before mid.
	}
	else
	{
		return RecursiveBinarySearch(A, mid + 1, high, x);		// Recursive call, x lies after mid.
	}
}
