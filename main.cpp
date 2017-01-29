#include<iostream>
#include"linkedlist.h"
#include<time.h>
int random();
int main(int argc, char *argv[]) {
	srand(time(NULL));
	linkedlist list1;
	node *gen=NULL;
	//node *tmp = gen;
	//node *tmp1 = NULL;
	for (int i = 1; i <= 10; i++) {
		gen = new node;
		gen->val = random();
		list1.insert(gen, i);
		
	}
	list1.traverse();
	list1.reverse();
	list1.traverse();
	list1.del(gen);
	/*for (int i = 1; i <10; i++) {
		tmp1 = tmp->next;
		list1.del(tmp);
		tmp = tmp1;
	*/
}


int random() {
	
	return (rand() % 100 + 1);
}