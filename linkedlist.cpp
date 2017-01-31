/*1. Implement selection sort on a single linked list. 

   a. Create  a single  linked list of 10 numbers in random order.

   b. Traverse the list and show the node values.

   c. Sort the linked list.  Sort it so that you exchange the nodes and not just the values.

   d. Traverse the list again to show the values in sorted order.*/
#include "linkedlist.h"
#include <iostream>

linkedlist::linkedlist() { 
	listlen = 0;
	head = NULL;
}

void linkedlist::insert(node *input, int pos){
	if ((pos<1) || (pos>(listlen + 1))) {
		cout << "Out of range!" << endl;
		return;
	}

	if (head== NULL) {
		if (pos == 1) {
			head = input;
			input->next = NULL;
			listlen++;
			return;
		}
		
}
	if (pos == listlen + 1) {
		node *tmp = head;
		while (tmp->next) {
			tmp = tmp->next;
		}
		tmp->next = input;
		input->next = NULL;
		listlen++;
		return;
	}

	
	

	node *tmp = head;
	for (int i = 1; i < pos; i++) {
		tmp = tmp->next;
	}
	input->next=tmp->next;
	tmp->next = input;
	listlen++;

}

void linkedlist::del(node *input) {
	node *tmp = head;
	if (head = input) {
		head = input->next;
	}
	else {
		while (tmp) {
			tmp = tmp->next;
		}
		tmp->next = input->next;
	}
		input->next = NULL;
		delete input;
		listlen--;
}

void linkedlist::traverse() {
	if (head== NULL) {
		cout << "the list is empty" << endl;
		return;
	}
	node *tmp = head;
	int count = 0;

	//I wrote before the while loop condition as (tmp->next), 
	//leading to one output less
	while (tmp) {
		cout << "node" << " " << count+1 << ": " << tmp->val << endl;
		tmp = tmp->next;
		count++;
	}
	cout << "There're " << listlen << " nodes in this list" << endl << endl;

}

linkedlist::~linkedlist() {
	delete head;
}

void linkedlist::reverse() {
	node *tmp1 = head;
	node *tmp2 = tmp1->next;
	node *tmp3 = tmp2->next;
	tmp1->next = NULL;
	tmp2->next = tmp1;
	while (tmp3) {
		tmp1 = tmp2;
		tmp2 = tmp3;
		tmp3 = tmp3->next;
		tmp2->next = tmp1;
	}
	
	//previously wrong as head = tmp1;
	head = tmp2;
	cout << "Now the list is reversed: " << endl;
}

node *linkedlist::headgetter() {
	return head;
}
void linkedlist::sort() {

	node* i = head;
	node* j = head->next;
	node* tmp;
	int valbuf;
	node* swapbuf = NULL;
	while (i) {
		node *i_before=head;
		node *i_after=head;
		node *tmp_before = head;
		tmp = i;
		valbuf = tmp->val;
		j = i->next;
		while (j) {

			if (valbuf>j->val) {
				tmp = j;
				valbuf = j ->val;
			}
			j=j->next;
		}
		//do the swap
		if (tmp == i) {
			i = i->next;
		}
		else {
			if (i == head) {
				head = tmp;
				while (tmp_before->next != tmp) {
					tmp_before = tmp_before->next;
				}
				tmp_before->next = i;
				i->next = tmp->next;
				tmp->next = i;

			}
			else {
				while (i_before->next != i) {
					i_before = i_before->next;
				}
				i_after = i->next;
				while (tmp_before->next != tmp) {
					tmp_before = tmp_before->next;
				}
				i_before->next = tmp;
				tmp_before->next = i;
				i->next = tmp->next;
				tmp->next = i_after;
				swapbuf = i;
				i = tmp;
				tmp = swapbuf;
				i = i->next;
				

			}
		}
	}
	
}//function ends