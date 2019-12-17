//// Task 4 .cpp
#include "splay.h"
#include "BST.h"

//
//int splay::height(node *NODE)
//{
//	if (NODE == NULL)
//
//		return 0;
//
//	return NODE->height;
//}
//
//int splay::maximum(int a, int b) {
//
//	if (a > b) {
//		return a;
//	}
//	return b;
//
//};
//
//
//
//
////// A utility function to right 
////// rotate subtree rooted with y  
////// See the diagram given above.  
////node *rightRotate(node *x)
////{
////	node *y = x->left;
////	x->left = y->right;
////	y->right = x;
////	return y;
////}
////
////// A utility function to left 
////// rotate subtree rooted with x  
////// See the diagram given above.  
////node *leftRotate(node *x)
////{
////	node *y = x->right;
////	x->right = y->left;
////	y->left = x;
////	return y;
////}
//
//
//
//
//
//void splay::rightRotate(node* x)
//{
//	// rotate right at node x
//		node* y = x->left;
//		x->left = y->right;
//		if (y->right != nullptr) {
//			y->right->parent = x;
//		}
//		y->parent = x->parent;
//		if (x->parent == nullptr) {
//			this->root = y;
//		}
//		else if (x == x->parent->right) {
//			x->parent->right = y;
//		}
//		else {
//			x->parent->left = y;
//		}
//		y->right = x;
//		x->parent = y;
//	
//}
//
//void splay::leftRotate(node* x)
//{
//		node* y = x->right;
//		x->right = y->left;
//		if (y->left != nullptr) {
//			y->left->parent = x;
//		}
//		y->parent = x->parent;
//		if (x->parent == nullptr) {
//			this->root = y;
//		}
//		else if (x == x->parent->left) {
//			x->parent->left = y;
//		}
//		else {
//			x->parent->right = y;
//		}
//		y->left = x;
//		x->parent = y;
//	
//}
//
//int splay::printTree(node* root, int indent)										// Prints tree rotated by 90 degrees. Returns height of tree
//{
//
//	if (root != NULL) {															// This if loop was taken from "https://stackoverflow.com/questions/13484943/print-a-binary-tree-in-a-pretty-way"
//		if (root->right) {
//			printTree(root->right, indent + 4);
//		}
//		if (indent) {
//			std::cout << std::setw(indent) << ' ';
//		}
//		if (root->right) std::cout << " /\n" << std::setw(indent) << ' ';
//		std::cout << root->data << "\n ";
//		if (root->left) {
//			std::cout << std::setw(indent) << ' ' << " \\\n";
//			printTree(root->left, indent + 4);
//		}
//		//int a = (root->right != NULL) || root->left != NULL;
//		//return 1 + (root->right != NULL) || (root->left != NULL);
//	}
//	return 0;
//}
//
//
//// This function brings the key at  
//// root if key is present in tree.  
//// If key is not present, then it  
//// brings the last accessed item at  
//// root. This function modifies the  
//// tree and returns the new root  
//void splay::splayfunc(node *x)
//{
//		while (x->parent) {
//			if (!x->parent->parent) {
//				if (x == x->parent->left) {
//					// zig rotation
//					rightRotate(x->parent);
//				}
//				else {
//					// zag rotation
//					leftRotate(x->parent);
//				}
//			}
//			else if (x == x->parent->left && x->parent == x->parent->parent->left) {
//				// zig-zig rotation
//				rightRotate(x->parent->parent);
//				rightRotate(x->parent);
//			}
//			else if (x == x->parent->right && x->parent == x->parent->parent->right) {
//				// zag-zag rotation
//				leftRotate(x->parent->parent);
//				leftRotate(x->parent);
//			}
//			else if (x == x->parent->right && x->parent == x->parent->parent->left) {
//				// zig-zag rotation
//				leftRotate(x->parent);
//				rightRotate(x->parent);
//			}
//			else {
//				// zag-zig rotation
//				rightRotate(x->parent);
//				leftRotate(x->parent);
//			}
//		}
//	
//}
//
//
//void splay::Insert(int key)
//{
//		// normal BST insert
//		node* Node = new node;
//		Node->parent = nullptr;
//		Node->left = nullptr;
//		Node->right = nullptr;
//		Node->data = key;
//		node* y = nullptr;
//		node* x = this->root;
//
//		while (x != nullptr) {
//			y = x;
//			if (Node->data < x->data) {
//				x = x->left;
//			}
//			else {
//				x = x->right;
//			}
//		}
//
//		// y is parent of x
//		Node->parent = y;
//		if (y == nullptr) {
//			root = Node;
//		}
//		else if (Node->data < y->data) {
//			y->left = Node;
//		}
//		else {
//			y->right = Node;
//		}
//
//		// splay the node
//		splayfunc(Node);
//	
//  
//}
//
























// Task 4 .cpp

int splay::height(node *NODE)
{
	if (NODE == NULL)

		return 0;

	return NODE->height;
}

int splay::maximum(int a, int b) {

	if (a > b) {
		return a;
	}
	return b;

};

node* splay::rightRotate(node* Node)
{
	node *y = Node->left;
	Node->left = y->right;
	y->right = Node;
	return y;
}

node* splay::leftRotate(node* Node)
{
	node *y = Node->right;
	Node->right = y->left;
	y->left = Node;
	return y;
}

int splay::printTree(node* root, int indent)										// Prints tree rotated by 90 degrees. Returns height of tree
{

	if (root != NULL) {															// This if loop was taken from "https://stackoverflow.com/questions/13484943/print-a-binary-tree-in-a-pretty-way"
		if (root->right) {
			printTree(root->right, indent + 4);
		}
		if (indent) {
			std::cout << std::setw(indent) << ' ';
		}
		if (root->right) std::cout << " /\n" << std::setw(indent) << ' ';
		std::cout << root->data << "\n ";
		if (root->left) {
			std::cout << std::setw(indent) << ' ' << " \\\n";
			printTree(root->left, indent + 4);
		}
		//int a = (root->right != NULL) || root->left != NULL;
		//return 1 + (root->right != NULL) || (root->left != NULL);
	}
	return 0;
}


node* splay::splayfunc(node *root, int key)
{
	// Base case
	if (root == NULL || root->data == key)
		return root;

	if (root->data > key)
	{
		if (root->left == NULL) return root;

		// Zig-Zig (Left Left)  
		if (root->left->data > key)
		{
			root->left->left = splayfunc(root->left->left, key);

			// first rotation at roo  
			root = this->rightRotate(root);
		}
		else if (root->left->data < key)												// Zig-Zag (Left Right)  
		{
	  
			root->left->right = splayfunc(root->left->right, key);

			//  first rotation at root->left  
			if (root->left->right != NULL)
				root->left = this->leftRotate(root->left);
		}

		// second rotation   
		return (root->left == NULL) ? root : this->rightRotate(root);
	}
	else   
	{
		// Key not in tree  
		if (root->right == NULL) return root;

		// Zig-Zag (Right Left)  
		if (root->right->data > key)
		{
			root->right->left = splayfunc(root->right->left, key);

			// first rotation for root->right  
			if (root->right->left != NULL)
				root->right = this->rightRotate(root->right);
		}
		else if (root->right->data < key)// Zag-Zag (Right Right)  
		{
			 
			root->right->right = splayfunc(root->right->right, key);
			root = this->leftRotate(root);
		}

		return (root->right == NULL) ? root : this->leftRotate(root);
	}
}


node* splay::Insert(node* root, int key)
{

	if (root == NULL) {

		node* Node = new node();
		Node->data = key;
		Node->left = Node->right = NULL;
		return Node;

	}


	if (root->data == key) return root;

	node *Node = new node();
	Node->data = key;
	Node->left = Node->right = NULL;

	root = this->splayfunc(root, key);




	if (root->data > key)
	{
		Node->right = root;
		Node->left = root->left;
		root->left = NULL;
	}


	else
	{
		//printf("executes \n");

		Node->left = root;
		Node->right = root->right;
		root->right = NULL;
	}

	return Node;
}


	node* splay::search(node *root, int key) {
		return splayfunc(root, key);
	}


