/*------------------------------------------------------------------------------------
Programming Assignment 6 Submission
Binary Search Trees - Use recursion to search, order, and count the nodes in a
					  Binary Search Tree.
Created by Hyo Lee
Student ID: 002292770
02/23/2016
-------------------------------------------------------------------------------------*/

#include <iostream>
using namespace std;  

#ifndef BINARY_SEARCH_TREE
#define BINARY_SEARCH_TREE

class BST
{
public:
	/***** Function Members *****/
	BST();
	bool empty() const;
	bool search(const int & item) const;	// Calls searchAux() (hidden from user)
	void insert(const int & item);
	void inOrder(ostream & out) const;		// Calls inOrderAux() (hidden from user)
	void preOrder(ostream & out) const;		// Calls preOrderAux() (hidden from user)
	int nodeCount();						// Calls nodeCountAux() (hidden from user)
	
private:
  /***** Node class *****/
  class BinNode 
  {
   public:
    int data;
    BinNode * left;
    BinNode * right;

    // BinNode constructors
    // Default -- data part is default int value; both links are null.
    BinNode()
    : left(0), right(0)
    {}

    // Explicit Value -- data part contains item; both links are null.
    BinNode(int item)
    : data(item), left(0), right(0)
    {}
 
  };// end of class BinNode declaration
  
  /***** Data Members *****/
  BinNode * myRoot;

  /***** Private Member Functions *****/
  bool searchAux(BinNode * subtreeRoot, const int & item) const;
  void inOrderAux(ostream & out, BinNode * subtreePtr) const;
  void preOrderAux(ostream & out, BinNode * substreePtr) const;
  int nodeCountAux(BinNode * substreeRoot);

}; // end of class declaration

#endif
