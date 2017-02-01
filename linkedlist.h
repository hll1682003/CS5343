#pragma once
#include <iostream>
using namespace std;

struct node {
	int val;
	node *next;
};

class linkedlist {
private:
	node *head;
	int listlen;

public:
	linkedlist();
	void append(node*);
	void del(node*);
	void reverse();
	void traverse();
	void swap(node *a, node *b);
	void sort();
	node *headgetter();
	~linkedlist();

};