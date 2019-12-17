///////////////////////////// Task 1 header \\\\\\\\\\\\\\\\\\\\\\\\\\\\\


#ifndef __1__
#define __1__

#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

struct node
{
	int data;
	int height;
	node* parent;
	node* left;
	node* right;
};

class BST
{
	//node* root = NULL;
public:
	BST()
	{
		node* root = NULL;
	}
	node* root = NULL;
	node* Insert(int, node* root);	// this method adds a node to the given BST with a given int input
	node* Delete(int, node*);	// this method deletes a node of a given int input from the given BST (if int is not in the tree, Delete() returns 0 and does nothing to the tree, otherwise returns 1)
	int printTree(node*, int); // Prints tree structure with values, and returns height
	int height(node*); // Prints tree structure with values, and returns height




};

#endif