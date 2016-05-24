/*------------------------------------------------------------------------------------
Programming Assignment 6 Submission
Binary Search Trees - Use recursion to search, order, and count the nodes in a
					  Binary Search Tree.
Created by Hyo Lee
Student ID: 002292770
02/23/2016
-------------------------------------------------------------------------------------*/


/*----- treetester.cpp -----------------------------------------------------
                Program for testing BST.
 ------------------------------------------------------------------------*/
#include <iostream>
using namespace std;

#include "BST.h"

int main()
{
   // Testing Constructor and empty()
   BST intBST;            // test the class constructor
   cout << "Constructing empty BST\n";
   cout << "BST " << (intBST.empty() ? "is" : "is not") << " empty\n";

   // Testing insert
   cout << "\nNow insert a bunch of integers into the BST."
           "\nTry items not in the BST and some that are in it:\n";
   int number;
   for (;;)
   {
      cout << "Item to insert (-999 to stop): ";
      cin >> number;
      if (number == -999) break;
      intBST.insert(number);
   }
   cout << "BST " << (intBST.empty() ? "is" : "is not") << " empty\n";

   // Testing search()
   cout << "\n\nNow testing the search() operation."
           "\nTry both items in the BST and some not in it:\n";
   for (;;)
   {
      cout << "Item to find (-999 to stop): ";
      cin >> number;
      if (number == -999) break;
      cout << (intBST.search(number) ? "Found" : "Not found") << endl;
   }

   // Testing inOrder traversal
   cout << "\nInOrder traversal of BST: ";
   intBST.inOrder(cout);

   // Testing preOrder traversal
   cout << "\nPreOrder traversal of BST: ";
   intBST.preOrder(cout);

   // Testing nodeCount()
   cout << "\nNode Count = ";
   cout << intBST.nodeCount();
   cout << endl;
}
