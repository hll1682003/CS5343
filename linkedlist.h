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
	void insert(node*, int);
	void del(node*);
	void reverse();
	void traverse();
	void sort();
	node *headgetter();
	~linkedlist();

};