#include"BST.h"
#include<time.h>
#include<iostream>
using namespace std;
int random();
void nonleafsuccdel(BST &a, BSTnode *b);
int main(int argc, char **argv) {	
	srand((unsigned int)time(NULL));
	BST tree1;
	int searchitem=0;
	cout << "Now insert 15 random intergers between 1 and 100: " << endl;
	
	for (int i = 0; i < 15; i++) {
		int tmp = random();
		if (i == (rand() % 15)) { searchitem = tmp; }
		cout << tmp << endl;
		if (tree1.insert(tree1.rootgetter(), tmp) == false) {
			i--;
		}
	}

	
	//debug example here
	/*int debug[] = {91,92,48,66,38,45,75,6,34,24,60,90,8,53,96};
	for (int i = 0; i < 15; i++) {
		tree1.insert(tree1.rootgetter(), debug[i]);
		searchitem = debug[i - 2];
	}*/
	
	
	cout <<endl<< "this is inorder traverse of the BST:" << endl;
	tree1.inorder(tree1.rootgetter());
	BSTnode *tmp;
	tmp=tree1.search(tree1.rootgetter(),searchitem);
	cout << "a random search item is: " << searchitem << endl<<endl;
	if (tmp != NULL) {
		cout << "the search result: " << tmp->val << endl << endl;
	}
	else {
		cout << "can't find it"<<endl;
	}
	tmp = tree1.max(tree1.rootgetter());
	cout << "now a leaf node whose value is " << tmp->val << " is to be deleted " << endl;
	tree1.del(tmp->val);
	cout << "Now show the inorder traverse of the BST after deletion" << endl;
	tree1.inorder(tree1.rootgetter());
	
	cout << "Now the root node ("<< tree1.rootgetter()->val<< ") is to be deleted (which means non-leaf)";
	cout<<"and it will be replaced by its successor."<<"" << endl;
	cout << "Now show the inorder traverse of the BST after deletion" << endl;
	tree1.del(tree1.rootgetter()->val);
	tree1.inorder(tree1.rootgetter());

	
	

	//find a non-leaf node of which the successor is not leaf to delete
	nonleafsuccdel(tree1, tree1.min(tree1.rootgetter()));
	
	cout << "Now show the inorder traverse of the BST after deletion" << endl;
	tree1.inorder(tree1.rootgetter());
	cin.get();
	return 0;
}

int random() {
	return (rand() % 100 + 1);
}

void nonleafsuccdel(BST &a, BSTnode *b) {
	if (b == NULL) { cout << "failed!" << endl; return; }
	if (a.max(a.rootgetter())->parent->parent != NULL) {
		cout << endl << "Now the node (" << a.max(a.rootgetter())->parent->parent->val << ") is to be deleted ";
		cout << " and it will be replaced by its successor ("<< a.max(a.rootgetter())->parent->val <<")(non-leaf)." << endl;
		a.del(a.max(a.rootgetter())->parent->parent->val);
		return;
	}
	else {
		if (b->parent->rchild->lchild == NULL ||b->parent->rchild->rchild != NULL) {
			cout << endl << "Now the node (" << b->parent->val << ") is to be deleted ";
			cout << " and it will be replaced by its successor (" << b->parent->rchild->val << ")(non-leaf)." << endl;
			a.del(b->parent->val);
			return;
		}
		else {
			nonleafsuccdel(a, b->parent);
		}
	}
}