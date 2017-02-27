#include "heap.h"
#include<time.h>
#include<iostream>
#include<algorithm>
using namespace std;
int random();

void heap::generate() {
	srand((unsigned int)time(NULL));
	
	int temp = random();
	int rep_check;
	heapsize = sizeof(arry) / sizeof(arry[0])-1;
	//arry[0] stores the size of heap
	arry[0] = sizeof(arry) / sizeof(arry[0])-1;
	for (int i = 1; i < (sizeof(arry)/sizeof(arry[1]));i++) {
		rep_check = temp;
		arry[i] = temp;
		temp = random();
		//exclude repetitive numbers
		if (rep_check == temp) { i--; }
		
	}
	

}

void heap::heapify() {
	for (int i = 2; i <= heapsize; i++) {
		for (int j = i; j > 1; j /= 2) {
			if (arry[j] > arry[j / 2]) {
				swap(arry[j], arry[j / 2]);
			}
		}
	}


}

void heap::heapsort() {
	int currentsize = heapsize;
	swap(arry[currentsize], arry[1]);
	currentsize--;
	for (currentsize; currentsize > 0; currentsize--) {
		for (int j = 1; j <= currentsize; j *= 2) {}
	}
}
/*void heap::heapify() {
	int lastparent = (sizeof(arry) / sizeof(arry[0])) / 2-1;
	int quarterparent = lastparent / 2;
	int temp;
	int flag;
	for (lastparent; lastparent >= 1; lastparent--) {
		flag = -1;
		//case one: if both the children nodes are greater than the parent, swap the parent with the bigger one
		if ((arry[lastparent * 2] > arry[lastparent])&&(arry[lastparent*2+1]>arry[lastparent])) {
			if (arry[lastparent * 2] >= arry[lastparent * 2+1]) {
				temp = arry[lastparent * 2];
				arry[lastparent * 2] = arry[lastparent];
				arry[lastparent] = temp;
				flag= lastparent * 2;
			}
			else {
				temp = arry[lastparent * 2 + 1];
				arry[lastparent * 2+1] = arry[lastparent];
				arry[lastparent] = temp;
				flag = lastparent * 2 + 1;
			}

		}
		//case two: if only one of children nodes are greater than the parent, just swap the parent with that node
		else if ((arry[lastparent * 2] > arry[lastparent]) || (arry[lastparent * 2 + 1] > arry[lastparent])) {
			if (arry[lastparent * 2] > arry[lastparent]) {
				temp = arry[lastparent * 2];
				arry[lastparent * 2] = arry[lastparent];
				arry[lastparent] = temp;
				flag = lastparent * 2;
			}
			else {
				temp = arry[lastparent * 2 + 1];
				arry[lastparent * 2 + 1] = arry[lastparent];
				arry[lastparent] = temp;
				flag = lastparent * 2+1;
			}
		}
		while(flag< (sizeof(arry) / sizeof(arry[0])-1)){
			if (max(flag, flag * 2, (flag * 2 + 1)) != flag) {
				swap(arry[flag], arry[max(flag, flag * 2, flag * 2 + 1)]);
			}
			flag *= 2;
		}

	}
	
}*/
void heap::print_heap() {
	for (int i : arry) {
		cout << i<<" ";
	}
	cout << endl;

}

int random() {
	return (rand() % 100 + 1);
}
