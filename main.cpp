#include<iostream>
#include"linkedlist.h"
#include<time.h>
int random();
int main(int argc, char *argv[]) {
	
	srand((unsigned int)time(NULL));
	linkedlist list1;
	node *tmp, *tmp1 = NULL;
	int num[10] = {3,4,3,1,4,7,1,4,8,7};
	for (int i = 1; i <= 10; i++) {
		tmp = new node;
		tmp->val = num[i-1];
		//tmp->val = random();
		list1.insert(tmp, i);

	}
	//list1.traverse();
	//list1.reverse();
	list1.traverse();
	list1.sort();
	list1.traverse();
	//list1.traverse();

	/*
	tmp = list1.headgetter();
	for (int i = 1; i <= 10; i++) {
		tmp1 = tmp->next;
		list1.del(tmp);
		tmp = tmp1;
	}
	list1.traverse();
	*/

}

int random() {
	
	return (rand() % 10 + 1);
}