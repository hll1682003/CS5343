#pragma once

struct heap {
public:	//a heap implemented with array, the first element is used to store the heap size(15)
	int arry[16];
	int heapsize;
	void generate();
	void heapify();
	void heapsort();
	void print_heap();
	int max(int, int, int);

};
