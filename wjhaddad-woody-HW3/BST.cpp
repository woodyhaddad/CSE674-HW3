///////////////////////////// Task 1 \\\\\\\\\\\\\\\\\\\\\\\\\\\\\

//reference: https://gist.github.com/harish-r/a7df7ce576dda35c9660

#include "BST.h"

node* findMin(node* t)															// Helper function
{
	if (t == NULL)
		return NULL;
	else if (t->left == NULL)
		return t;
	else
		return findMin(t->left);
}

int BST::printTree(node* root, int indent)										// Prints tree rotated by 90 degrees. Returns height of tree
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

int BST::height(node* root)										// Returns height of tree
{
	if (root == NULL)
	{
		return -1;
	}
	int a = 1 + (height(root->right));
	int b = 1 + (height(root->left));

	if (a > b)
	{
		return a;
	}
	return b;
}



node* BST::Insert(int val, node* root)
{
	if (root == NULL)
	{
		root = new node;
		root->data = val;
		root->left = root->right = NULL;

	}
	else if (val < root->data)
	{
		root->left = Insert(val, root->left);
	}
	else if (val > root->data)
	{
		root->right = Insert(val, root->right);
	}
	//printf("root->data is %d\n", root->data);

	return root;

}

node* BST::Delete(int val, node* root)
{
	node* temp;
	if (root == NULL)
		return NULL;
	else if (val < root->data)
		root->left = Delete(val, root->left);
	else if (val > root->data)
		root->right = Delete(val, root->right);
	else if (root->left && root->right)
	{
		temp = findMin(root->right);
		root->data = temp->data;
		root->right = Delete(root->data, root->right);
	}
	else
	{
		temp = root;
		if (root->left == NULL)
			root = root->right;
		else if (root->right == NULL)
			root = root->left;
		delete temp;
	}

	return root;
}
