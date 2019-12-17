// TASK 4 header

// Reference: www.geeksforgeeks.org

#ifndef __4__
#define __4__

#include <iostream>
#include <vector>
#include <iomanip>
#include "BST.h"

using namespace std;

class splay
{
	//node* root = NULL;
public:
	splay()
	{
		node* root = NULL;
	}
	node* root = NULL;
	node* Insert(node*, int);	// this method adds a node to the given splay with a given int input. Note that insert is self balancing
	int printTree(node*, int); // Prints tree structure with values, and returns height
	int height(node*); // Prints tree structure with values, and returns height
	int maximum(int, int);
	node* rightRotate(node*);
	node* leftRotate(node*);
	node* splayfunc(node*, int);
	node* search(node*, int);




};

#endif