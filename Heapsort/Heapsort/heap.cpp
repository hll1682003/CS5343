#include <iostream>
#include<time.h>
#include<algorithm>
using namespace std;
int random() {
	return (rand() % 100 + 1);
}

//compare one node with its two children, if any of its children is larger than it, swap them
//and recursively call this function to see if the modified heap stil meet the heap property
void percolatedown(int a[], int arraysize, int node) {
	int largest = node;
	//the first element is saved in position 1, so the lchild is simply node*2, rchild is lchild+1
	int lchild = node * 2;
	int rchild = lchild + 1;
	if (lchild <= arraysize&&a[largest] < a[lchild]) {
		largest = lchild;
	}
	if (rchild <= arraysize && a[largest] < a[rchild]) {
		largest = rchild;
	}
	if (largest != node) {
		swap(a[largest], a[node]);
		//recursive call
		percolatedown(a, arraysize, largest);
	}
}
//to print the whole heap
void heapprint(int a[], int size) {
	for (int i = 1; i <= size; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}
void heapsort(int a[], int size) {
	//heapify algorithm is implemented in the first for-loop
	//start with size/2 because the percolatedown() function is comparing a parent with its two children
	//and we need to start from the last internal node in the heap i.e. a[size/2]
	for (int i = size / 2; i >= 1; i--) {
		percolatedown(a, size, i);
	}
	cout << "Here's heapified heap: " << endl;
	heapprint(a, size);

	for (int j = size; j > 0; j--) {
		swap(a[1], a[j]);
		percolatedown(a, j - 1, 1);
	}

}



int main() {
	int arr[16];
	//record the heap size in arr[0]
	arr[0] = sizeof(arr) / sizeof(arr[0]) - 1;
	srand((unsigned int)time(NULL));
	for (int i = 1; i <= arr[0]; i++) {
		arr[i] = random();
	}
	cout << "The original array is: " << endl;
	heapprint(arr, arr[0]);
	heapsort(arr, arr[0]);
	cout << "The sorted heap is: " << endl;
	heapprint(arr, arr[0]);
}