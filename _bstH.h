#ifndef BST_H_
#define BST_H_

#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include<algorithm>

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
class Bst {
    private:
    struct bst_node {
      T      val;
      bst_node *left;
      bst_node *right;

      bst_node ( const T & _val = T{}, bst_node * l = nullptr, bst_node *r = nullptr)
        : val { _val },  left { l }, right {r}
      {
          //cout << " bst_node::bst_node(" << val << ")" << endl;
      }
    };
private:
    bst_node *root;
// member variables
T val; // value stored at this node
Bst* left; // left child of this node
Bst* right; // right child of this node
    // helper function which recursively deallocates nodes
    //   in a tree.
    static void delete_nodes(bst_node *r){
      if(r==nullptr) return;
      delete_nodes(r->left);
      delete_nodes(r->right);
      delete r;
    }


public:

// Constructor. Constructs a BST with one root that holds value x.
// (This data structure does not support empty trees: it must have
// at least one element.)
Bst(const T& x) {
    root = new bst_node(x);
}

// Destructor
~Bst() {
// IMPLEMENT ME
     delete_nodes(root);
}


// Copy constructor
Bst(const Bst& other) {
//   root = new bst_node(other);
 

 
}

// Copy assignment operator
Bst& operator=(const Bst& other) {
// IMPLEMENT ME
 
}

bst_node * _insert(bst_node *r,const T & x, bool &success){
      if(r == nullptr){
        success = true;
        return new bst_node(x, nullptr, nullptr);
      }

      if(r->val == x){
        success = false;
        return r;
      }
      if(x < r->val){
        r->left = _insert(r->left, x, success);
        return r;
      }
      else {
        r->right = _insert(r->right, x, success);
        return r;
      }
    }
// Insert x into the tree. If there is already another entry equal to
// x in the tree, as defined by T's == operator, do nothing to the
// BST and return false. Otherwise return true for successful
// insertion
bool insert(const T& x) {
 bool success;
      root = _insert(root, x, success);
      return success;
}

// Search for x in the tree. If a match is found (as defined by
// T's == operator), return true, and MODIFY x so that it becomes
// a copy of the matched object in the tree. Note that depending
// on how T's operator== is defined, this matched object in the tree
// may not be identical in every class member with x; hence the
// need to return a copy. This overwrites the variable x.
// If a match is not found, return false and do not change x
bool find(T& x) {

}

// overloaded version of the above, does the same except that
// there is no copying to x (x is not changed).
// This is meant to be used when T is a basic data type so cannot
// be passed by non-constant reference
bool find(const T& x) {
    return (find(root, x) != nullptr);
}

bst_node* find(bst_node* t, int x) {
    if(t == NULL)
        return NULL;
    else if(x < t->val)
        return find(t->left, x);
    else if(x > t->val)
        return find(t->right, x);
    else
        return t;
}

// Returns the height of the node with object equal to x in the tree.
// The root is at height 0, its children at height 1, those
// children's own children at height 2 and so on.
// Return -1 if x is not found
int height(const T& x)
{
    int32_t h = 0;
    height(root, x, h);
    return h;
}

void height(bst_node* t, int x, int32_t& h) {
    if(t == nullptr)
    {
        h = -1;
    }
    else if(t->val != x)
    {
        height((t->val > x ? t->left : t->right), x, ++h);
    }
}

// Returns all entries of the tree in a vector, in increasing order.
// Ordering as defined by operator>.
vector<T> toVector() {
  // std::sort(T.begin(), T.end());
 
  // return 0;
// IMPLEMENT ME
}

};

#endif