/*---------------------------------------------------------------------------
Lab 3 Submission
Queues -- This program displays the extracted footnotes between the { and }
			delimiters in a text file
Created by Hyo Lee
Student ID: 002292770
01/26/2016
----------------------------------------------------------------------------*/

/*---------------------------------------------------------------------
                  Driver program to test the Queue class.
  ----------------------------------------------------------------------*/

#include <iostream>
#include <string>
#include <fstream>

using namespace std;
	
#include "Queue.h"

int main()
{
	Queue q;
	string line;
	string footString;
	string displayLine;
	bool footer = false;

	ifstream myFile("lab3.txt");

	if (myFile.is_open())
	{
		while (getline(myFile, line))						// Store file contents as one line.
		{
			for (size_t i = 0; i < line.length(); i++)		// Loop through each character in line.
			{
				if (line[i] == '{')							// Find each open delimiter.
				{
					footer = true;							// Start of footnote.
				}
				else if (line[i] == '}')					// Find each closed delimiter.
				{
					q.enqueue(footString);					// End of footnote.
					footString = "";						// Store in queue.
					footer = false;
				}
				else
				{
					if (footer)
					{
						footString += line[i];				// Create footnote string.
					}
				}
			}
		}
		cout << "*** Raw footnotes ***\n";
		q.display(cout);

		cout << "\n*** Formatted footnotes ***" << endl;
		while (!q.empty())
		{
			cout << q.front();
			q.dequeue();
			cout << endl;
		}
	}
	else
	{
		cout << "Unable to open file." << endl;
	}	

	return 0;
}
