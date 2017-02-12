#pragma once
struct BSTnode {
	BSTnode();
	int val;
	BSTnode *lchild;
	BSTnode *rchild;
	BSTnode *parent;
};

class BST {
private:
	BSTnode *root;
public:
	BST();
	bool insert(BSTnode*,int);
	
	void inorder(BSTnode*);
	BSTnode* search(BSTnode*,int);
	void del(int);
	BSTnode* rootgetter();
	BSTnode* min(BSTnode*);
	BSTnode* max(BSTnode*);
};