#include"BST.h"
#include<time.h>
#include<iostream>
using namespace std;
int random();
int main(int argc, char **argv) {	
	srand((unsigned int)time(NULL));
	BST tree1;
	int searchitem;
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
	cout <<"the search result: "<< tmp->val<< endl<<endl;
	tmp = tree1.max(tree1.rootgetter());
	cout << "now a leaf node whose value is " << tmp->val << " is to be deleted " << endl;
	tree1.del(tmp->val);
	cout << "Now show the inorder traverse of the BST after deletion" << endl;
	tree1.inorder(tree1.rootgetter());
	
	cout << endl << "Now the root node ("<< tree1.rootgetter()->val<< ") is to be deleted ( which means non-leaf)";
	cout<<"and it will be replaced by its successor."<<"" << endl;
	cout << "Now show the inorder traverse of the BST after deletion" << endl;
	tree1.del(tree1.rootgetter()->val);
	tree1.inorder(tree1.rootgetter());

	cout << endl << "Now the root node (" << tree1.rootgetter()->val << ") is to be deleted again";
	cout << " and it will be replaced by its successor."<< endl;
	cout << "Now show the inorder traverse of the BST after deletion" << endl;
	tree1.del(tree1.rootgetter()->val);
	tree1.inorder(tree1.rootgetter());

}

int random() {
	return (rand() % 100 + 1);
}