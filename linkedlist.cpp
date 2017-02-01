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

void linkedlist::append(node *input){
	if (head== NULL) {
			head = input;
			input->next = NULL;
			listlen++;
			return;
		
}
	else{
		node*tmp = head;
		input->next = NULL;
		while (tmp->next) {
			tmp = tmp->next;
		}
		tmp->next = input;
		listlen++;
		return;
	}


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
	node *traverse_ = head;
	node *default_;
	node *min;
	node *compare;
	while (traverse_ != NULL) {
		default_ = traverse_;
		//The minimal node is always set to traverse_ at first
		min = default_;
		compare = default_->next;
		while (compare != NULL) {
			if (min->val > compare->val) {
				min = compare;
			}
			compare = compare->next;
		}

		swap(default_, min);
		traverse_ = min->next;
	
	}
	cout << "Now the list has been sorted." << endl;
}//function ends

void linkedlist::swap(node *a, node *b) {
		//Do not save a->next instead
		node *b_next = b->next;
		node *a_before = head;
		node *b_before = head;
		while (b_before->next != b) {
			b_before = b_before->next;
		}
		if (a != head&&b != head) {
			while (a_before->next != a) {
				a_before = a_before->next;
			}
			
			a_before->next = b;
			b_before->next = a;
			b->next = a->next;
			a->next = b_next;
		}
		else if (a == head&&b != head) {
			b_before->next = a;
			b->next = a->next;
			a->next = b_next;
			head = b;
		}
	
}
