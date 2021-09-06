#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include "Bst.h"

using namespace std;

// This program is an illustration of how the Bst class can be used.
// It is not meant to be a thorough test suite.
// This file is not part of the submission and you do not need to write
// anything here.
int main() {

	// create a tree with a few integers
	Bst<int> tree(3);
	tree.insert(1);
	tree.insert(2);
	tree.insert(4);
	tree.insert(5);

	cout << std::boolalpha;
	cout << tree.find(1) << endl;
	cout << tree.find(0) << endl;

	cout << tree.height(1) << endl;
	cout << tree.height(2) << endl;
	cout << tree.height(3) << endl;
	cout << tree.height(4) << endl;
	cout << tree.height(5) << endl;
	cout << tree.height(6) << endl;

	vector<int> v = tree.toVector();
	for(int i : v) cout << i << " ";
	cout << endl;

	// copy con
	Bst<int> tree2(tree);
	v = tree2.toVector();
	for(int i : v) cout << i << " ";
	cout << endl;

	// copy asg
	Bst<int> tree3(0);
	tree3 = tree;
	v = tree3.toVector();
	for(int i : v) cout << i << " ";
	cout << endl;

	// create another tree of a more complex type
	Bst<pair<int,string>> tree4({1,"one"});
	pair<int,string> q(2,"two");
	tree4.insert(q);
	cout << tree4.find(q) << endl;
	cout << q.first << " " << q.second << endl;

}
