// http://www.smunlisted.com/day-stout-warren-dsw-algorithm.html


#include "helpers.cpp"
#include "BST.h"
#include "BST_DSW.h"
#include "AVL.h"
#include "splay.h"
//#include <vector>
#include <stdlib.h>     /* srand, rand */

vector<int> v;


int main() {

	BST bst;
	vector<int> S1;						// declare vectors to store integers
	vector<int> S2;						// declare vectors to store integers

	for (int i = 1; i <= 100; i++)
	{
		S1.push_back(i);
	}

	int n = 0;

	while (S2.size() < 100)								// This while loop adds numbers from 1-100 to S2 vector in random order 
	{

		n = 0;

		int m = rand() % 100 + 1;

		if (S2.size() == 0)
		{
			S2.push_back(m);
		}


		for (int j = 0; j < S2.size(); j++)
		{

			if (S2[j] == m)
			{
				n++;
			}

		}

		if (n == 0)
		{
			S2.push_back(m);

		}

	}

	for (int i = 1; i <= 100; i++)
	{
		printf("S2 = %d\n", S2[i-1]);
	}
	////////////////////// Task 1 \\\\\\\\\\\\\\\\\\\\
	
	printf("||||||||||||||||||||||||||||||||||| Task 1 ||||||||||||||||||||||||||||||||||| \n\n\n\n");

	//// 1 \\ 

	printf("********** 1 ********** \n\n");

	(&bst)->root = bst.Insert(1, (&bst)->root);

	for (int i = 1; i < S1.size(); i++)
	{
		bst.Insert(S1[i], (&bst)->root);
		if ((i+1)%10 == 0)
		{
			printf("tree height is %d\n", bst.height((&bst)->root));
			bst.printTree((&bst)->root, 0);

		}
	}

	//// 1 a \\ 

	printf("**********  a ********** \n\n");

	bst.Delete(50, (&bst)->root);
	printf("tree height is %d\n", bst.height((&bst)->root));
	bst.printTree((&bst)->root, 0);
	
	//// 2 \\ 

	printf("********** 2 ********** \n\n");

	(&bst)->root = NULL;				// make tree empty
	(&bst)->root = bst.Insert(S2[0], (&bst)->root);			// Initialize tree at root with first element of S2

		for (int i = 1; i < S2.size(); i++)
	{
		bst.Insert(S2[i], (&bst)->root);
		if ((i+1)%10 == 0)
		{
			printf("tree height is %d\n", bst.height((&bst)->root));
			bst.printTree((&bst)->root, 0);

		}
	}

	//// 2 a \\
	
	printf("********** 2 a ********** \n\n");

		bst.Delete(50, (&bst)->root);
		printf("tree height is %d\n", bst.height((&bst)->root));
		bst.printTree((&bst)->root, 0);

	//// 3 \\\\

	printf("********** 3 ********** \n\n");


	(&bst)->root = NULL;				// make tree empty

	binaryShuffle(S1, &v);				// call binary shuffle function that re-sorts S1 in binary fashion into v vector

	(&bst)->root = bst.Insert(v[0], (&bst)->root);

	for (int i = 1; i < v.size(); i++)		// inserts elements of v vector (binary sorted)
	{
		bst.Insert(v[i], (&bst)->root);
		if ((i+1)%10 == 0)
		{
			printf("tree height is %d\n", bst.height((&bst)->root));
			bst.printTree((&bst)->root, 0);

		}
	}

	//// 3 a \\\\

	printf("********** 3 a ********** \n\n");
		bst.Delete(50, (&bst)->root);
		printf("tree height is %d\n", bst.height((&bst)->root));
		bst.printTree((&bst)->root, 0);



	//////////////////// Task 2 \\\\\\\\\\\\\\\\\\\\
			
	printf("||||||||||||||||||||||||||||||||||| Task 2 ||||||||||||||||||||||||||||||||||| \n\n\n\n");


	printf("********** 1 ********** \n\n");


	BST_DSW bstDsw;

	(&bstDsw)->root = bstDsw.Insert(1, (&bstDsw)->root);

	for (int i = 1; i < S1.size(); i++)
	{
		bstDsw.Insert(S1[i], (&bstDsw)->root);
		if ((i+1)%10 == 0)
		{
			printf("tree height is %d\n", bstDsw.height((&bstDsw)->root));
			bstDsw.printTree((&bstDsw)->root, 0);

		}
	}

	printf("********** 1 a ********** \n\n");

	(&bstDsw)->root = NULL;				// make tree empty
	(&bstDsw)->root = bstDsw.Insert(S1[0], (&bstDsw)->root);

	for (int i = 1; i < S1.size(); i++)
	{
			bstDsw.Insert(S1[i], (&bstDsw)->root);
		if ((i + 1) % 10 == 0)
		{
			bstDsw.DSW((&bstDsw)->root);

			printf("tree height is %d\n", bstDsw.height((&bstDsw)->root));
			bstDsw.printTree((&bstDsw)->root, 0);

		}
	}

	printf("********** 1 b ********** \n\n");

	bstDsw.Delete(50, (&bstDsw)->root);
	printf("tree height is %d\n", bstDsw.height((&bstDsw)->root));
	bstDsw.printTree((&bstDsw)->root, 0);

	printf("********** 2 ********** \n\n");

	(&bstDsw)->root = bstDsw.Insert(S2[0], (&bstDsw)->root);

	for (int i = 1; i < S2.size(); i++)
	{
		bstDsw.Insert(S2[i], (&bstDsw)->root);
		if ((i+1)%10 == 0)
		{
			printf("tree height is %d\n", bstDsw.height((&bstDsw)->root));
			bstDsw.printTree((&bstDsw)->root, 0);

		}
	}

	printf("********** 2 a ********** \n\n");

	(&bstDsw)->root = NULL;				// make tree empty
	(&bstDsw)->root = bstDsw.Insert(S2[0], (&bstDsw)->root);

	for (int i = 1; i < S2.size(); i++)
	{
			bstDsw.Insert(S2[i], (&bstDsw)->root);
		if ((i + 1) % 10 == 0)
		{
			bstDsw.DSW((&bstDsw)->root);

			printf("tree height is %d\n", bstDsw.height((&bstDsw)->root));
			bstDsw.printTree((&bstDsw)->root, 0);

		}
	}

	printf("********** 2 b ********** \n\n");

	bstDsw.Delete(50, (&bstDsw)->root);
	printf("tree height is %d\n", bstDsw.height((&bstDsw)->root));
	bstDsw.printTree((&bstDsw)->root, 0);

	printf("********** 3 ********** \n\n");


	binaryShuffle(S1, &v);				// call binary shuffle function that re-sorts S1 in binary fashion into v vector

	(&bstDsw)->root = bstDsw.Insert(v[0], (&bstDsw)->root);

	for (int i = 1; i < v.size(); i++)		// inserts elements of v vector (binary sorted)
	{
		bstDsw.Insert(v[i], (&bstDsw)->root);
		if ((i + 1) % 10 == 0)
		{
			printf("tree height is %d\n", bstDsw.height((&bstDsw)->root));
			bstDsw.printTree((&bstDsw)->root, 0);

		}
	}

	printf("********** 3 a ********** \n\n");

	for (int i = 1; i < S2.size(); i++)
	{
			bstDsw.Insert(S2[i], (&bstDsw)->root);
		if ((i + 1) % 10 == 0)
		{
			bstDsw.DSW((&bstDsw)->root);

			printf("tree height is %d\n", bstDsw.height((&bstDsw)->root));
			bstDsw.printTree((&bstDsw)->root, 0);

		}
	}

	printf("********** 3 b ********** \n\n");

	bstDsw.Delete(50, (&bstDsw)->root);
	printf("tree height is %d\n", bstDsw.height((&bstDsw)->root));
	bstDsw.printTree((&bstDsw)->root, 0);


	//////////////////// Task 3 \\\\\\\\\\\\\\\\\\\\
				
	printf("||||||||||||||||||||||||||||||||||| Task 3 ||||||||||||||||||||||||||||||||||| \n\n\n\n");

	printf("********** 1 ********** \n\n");


	AVL avl;

	(&avl)->root = avl.Insert(S1[0], (&avl)->root);

	for (int i = 1; i < S1.size(); i++)
	{
		(&avl)->root = avl.Insert(S1[i], (&avl)->root);
		if ((i+1)%10 == 0)
		{
			printf("tree height is %d\n", avl.height((&avl)->root));
			printf("tree height is %d\n", (&avl)->root->height);
			avl.printTree((&avl)->root, 0);

		}
	}

	printf("********** 1 a ********** \n\n");

	(&avl)->root = avl.Delete(50, (&avl)->root);
	avl.printTree((&avl)->root, 0);

	printf("********** 2 ********** \n\n");


	(&avl)->root = NULL;				// make tree empty

	(&avl)->root = avl.Insert(S2[0], (&avl)->root);

	for (int i = 1; i < S2.size(); i++)
	{
		(&avl)->root = avl.Insert(S2[i], (&avl)->root);
		if ((i + 1) % 10 == 0)
		{
			printf("tree height is %d\n", avl.height((&avl)->root));
			printf("tree height is %d\n", (&avl)->root->height);
			avl.printTree((&avl)->root, 0);

		}
	}

	printf("********** 2 a ********** \n\n");

	(&avl)->root = avl.Delete(50, (&avl)->root);
	avl.printTree((&avl)->root, 0);

	printf("********** 3 ********** \n\n");


	binaryShuffle(S1, &v);				// call binary shuffle function that re-sorts S1 in binary fashion into v vector
	
	(&avl)->root = NULL;				// make tree empty
	(&avl)->root = avl.Insert(v[0], (&avl)->root);

	for (int i = 1; i < v.size(); i++)		// inserts elements of v vector (binary sorted)
	{
		(&avl)->root = avl.Insert(v[i], (&avl)->root);
		if ((i + 1) % 10 == 0)
		{
			printf("tree height is %d\n", avl.height((&avl)->root));
			avl.printTree((&avl)->root, 0);

		}
	}

	printf("********** 3 a ********** \n\n");

	(&avl)->root = avl.Delete(50, (&avl)->root);
	avl.printTree((&avl)->root, 0);


	printf("||||||||||||||||||||||||||||||||||| Task 4 ||||||||||||||||||||||||||||||||||| \n\n\n\n");


	printf("********** 1 ********** \n\n");


	splay spl;

	(&spl)->root = spl.Insert((&spl)->root, S1[0]);

	for (int i = 1; i < S1.size(); i++)
	{
		(&spl)->root = spl.Insert((&spl)->root, S1[i]);
		if ((i+1)%10 == 0)
		{
			printf("tree height is %d\n", spl.height((&spl)->root));
			printf("tree height is %d\n", (&spl)->root->height);
			spl.printTree((&spl)->root, 0);

		}
	}

	printf("********** 1 a ********** \n\n");

	(&spl)->root = spl.search((&spl)->root, 50);
	spl.printTree((&spl)->root, 0);

	printf("********** 2 ********** \n\n");


	(&spl)->root = NULL;				// make tree empty

	(&spl)->root = spl.Insert((&spl)->root, S2[0]);

	for (int i = 1; i < S2.size(); i++)
	{
		(&spl)->root = spl.Insert((&spl)->root, S2[i]);
		if ((i + 1) % 10 == 0)
		{
			printf("tree height is %d\n", spl.height((&spl)->root));
			printf("tree height is %d\n", (&spl)->root->height);
			spl.printTree((&spl)->root, 0);

		}
	}

	printf("********** 2 a ********** \n\n");

	(&spl)->root = spl.search((&spl)->root, 50);
	spl.printTree((&spl)->root, 0);

	printf("********** 3 ********** \n\n");


	binaryShuffle(S1, &v);				// call binary shuffle function that re-sorts S1 in binary fashion into v vector
	
	(&spl)->root = NULL;				// make tree empty
	(&spl)->root = spl.Insert((&spl)->root, v[0]);

	for (int i = 1; i < v.size(); i++)		// inserts elements of v vector (binary sorted)
	{
		(&spl)->root = spl.Insert((&spl)->root, v[i]);
		if ((i + 1) % 10 == 0)
		{
			printf("tree height is %d\n", spl.height((&spl)->root));
			spl.printTree((&spl)->root, 0);

		}
	}

	printf("********** 3 a ********** \n\n");

	(&spl)->root = spl.search((&spl)->root, 50);
	spl.printTree((&spl)->root, 0);

	system("pause");
	return 0;
}



