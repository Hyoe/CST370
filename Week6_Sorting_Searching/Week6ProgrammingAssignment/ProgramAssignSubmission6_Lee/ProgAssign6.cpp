/*------------------------------------------------------------------------------------
Programming Assignment 6 Submission
Sorting Algorithm 2 - The CoolSort function sorts an array in ascending order
					  at time complexity O(n^3/2) by sorting at varying step sizes.
Created by Hyo Lee
Student ID: 002292770
02/16/2016
-------------------------------------------------------------------------------------*/


#include <iostream>

using namespace std;

void CoolSort(int[], int, int[], int);
// Sorts an array at H[] sequence (on each step size).
// @Param int[] - Input array A.
// @Param int - Length of input array A.
// @Param int - Input sequence array H.
// @Param int - Length of input array H.


int main()
{
	// Initialize input array A.
	int A[] = { 2, 5, 9, 4, 10, 7, 8, 1, 11, 5 };
	int ALength = sizeof(A) / sizeof(A[0]);									// Length of input array A.
	
	// Initialize sequence array H (H[] can be changed to test e.g. {5} or {5, 3}, etc).
	int H[] = { 5 };
	int HLength = sizeof(H) / sizeof(H[0]);									// Length of sequence array H.

	bool validStepSize = false;

	for (int i = 0; i < HLength; i++)
	{
		if (H[i] > ALength)													// Validate size of each step in H array.
		{
			cout << "Step size cannot exceed " << ALength << endl;
			validStepSize = false;
			break;
		}
		else
		{
			validStepSize = true;
		}
	}
	if (validStepSize)
	{
		CoolSort(A, ALength, H, HLength);									// Call CoolSort() function.

		for (int i = 0; i < ALength; i++)									// Print out sorted array to H sequence.
		{
			cout << A[i] << " ";
		}
		cout << endl;
	}
}


// Definition of CoolSort
void CoolSort(int A[], int ALength, int H[], int HLength)
{
	for (int h = 0; h < HLength; h++)								// Iterate through H sequence array.
	{
		int stepSize = H[h];										// Set each step size from H as stepSize.

		for (int i = stepSize; i < ALength; i++)					// Start from first step size to entire length of input array.
		{
			int temp = A[i];
			int j = i;

			while (j >= stepSize && A[j - stepSize] > temp)			// Swap condition.
			{
				A[j] = A[j - stepSize];								// Value at current j position set to previous j value.
				j -= stepSize;										// Decrement back one step.
			}
			A[j] = temp;											// Value at previous j position set to temp (swap complete).
		}
	}
}
