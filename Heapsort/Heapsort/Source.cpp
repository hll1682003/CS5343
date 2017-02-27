#include<iostream>
#include"heap.h"
using namespace std;
int main(int argc, char **argv) {
	heap heap1;
	heap1.generate();
	heap1.print_heap();
	heap1.heapify();
	heap1.print_heap();
	heap1.heapsort();
	heap1.print_heap();
	return 0;
}