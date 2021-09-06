	// Copy constructor
	Bst(const Bst& other) {
		// IMPLEMENT ME
		this->root = NULL;
		// *this 
	}

	// Copy assignment operator
	Bst& operator=(const Bst& other) {
		
		// IMPLEMENT ME
		// if(this!= &other){
		// 	delete root;
		// 	root= operatorHelper(other.root);
		// }
		// return *this;
	}

	Bst* operatorHelper(Bst *t) {
		// if(t==NULL)
		// 	return NULL;

		// return new BstNode(t->val,operatorHelper(t->left),operatorHelper(t->right));
	}