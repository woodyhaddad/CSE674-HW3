#ifndef __2__
#define __2__


#include "BST.h"

inline vector<int> slice(vector<int> const &v, int m, int n)			// vector slicing function
{
	auto first = v.cbegin() + m;

	auto last = v.cbegin() + n + 1;

	std::vector<int> vec(first, last);

	return vec;
}

inline void binaryShuffle(vector<int> vect, vector<int> *v) {			// takes in vector and shuffle it in binary fashion
	int vect_size = vect.size();
	if (vect_size == 0) {
		return;
	}
	else if (vect_size == 1) {
		v->push_back(vect[0]);
	}
	else if (vect_size == 2) {
		v->push_back(vect[0]);
		v->push_back(vect[1]);
	}
	else {
		int index_to_add = vect_size / 2;
		vector<int> slice_1 = slice(vect, 0, index_to_add - 1);					// left sub-vector
		vector<int> slice_2 = slice(vect, index_to_add + 1, vect_size - 1);		// right sub vector
		v->push_back(vect[index_to_add]);
		binaryShuffle(slice_1, v);
		binaryShuffle(slice_2, v);
	}
}
	
#endif