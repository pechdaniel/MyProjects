#pragma once
#include "node.h"
#include "iterator.h"
#include <iostream>
#include <string>

template <typename TElem>
class SortedBag
{
private:
	Node<TElem>* root;		// root is a pointer to a node
	std::string relation;	// relation is a string that will consist in comparing two values
	
	//	Comparison function between two values, this function uses the relation
	bool cmp(TElem e1, TElem e2);

	// Adds a new node to the tree, returns the pointer to the node.
	Node<TElem>* add(Node<TElem>* parent, Node<TElem>* root, TElem data);

	// Searches the value in the tree and returns a pointer to the node if the value is found.
	Node<TElem>* find(Node<TElem>* root, TElem data);

	// Recursively deletes a node from the tree
	Node<TElem>* del(Node<TElem>* root, TElem data);

	// Returns a pointer to the most left node.
	Node<TElem>* FindMin(Node<TElem>* root);
	// Destroies the children along with their children of the root, after which the root itself is destroyed.
	void destroy(Node<TElem>* root);
	// Counts and returns the number of elements from the sorted bag recursively.
	void count(Node<TElem>* root, int &contor);
public:
	//int cnt;
	// Constructor for the sorted bag, initializes the root to NULL and the relation to a string
	SortedBag(std::string relation) :relation{ relation } { root = NULL; }

	// Deconstructor for the sorted bag
	~SortedBag() { destroy(root); }

	

	// Inserts a new element into the tree.
	void insert(TElem data);

	// Removes a node with a given value from the tree.
	bool remove(TElem data);

	// Searches the given value in the tree, if it finds it then returns true, false otherwise.
	bool search(TElem data);


	// Returns the number of elements from the sorted bag.
	int size();

	// Returns the iterator for the binary tree.
	Iterator<TElem> iterator() { return Iterator<TElem>{ root }; }
};

template<typename TElem>
inline bool SortedBag<TElem>::cmp(TElem e1, TElem e2)
{
	if (relation == ">")
		return e1 > e2;
	return e1< e2;
}

template<typename TElem>
inline Node<TElem>* SortedBag<TElem>::add(Node<TElem>* parent,Node<TElem>* root, TElem data)
{
	if (root == NULL) {		// sets up the root to be the first node
		root = new Node<TElem>();	// allocates new memory for the root
		root->data = data;			// data from the root becomes the given parameter
		root->parent = parent;		// the parent is going to be a pointer to the parent node
		root->left = NULL;			// both left and right childs are set to null
		root->right = NULL;	
	}
	else if (!cmp(data, root->data))	// compares the two values using the given relation
		root->left = add(root, root->left, data);
	// checks if the given value is greater than the one in the current node 
	// and makes a decision based on the relation wether it should be a left or a right child
	else
		root->right = add(root, root->right, data);
	return root;
}

template<typename TElem>
inline Node<TElem>* SortedBag<TElem>::find(Node<TElem>* root, TElem data)
{
	if (root != NULL) {

		if (data == root->data)
			return root;

		if (!cmp(data, root->data))
			return find(root->left, data);
		else
			return find(root->right, data);

	}
	else
		return NULL;
}

template<typename TElem>
inline Node<TElem>* SortedBag<TElem>::del(Node<TElem>* root, TElem data)
{
	if (root == NULL) return root;
	else if (data < root->data) root->left = del(root->left, data);
	else if (data > root->data) root->right = del(root->right, data);
	else {
		// case 1: no child
		if (root->left == NULL && root->right == NULL) {
			delete root;	// easily frees the memory allocated to the leaf
			root = NULL;	// sets the root to null
		}
		// case 2: one child (right child)
		else if (root->left == NULL) {

			Node<TElem> *temp = root->right;	// saving the pointer to the right child
			
			root->data = root->right->data;		// replaces the current node pointer with its right child
			root->left = root->right->left;
			root->right = root->right->right;
			
			if (root->left != NULL &&root->left->right != NULL )
				root->left->right->parent = root->left;
			if (root->left != NULL && root->left->left != NULL)
				root->left->left->parent = root->left;
			if (root->right != NULL&&root->right->left != NULL )
				root->right->left->parent = root->right;
			if (root->right != NULL && root->right->right != NULL)
				root->right->right->parent = root->right;
			
			delete temp;						// frees the memory allocated for the right child
		}
		// case 2: one child (left child)
		else if (root->right == NULL) {            
			Node<TElem> *temp = root->left;		// saving the pointer to the left child
			
			root->data = root->left->data;		// replaces the current node pointer with its left child
			root->right = root->left->right;
			root->left = root->left->left;

			if (root->left != NULL && root->left->right != NULL)
				root->left->right->parent = root->left;
			if (root->left != NULL && root->left->left != NULL)
				root->left->left->parent = root->left;
			if (root->right != NULL && root->right->left != NULL)
				root->right->left->parent = root->right;
			if (root->right != NULL && root->right->right != NULL)
				root->right->right->parent = root->right;
			delete temp;						// frees the memory alocated for the left child
		}
		// case 3: two children
		else {
			Node<TElem> *temp = FindMin(root->right);
			root->data = temp->data;
			root->right = del(root->right, temp->data);		// recursively replaces the nodes one by one so that the old node can be freed 
		}
	}
	return root;
}

template<typename TElem>
inline Node<TElem>* SortedBag<TElem>::FindMin(Node<TElem>* root)
{
	while (root->left != NULL)
		root = root->left;
	return root;
}

template<typename TElem>
inline void SortedBag<TElem>::destroy(Node<TElem>* root)
{
	// frees the memory allocated to all the nodes below 'root', after which frees the memory allocated for 'root'
	if (root != NULL)
	{
		destroy(root->left);
		destroy(root->right);
		delete root;
	}
}

template<typename TElem>
inline void SortedBag<TElem>::insert(TElem data)
{
	
	root = add(NULL,root, data);
}

template<typename TElem>
inline bool SortedBag<TElem>::remove(TElem data)
{
	if (search(data) == false)
		return false;
	
	root = del(root, data);
	return true;
}

template<typename TElem>
inline bool SortedBag<TElem>::search(TElem data)
{
	Node<TElem>* x = find(root, data);

	if (x == NULL)
		return false;
	return true;
}

template<typename TElem>
inline void SortedBag<TElem>::count(Node<TElem>* root,int &contor)
{
	if (root == NULL)
		return;

	contor += 1;

	if (root->left != NULL)
		count(root->left, contor);
	if (root->right != NULL)
		count(root->right, contor);
}

template<typename TElem>
inline int SortedBag<TElem>::size()
{
	int c = 0;
	count(root, c);
	return c;
}
