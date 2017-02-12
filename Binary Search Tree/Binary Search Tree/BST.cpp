#include "BST.h"
#include<iostream>

using namespace std;
BSTnode::BSTnode() :lchild(NULL),rchild(NULL),parent(NULL),val(0){}
BSTnode* BST::search(BSTnode* root,int a){
	if (root == NULL) {
		return NULL;
}
	if (root->val == a) {
		return root;
	}
	else if (root->val > a) {
		search(root->lchild, a);
	}
	else {
		search(root->rchild, a);
	}
}

bool BST::insert(BSTnode *rt, int a) {
	if (rt == NULL) {
		rt = new BSTnode;
		rt->val = a;
		//this is critical, I don't remember to write it at first
		BST::root = rt;
		return true;
	}

	else if (a == rt->val) { cout <<"Because "<< a << " has a duplicate, so one more random number is generated to make it 15" << endl; return false; }
	else if (a > rt->val) {
		if (rt->rchild == NULL) {
			rt->rchild = new BSTnode;
			rt->rchild->val = a;
			rt->rchild->parent = rt;
			return true;
		}
		else{
			insert(rt->rchild, a);
		
		}

	}
	else if (a < rt->val) {
		if (rt->lchild == NULL) {
			rt->lchild = new BSTnode;
			rt->lchild->val = a;
			rt->lchild->parent = rt;
			return true;
		}
		else {
			insert(rt->lchild, a);
		}
	}
	
}

void BST::inorder(BSTnode *rt) {
	if (rt!=NULL) {
		inorder(rt->lchild);
		cout << rt->val << endl;
		inorder(rt->rchild);
	}
}

//max() is bound to find the node with
//the max value in the given subtree
BSTnode* BST::max(BSTnode *subtree){
	BSTnode *tmp = subtree;
	while (tmp->rchild != NULL) {
		tmp = tmp->rchild;
	}
	return tmp;

}


//max() is bound to find the node with
//the max value in the given subtree
BSTnode* BST::min(BSTnode *subtree) {
	BSTnode *tmp = subtree;
	while (tmp->lchild != NULL) {
		tmp = tmp->lchild;
	}
	return tmp;
}

void BST::del(int a) {
	BSTnode *tmp = search(root, a);
	if (tmp == NULL) { cout << "Empty tree! "<<endl; return; }
	//condition 1: deletion when the node have no child
	else if (tmp->lchild == NULL && tmp->rchild == NULL) {
		if (tmp->parent->lchild==tmp){
			tmp->parent->lchild = NULL;
		}
		if (tmp->parent->rchild==tmp){
			tmp->parent->rchild = NULL;
		}
		//tmp->parent = NULL;
		//delete(tmp);
	}
	//condition 2:deletion when the node have exactly one child
	//XOR logic implementation
	else if ((tmp->lchild == NULL && tmp->rchild != NULL)||(tmp->lchild != NULL && tmp->rchild == NULL)) {
		//condition 2a:if true, the tmp node only have a right subtree
		if (tmp->lchild == NULL) {
			//a special case for condition 2a:when the disired node is the root itself
			if (tmp == root) {
				root = root->rchild;
				return;
			}
			
			tmp->rchild->parent = tmp->parent;
			//if true: the desired node is the left child of its parent node
			if (tmp->parent->lchild == tmp) {
				tmp->parent->lchild = tmp->rchild;
			}
			//if true: the desired node is the right child of its parent nod
			else if (tmp->parent->rchild == tmp) {
				tmp->parent->rchild = tmp->rchild;
			}
		}
		//condition 2b: if true, the tmp node only have a left subtree
		else if (tmp->rchild == NULL) {
			//a special case for condition 2b:when the disired node is the root itself
			if (tmp == root) {
				root = root->lchild;
				return;
			}

			tmp->lchild->parent = tmp->parent;
			//if true: the desired node is the left child of its parent node
			if (tmp->parent->lchild == tmp) {
				tmp->parent->lchild = tmp->lchild;
			}
			//if true: the desired node is the left child of its parent node
			else if (tmp->parent->rchild == tmp) {
				tmp->parent->rchild = tmp->lchild;
			}
		}
		//tmp->lchild = NULL;
		//tmp->rchild = NULL;
		//tmp->parent = NULL;
		//delete(tmp);
	}
	//condition 3: if true, deletion when the node have two children
	//This implementation will use the successor of the deletion node for replacement
	else if (tmp->lchild != NULL && tmp->rchild != NULL) {
		BSTnode *succ = min(tmp->rchild);
		// condition 3a: a special case, if true, the right child of the deletion node is its successor
		if (succ == tmp->rchild) {
			tmp->val = succ->val;
			tmp->rchild = succ->rchild;
			//This IF wrapping was added after debugging. Don't forget to handle the parent pointer of the successor when it has no right child
			if (succ->rchild != NULL) { succ->rchild->parent = succ->parent; }
			//succ->lchild = NULL;
			//succ->rchild = NULL;
			//succ->parent = NULL;
			//delete(succ);
		}
		//condition 3b: the successor node has no child
		else if ((succ->lchild == NULL) && (succ->rchild == NULL)) {
			tmp->val = succ->val;
			succ->parent->lchild = NULL;
			//succ->parent = NULL;
			//delete(succ);
		}
		//condition 3c: the successor node only has the right child
		else if ((succ->lchild == NULL) && (succ->rchild != NULL)) {
			tmp->val = succ->val;
			succ->parent->lchild = succ->rchild;
			succ->rchild->parent = succ->parent;
			//succ->parent = NULL;
			//succ->lchild = NULL;
			//succ->rchild = NULL;
			//delete(succ);
		}
		cout << "The successor of deletion node is: " << succ->val << endl;

	}
}
BSTnode * BST::rootgetter() {
	return root;
}

BST::BST() :root(NULL){};