/*------------------------------------------------------------------
Lab 1 Submission
Linked Lists -- Find max element and if list is in ascending order
Created by Hyo Lee
Student ID: 002292770
01/12/2016
-------------------------------------------------------------------*/

#include <iostream>
using namespace std;

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


   // Test maxItem() with empty list
   {
	   LinkedList maxValueList;

	   cout << "\nNew list to test maxItem() with empty list\n";
	   maxValueList.display(cout);
	   cout << "\nMax Value: " << maxValueList.maxItem() << endl;
   }


   // Test maxItem() with one element
   {
	   LinkedList maxValueList;

	   maxValueList.insert(100, 0);

	   cout << "\nNew list to test maxItem() with one element\n";
	   maxValueList.display(cout);
	   cout << "\nMax Value: " << maxValueList.maxItem() << endl;
   }


   // Test maxItem() with many elements
   {
	   LinkedList maxValueList;

	   maxValueList.insert(100, 0);
	   maxValueList.insert(800, 1);
	   maxValueList.insert(900, 2);
	   maxValueList.insert(700, 3);
	   maxValueList.insert(920, 2);
	   maxValueList.insert(150, 4);

	   cout << "\nNew list to test maxItem() with many elements\n";
	   maxValueList.display(cout);
	   cout << "\nMax Value: " << maxValueList.maxItem() << endl;
   }


   // Test isAscendingOrder() with an ascending list.
   // Should return true.
   {
	   LinkedList ascendingList;
	   for (int i = 0; i < 10; i++)
	   {
		   ascendingList.insert(100 * i, i);
	   }
	   cout << "\nNew list to test isAscendingOrder() on a list in ascending order\n";
	   ascendingList.display(cout);
	   cout << "\nIs list in ascending order? " << ascendingList.isAscendingOrder() << endl;
   }


   // Test isAscendingOrder() with an ascending list.
   // Should return false.
   {
	   LinkedList ascendingList;

	   ascendingList.insert(100, 0);
	   ascendingList.insert(800, 1);
	   ascendingList.insert(900, 2);
	   ascendingList.insert(700, 3);
	   ascendingList.insert(920, 2);
	   ascendingList.insert(150, 4);

	   cout << "\nNew list to test isAscendingOrder() on a list not in ascending order\n";
	   ascendingList.display(cout);
	   cout << "\nIs list in ascending order? " << ascendingList.isAscendingOrder() << endl;
   }


   // Test isAscendingOrder() with empty list.
   // Should return true.
   {
   LinkedList ascendingList;

   cout << "\nNew list to test isAscendingOrder() on an empty list\n";
   ascendingList.display(cout);
   cout << "\nIs list in ascending order? " << ascendingList.isAscendingOrder() << endl;
   }


   // Test isAscendingOrder() with one element.
   // Should return true.
   {
	   LinkedList ascendingList;

	   ascendingList.insert(100, 0);

	   cout << "\nNew list to test isAscendingOrder() on a list with one element\n";
	   ascendingList.display(cout);
	   cout << "\nIs list in ascending order? " << ascendingList.isAscendingOrder() << endl;
   }

    
}