/*------------------------------------------------------------------------------------
Programming Assignment 5 Submission
Sorting Algorithms - Sort arrays in ascending order using Selection Sort at O(n^2)
					 and O(kn) time complexities and finding the median value
					 using k index. 
Created by Hyo Lee
Student ID: 002292770
02/09/2016
-------------------------------------------------------------------------------------*/


#include <iostream>
#include <string>
#include <sstream>

using namespace std;

/*----------------------------
	Function Declarations
-----------------------------*/
void SelectionSort(double [], int);
// Sorts an array to n int
// @Param double [] - input array A 
// @Param int - size of array A

void SelectionSortToK(double [], int, int);
// Sorts an array to k int
// @Param double [] - input array B
// @Param int - size of array B
// @Param int - k position of array B

double findMedian(double [], int, int);
// Finds the median value
// @Param double [] - input array B
// @Param int - size of array B
// @Param int - k position of array B = size of array / 2
// @Return - median value


int main()
{
	// Sort to n-1, O(n^2)
	double A[] = { 4, 6, 8, 15, 20, 22, 10, 3, 9, 2 };		// Input array for full O(n^2) sort.
	int n1 = sizeof(A)/sizeof(A[0]);						// Store size of array.
	
	SelectionSort(A, n1);									// Sort function call.
	cout << "Sort to n-1, O(n^2): ";
	for (int i = 0; i < n1; i++)							// Loop through and print values.
	{
		cout << A[i] << " ";
	}
	cout << endl;

	
	// Sort to k value, O(kn)
	double B[] = { 4, 6, 8, 15, 20, 22, 10, 3, 9, 2 };		// Input array for full O(kn) sort.
	int n = sizeof(B) / sizeof(B[0]);						// Store size of array.
	int k = 0;
	string input;
	char response;

	do
	{
		bool isNumber = false;
		cout << "Enter a positive integer less than or equal to " << n << ": ";
		getline(cin, input);
		stringstream inputStream(input);

		for (size_t i = 0; i < input.length(); i++)
		{
			if (isdigit(input[i]))								// Check if input is a number.
			{
				isNumber = true;
				inputStream >> k;
			}
			else
			{
				isNumber = false;
			}
		}
		if (k == 0 || k < 0 || k > n || !isNumber)				// Validate number input.			
		{
			cerr << "*** Invalid Input. ***" << endl;
		}
		else
		{
			SelectionSortToK(B, n, k);							// Sort to k function call.
			cout << "Sort to k value, O(kn): ";
			for (int i = 0; i < k; i++)							// Loop through and print values.
			{
				cout << B[i] << " ";
			}
			cout << endl;

			// Find Median of starting array
			cout << "Median value of starting Array: ";
			k = n / 2;											// Middle point.
			SelectionSortToK(B, n, k + 1);						// Sort to k function call (k + 1) for even set.
			cout << findMedian(B, n, k) << endl;
		}

		cout << "More? (Y or N): ";
		getline(cin, input);
		if (input.length() == 1)
		{
			response = input[0];
		}
	}
	while (response == 'y' || response == 'Y');

	return 0;
}	// end main()


/*------------------------------------------------------------------------
	Definitions
--------------------------------------------------------------------------*/

// Definition of SelectionSort(), O(n^2)
void SelectionSort(double A [], int n)
{
	for (int i = 0; i < n - 1; i++)			// Last element will be correctly positioned after n-1.
	{
		int iMin = i;						// ith position: elements from i till n-1 are candidates.

		for (int j = i + 1; j < n; j++)
		{
			if (A[j] < A[iMin])
			{
				iMin = j;					// Update the index of minimum element.
			}
		}
		double temp = A[i];					// Swap.
		A[i] = A[iMin];
		A[iMin] = temp;
	}
}

// Definition of SelectionSortAtk(), O(kn)
void SelectionSortToK(double A[], int n, int k)
{
	for (int i = 0; i < k; i++)				// Stop sort at k.
	{
		int iMin = i;						// ith position: elements from i till k are candidates.

		for (int j = i + 1; j < n; j++)
		{
			if (A[j] < A[iMin])
			{
				iMin = j;					// Update the index of minimum element.
			}
		}
		double temp = A[i];					// Swap.
		A[i] = A[iMin];
		A[iMin] = temp;
	}
}

// Definition of findMedian()
double findMedian(double A [], int n, int k)
{
	if (n % 2 == 0)							// Even sets.
	{
		return (A[k] + A[(k) - 1]) / 2;
	}
	else
	{
		return A[k];						// Odd sets.
	}
}



