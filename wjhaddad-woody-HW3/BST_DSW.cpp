///////////////////////////// Task 2 \\\\\\\\\\\\\\\\\\\\\\\\\\\\\

//reference: https://gist.github.com/harish-r/a7df7ce576dda35c9660

#include "BST_DSW.h"

node* findMinDSW(node* t)															// Helper function
{
	if (t == NULL)
		return NULL;
	else if (t->left == NULL)
		return t;
	else
		return findMinDSW(t->left);
}

int BST_DSW::printTree(node* root, int indent)										// Prints tree rotated by 90 degrees. Returns height of tree
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

int BST_DSW::height(node* root)										// Returns height of tree
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



node* BST_DSW::Insert(int val, node* root)
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

node* BST_DSW::Delete(int val, node* root)
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
		temp = findMinDSW(root->right);
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


bool rightRotate(node* subtree) {						// function to right rotate tree at input node

		if (subtree == 0) { return false; }
		if (subtree->left == 0) { return false; }

		const int tempdata = subtree->data;
		subtree->data = subtree->left->data;
		subtree->left->data = tempdata;

		node *originalleft = subtree->left;
		subtree->left = originalleft->left;
		originalleft->left = originalleft->right;	
		originalleft->right = subtree->right;		
		subtree->right = originalleft;			

		return true;
};

bool leftRotate(node* subtree) {						// function to right rotate tree at input node

	if (subtree == 0) { return false; }
	if (subtree->right == 0) { return false; }

	const int tempdata = subtree->data;
	subtree->data = subtree->right->data;
	subtree->right->data = tempdata;

	node *originalright = subtree->right;
	subtree->right = originalright->right;
	originalright->right = originalright->left;
	originalright->left = subtree->left;
	subtree->left = originalright;

	return true;
};

bool BST_DSW::DSW(node* htree)					// DSW algorithm. htree is root of tree to balance with DSW

	{
		assert(htree != 0);

	node* currentNode = htree;					
		int nodecount = 0;						

		while (currentNode != 0)				
		{
			while (currentNode->left != 0)		
			{
				rightRotate(currentNode);
			}
			currentNode = currentNode->right;	
			nodecount += 1;						
		}

		// If the height + 1 isn't equal to the number of nodes in the tree we should stop
		if (nodecount != this->height(htree)+1)
		{
			return false;
		}


		// left rotate tree until balanced.

		int expected = ceil(log2(nodecount)) - nodecount; 	// nodes on the bottom level.
		node* currentNode1 = htree;	// the new root 

		for (int i = 0; i < expected; i++)
		{
			if (i == 0)					
			{
				printf("if executes \n");
				leftRotate(currentNode1);	// Rotate the root.
				currentNode1 = htree; 	
			}
			else						
			{
				printf("else executes \n");
				leftRotate(currentNode1->right);	
				currentNode1 = currentNode1->right;	
			}
		}

		int times = nodecount;					// The number of rotations
		while (times > 1)
		{
			times /= 2;					

										// Do a left rotate on the root.
			leftRotate(htree);			
			node* currentNode2 = htree;	

															// Do a left rotate on all the rest of the odd nodes 
			for (int i = 0; i < times - 1; i++)		
			{
				leftRotate(currentNode2->right);	// Rotate the right of the current node (which will always be odd.)
				currentNode2 = currentNode2->right;	
			}
		}



		return true;

}