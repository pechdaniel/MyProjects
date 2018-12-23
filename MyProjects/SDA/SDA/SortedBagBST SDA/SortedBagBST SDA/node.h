#pragma once

template <typename TElem>
class Node
{
public:
	TElem data;		// data contains the value of type TElem of the node
	Node* parent;	// parent is a pointer to the parent of the current node
	Node* left;		// left is a pointer to the left child of the current node
	Node* right;	// right is a pointer to the right child of the current node
};