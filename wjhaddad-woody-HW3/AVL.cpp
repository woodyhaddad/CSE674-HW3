#include "AVL.h"

int height(node *NODE)
{
	if (NODE == NULL)

		return 0;

	return NODE->height;
}

int maximum(int a, int b) {

	if (a > b){
	return a;
	}
	return b;

	};


node * minDataNode(node* Node)
{
	node* current = Node;

	/* loop down to find the leftmost leaf */
	while (current->left != NULL)
	{
		current = current->left;
	}
	return current;
}

node *rightRotate(node* Node)
{
	node *x = Node->left;
	node *temp = x->right;


	// Perform rotation  
	x->right = Node;
	Node->left = temp;

	// Update heights  
	Node->height = maximum(height(Node->left), height(Node->right)) + 1;

	x->height = maximum(height(x->left), height(x->right)) + 1;

	// Return new root  
	return x;
}

node *leftRotate(node* Node)
{
	node *x = Node->right;
	node *temp = x->left;


	// Perform rotation  
	x->left = Node;
	Node->right = temp;

	// Update heights  
	Node->height = maximum(height(Node->left), height(Node->right)) + 1;

	x->height = maximum(height(x->left), height(x->right)) + 1;

	// Return new root  
	return x;
}

int AVL::printTree(node* root, int indent)										// Prints tree rotated by 90 degrees. Returns height of tree
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
//

//
int AVL::height(node* root)										// Returns height of tree
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

node* AVL::Insert(int key, node* root) {
	
	/* 1. Perform the normal BST insertion */
	if (root == NULL) {						// if tree is empty, root is NULL, and this statement will insert a new node with key value at head
		node* Node1 = new node();
		Node1->data = key;
		Node1->left = NULL;
		Node1->right = NULL;
		Node1->height = 1;
		return(Node1);
		}

	if (key < root->data)							// traverses the tree to left if key smaller than root
	{
		root->left = Insert(key, root->left);
	}
	else if (key > root->data) {					// traverses the tree to right if key smaller than root
		root->right = Insert(key, root->right);
		}
	else
	{
		return root;
	}



	root->height = 1 + maximum(height(root->left), height(root->right));

	int balance;

	if (root == NULL)
	{
		balance = 0;
	}
	else
	{
		balance = height(root->left) - height(root->right);
	}

	// If  node becomes unbalanced, there are 4 cases  

	// Left Left Case  
	if (balance > 1 && key < root->left->data)
	{
		return rightRotate(root);
	}

	// Right Right Case  
	if (balance < -1 && key > root->right->data)
	{
		return leftRotate(root);
	}

	// Left Right Case  
	if (balance > 1 && key > root->left->data)
	{
		root->left = leftRotate(root->left);
		return rightRotate(root);
	}

	// Right Left Case  
	if (balance < -1 && key < root->right->data)
	{
		root->right = rightRotate(root->right);
		return leftRotate(root);
	}

	return root;


};



// This function returns the root of the modified subtree
node* AVL::Delete(int key, node* root)
{

	if (root == NULL)
		//system("pause");

		return root;


	if (key < root->data)
		root->left = Delete(key, root->left);


	else if (key > root->data)
		root->right = Delete(key, root->right);

	// This is node to be deleted  if above conditionals dont execute 
	else
	{
		if ((root->left == NULL) ||
			(root->right == NULL))
		{
			node *temp = root->left ? root->left : root->right;

			// No child case  
			if (temp == NULL)
			{
				root = NULL;
			}
			else // One child   
				*root = *temp; 
			free(temp);
		}
		else
		{
			node* temp = minDataNode(root->right);

			root->data = temp->data;

			root->right = Delete(temp->data, root->right );
		}
	}

	// If  tree has one node 
	if (root == NULL)
		return root;

	root->height = 1 + maximum(height(root->left),
		height(root->right));

	int balance;

	if (root == NULL)
	{
		balance = 0;
	}
	else
	{
		balance = height(root->left) - height(root->right);
	}



	int balanceL, balanceR;

	if (root == NULL)
	{
		balanceL = 0;
		balanceR = 0;

	}
	else
	{
		if (root->right == NULL)
		{
			balanceR = 0;
		}
		else
		{
			balanceR = height(root->right->left) - height(root->right->right);
		}

		if (root->left == NULL)
		{
			balanceL = 0;
		}
		else
		{
			balanceL = height(root->left->left) - height(root->left->right);
		}

	}


	// Left Left 

	if (balance > 1 && balanceL >= 0)
		return rightRotate(root);

	// Left Right   

	if (balance > 1 && balanceL < 0)
	{
		root->left = leftRotate(root->left);
		return rightRotate(root);
	}

	// Right Right  

	if (balance < -1 && balanceR <= 0)
		return leftRotate(root);

	// Right Left 

	if (balance < -1 && balanceR > 0)
	{
		root->right = rightRotate(root->right);
		return leftRotate(root);
	}

	return root;
}