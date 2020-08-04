#ifndef BST_H_
#define BST_H_

#include <vector>
using std::vector;

// This class implement the BST data structure.
// It stores objects of type T (a templated parameter) in a tree structure.
// Each node of the tree has two pointers, to its left and right child
// respectively, which are (recursively) also BSTs; thus they are also
// called the left and right subtrees.
// It is assumed the class (or type) T supports the == and > operators,
// in addition to the usual default constructor, assignment operator etc.
template <typename T>
class Bst {
private:
	// member variables
	T val; // value stored at this node
	Bst* left; // left child of this node
	Bst* right; // right child of this node

public:
	// Constructor. Constructs a BST with one root that holds value x.
	// (This data structure does not support empty trees: it must have
	// at least one element.)
	Bst(const T& x) {
		// IMPLEMENT ME
	}

	// Destructor
	~Bst() {
		// IMPLEMENT ME
	}


	// Copy constructor
	Bst(const Bst& other) {
		// IMPLEMENT ME
	}

	// Copy assignment operator
	Bst& operator=(const Bst& other) {
		// IMPLEMENT ME
	}

	// Insert x into the tree. If there is already another entry equal to
	// x in the tree, as defined by T's == operator, do nothing to the
	// BST and return false. Otherwise return true for successful
	// insertion
	bool insert(const T& x) {
		// IMPLEMENT ME
	}

	// Search for x in the tree. If a match is found (as defined by
	// T's == operator), return true, and MODIFY x so that it becomes
	// a copy of the matched object in the tree. Note that depending
	// on how T's operator== is defined, this matched object in the tree
	// may not be identical in every class member with x; hence the
	// need to return a copy. This overwrites the variable x.
	// If a match is not found, return false and do not change x
	bool find(T& x) {
		// IMPLEMENT ME
	}

	// overloaded version of the above, does the same except that
	// there is no copying to x (x is not changed).
	// This is meant to be used when T is a basic data type so cannot
	// be passed by non-constant reference
	bool find(const T& x) {
		// IMPLEMENT ME

	}

	// Returns the height of the node with object equal to x in the tree.
	// The root is at height 0, its children at height 1, those
	// children's own children at height 2 and so on.
	// Return -1 if x is not found
	int height(const T& x) {
		// IMPLEMENT ME
	}

	// Returns all entries of the tree in a vector, in increasing order.
	// Ordering as defined by operator>.
	vector<T> toVector() {
		// IMPLEMENT ME
	}

};

#endif
