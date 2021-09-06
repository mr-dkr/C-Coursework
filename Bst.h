#ifndef BST_H_
#define BST_H_

#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;
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
class Bst
{
private:
	// helper struct node is created
	struct BstNode
	{
		T val;
		BstNode *left;
		BstNode *right;

		BstNode(const T &tVal = T{}, BstNode *lt = nullptr, BstNode *rt = nullptr) : val{tVal}, left{lt}, right{rt} {}
	};

private:
	// member variables
	T val;		// value stored at this node
	Bst *left;	// left child of this node
	Bst *right; // right child of this node
	BstNode *root;

public:
	// Constructor. Constructs a BST with one root that holds value x.
	// (This data structure does not support empty trees: it must have
	// at least one element.)
	Bst(const T &x)
	{
		// New node created and value x set into the root node.
		root = new BstNode(x);
	}

	// Destructor
	~Bst()
	{
		// IMPLEMENT ME
		delete root;
		delete left;
		delete right;
	}

	// Copy constructor
	Bst(const Bst &other)
	{
		// IMPLEMENT ME
		root = copyConstructorHelper(other.root);
	}

	BstNode *copyConstructorHelper(const BstNode *other)
	{
		if (other == NULL)
			return NULL;
		BstNode *copyNode = new BstNode;
		copyNode->val = other->val;
		copyNode->left = copyConstructorHelper(other->left);
		copyNode->right = copyConstructorHelper(other->right);
		return copyNode;
	}
	// Copy assignment operator
	Bst &operator=(const Bst &other)
	{

		// IMPLEMENT ME
		if (this != &other)
		{
			makeEmpty(root);
			root = operatorHelper(other.root);
		}
		return *this;
	}

	BstNode *operatorHelper(BstNode *rootNode)
	{
		if (rootNode == NULL)
			return NULL;

		return new BstNode(rootNode->val, operatorHelper(rootNode->left), operatorHelper(rootNode->right));
	}

	//delete all the nodes in the tree and tree will become empty
	void makeEmpty(BstNode *rootNode)
	{
		if (rootNode == nullptr)
			return;
		makeEmpty(rootNode->left);
		makeEmpty(rootNode->right);
		delete rootNode;
	}

	// Checks rootNode, if it is empty then it will return true and creates a new node.
	BstNode *insertHelper(BstNode *rootNode, const T &x, bool &result)
	{
		if (rootNode == nullptr)
		{
			result = true;
			return new BstNode(x, nullptr, nullptr);
		}
	// If the rootNode is equivalent to the value then it return false
		if (rootNode->val == x)
		{
			result = false;
			return rootNode;
		}
		//If the value x is smaller than the rootNode then it pushes left.
		if (x < rootNode->val)
		{
			rootNode->left = insertHelper(rootNode->left, x, result);
			return rootNode;
		}
		// If the value x is greater than the rootNode then it pushed right.
		else 
		{
			rootNode->right = insertHelper(rootNode->right, x, result);
			return rootNode;
		}
	}
	// Insert x into the tree. If there is already another entry equal to
	// x in the tree, as defined by T's == operator, do nothing to the
	// BST and return false. Otherwise return true for successful
	// insertion
	bool insert(const T &x)
	{
		bool result;
		root = insertHelper(root, x, result);
		return result;
	}

	// Search for x in the tree. If a match is found (as defined by
	// T's == operator), return true, and MODIFY x so that it becomes
	// a copy of the matched object in the tree. Note that depending
	// on how T's operator== is defined, this matched object in the tree
	// may not be identical in every class member with x; hence the
	// need to return a copy. This overwrites the variable x.
	// If a match is not found, return false and do not change x
	bool find(T &x)
	{
		// IMPLEMENT ME
	}

	// overloaded version of the above, does the same except that
	// there is no copying to x (x is not changed).
	// This is meant to be used when T is a basic data type so cannot
	// be passed by non-constant reference
	bool find(const T &x)
	{
		return (findHelper(root, x) != nullptr);
	}

	BstNode *findHelper(BstNode *rootNode, int x)
	{
		if (rootNode == NULL)
			return NULL;
		else if (x < rootNode->val)
			return findHelper(rootNode->left, x);
		else if (x > rootNode->val)
			return findHelper(rootNode->right, x);
		else
			return rootNode;
	}

	// Returns the height of the node with object equal to x in the tree.
	// The root is at height 0, its children at height 1, those
	// children's own children at height 2 and so on.
	// Return -1 if x is not found
	int height(const T &x)
	{
		int h = 0;
		heightHelper(root, x, h);
		return h;
	}

	void heightHelper(BstNode *rootNode, int x, T &h)
	{
		//checks for rootNode if it is empty it return -1
		if (rootNode == nullptr)
		{
			h = -1;
		}
		else if (rootNode->val != x)
		{
			heightHelper((rootNode->val > x ? rootNode->left : rootNode->right), x, ++h);
		}
	}

	// Returns all entries of the tree in a vector, in increasing order.
	// Ordering as defined by operator>.
	vector<T> toVector()
	{
		// IMPLEMENT ME
		return inorderTraversal(root);
	}

	vector<int> inorderTraversal(BstNode *rootNode)
	{
		vector<int> r;
		if (rootNode == NULL)
		{
			return r;
		}
		vector<int> x;
		if (rootNode->left != NULL)
		{
			x = inorderTraversal(rootNode->left);
			r.insert(r.end(), x.begin(), x.end());
		}
		r.push_back(rootNode->val);
		if (rootNode->right != NULL)
		{
			x = inorderTraversal(rootNode->right);
			r.insert(r.end(), x.begin(), x.end());
		}
		return r;
	}
};

#endif