#pragma once
#include "node.h"
#include <iostream>

template <typename TElem>
class Iterator
{
	Node<TElem>* root = NULL;	// root is a pointer to the node that is the start of the tree, this pointer will cange as the inorder traversal is started

	// Modifies the root of the iterator so that it starts from the most left node of the tree.
	// returns false if the pointer to the node is null, true otherwise.
	bool DeeperToLeft(Node<TElem>* here)
	{
		if (here == NULL) {
			return false;
		}

		if (!DeeperToLeft(here->left)) {
			root = here;
		}

		return true;
	}
public:
	// Init function for the iterator given as parameter the first node (the root).
	// the root of the iterator becomes the most left node of the tree
	Iterator(Node<TElem>* root) :root{ root } { DeeperToLeft(root->left); }
	
	// Validator function for the current node.
	// returns true if the current node is valid (different from null), false otherwise.
	bool isValid();

	// Retruns the value from the current node.
	TElem getValue();

	// Iterates to the next node from the tree.
	void next();
};

template<typename TElem>
inline bool Iterator<TElem>::isValid()
{
	return root != NULL;
}

template<typename TElem>
inline TElem Iterator<TElem>::getValue()
{
	return root->data;
}

template<typename TElem>
inline void Iterator<TElem>::next()
{
	// Performs the inorder traversal through the binary tree
	if (!DeeperToLeft(root->right))	// goes to the most left node of the right child
	{
		if (root->parent != NULL)
		{
			while (root->parent != NULL && root == root->parent->right)	// checks if the root is equal to the right child of the parent of the root
																		// and goes to the right child of parent of the current node repetitively
				root = root->parent;
			root = root->parent;	// the root becomes its parent
		}
	}
}
