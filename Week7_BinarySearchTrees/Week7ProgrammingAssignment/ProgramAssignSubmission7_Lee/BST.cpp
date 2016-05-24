/*------------------------------------------------------------------------------------
Programming Assignment 6 Submission
Binary Search Trees - Use recursion to search, order, and count the nodes in a
					  Binary Search Tree.
Created by Hyo Lee
Student ID: 002292770
02/23/2016
-------------------------------------------------------------------------------------*/

#include <iostream>
#include <iomanip>

using namespace std;

#include "BST.h"

//--- Definition of constructor
BST::BST()
: myRoot(0)
{}

bool BST::empty() const
{ return myRoot == 0; }

//--- Definition of search()
bool BST::search(const int & item) const
{
	return searchAux(myRoot, item);
}

//--- Definition of searchAux()
bool BST::searchAux(BinNode * subtreeRoot, const int & item) const
{
	if (subtreeRoot == NULL)
	{
		return false;	// empty subtree
	}
	if (item < subtreeRoot->data)
	{
		return searchAux(subtreeRoot->left, item);		// search left subtree
	}
	else if (subtreeRoot->data < item)
	{
		return searchAux(subtreeRoot->right, item);		// search right subtree
	}
	else
	{
		return true;	// item found at root
	}
}

void BST::insert(const int & item)
{
   BinNode * locptr = myRoot;   // search pointer
   BinNode * parent = 0;        // pointer to parent of current node
   bool found = false;     // indicates if item already in BST
   while (!found && locptr != 0)
   {
      parent = locptr;
      if (item < locptr->data)       // descend left
         locptr = locptr->left;
      else if (locptr->data < item)  // descend right
         locptr = locptr->right;
      else                           // item found
         found = true;
   }
   if (!found)
   {                                 // construct node containing item
      locptr = new BinNode(item);  
      if (parent == 0)               // empty tree
         myRoot = locptr;
      else if (item < parent->data )  // insert to left of parent
         parent->left = locptr;
      else                           // insert to right of parent
         parent->right = locptr;
   }
   else
      cout << "Item already in the tree\n";
}

//--- Definition of inorder()
void BST::inOrder(ostream & out) const
{
	inOrderAux(out, myRoot);
}

//--- Definition of inorderAux()
void BST::inOrderAux(ostream & out, BinNode * subtreeRoot) const
{
	if (empty())
	{
		cout << "Empty tree";
	}
	else if (subtreeRoot != 0)
	{
		inOrderAux(out, subtreeRoot->left);		// L operation
		out << subtreeRoot->data << " ";		// V operation
		inOrderAux(out, subtreeRoot->right);	// R operation
	}
}

//--- Definition of preOrder()
void BST::preOrder(ostream & out) const
{
	preOrderAux(out, myRoot);
}

//--- Definition of preOrderAux()
void BST::preOrderAux(ostream & out, BinNode * substreeRoot) const
{
	if (empty())
	{
		cout << "Empty tree";
	}
	else if (substreeRoot != NULL)
	{
		out << substreeRoot->data << " ";		// V operation
		preOrderAux(out, substreeRoot->left);	// L operation
		preOrderAux(out, substreeRoot->right);	// R operation
	}
}

//--- Definition of nodeCount()
int BST::nodeCount()
{
	return nodeCountAux(myRoot);
}

//--- Definition of nodeCountAux()
int BST::nodeCountAux(BinNode * substreeRoot)
{
	if (substreeRoot != NULL)
	{
		// Traverse left substree and right substree add each subtree root add main root 
		return nodeCountAux(substreeRoot->left) + nodeCountAux(substreeRoot->right) + 1;
	}
	else
	{
		return 0;		// Empty tree
	}
}