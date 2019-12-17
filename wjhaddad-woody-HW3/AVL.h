///////////////////////////// Task 3 header \\\\\\\\\\\\\\\\\\\\\\\\\\\\\


#ifndef __3__
#define __3__

#include <iostream>
#include <vector>
#include <iomanip>
#include "BST.h"

using namespace std;

class AVL
{
	//node* root = NULL;
public:
	AVL()
	{
		node* root = NULL;
	}
	node* root = NULL;
	node* Insert(int, node* root);	// this method adds a node to the given AVL with a given int input. Note that insert is self balancing
	node* Delete(int, node*);	// this method deletes a node of a given int input from the given AVL tree. delete() is self balancing
	int printTree(node*, int); // Prints tree structure with values, and returns height
	int height(node*); // Prints tree structure with values, and returns height




};

#endif



