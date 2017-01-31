/*Write a recursive algorithm to do binary search in a sorted array.

    a. Create an array of 15 sorted numbers.  You may hard code the values in the main function.

    b. Implement the recursive binary search.

    c. run the program to search for a number in the list

    d. run the program to search for a number not in the list.

	e. Create an array of 16 numbers and repeat steps a-d*/

#include<iostream>
using namespace std;
int Binary_sch(int a[],int i, int j,int key);
int main(int argc, char *argv[]) {
	int array1[15] = { 5,7,13,13,50,58,61,89,90,201,201,210,212,240,400 };
	
	int array2[16];
	for (int i = 0; i < 16; i++) {
		if (i != 15) {
			array2[i] = array1[i];
		}
		else {
			array2[i] = 450;
		}
	}
	if ( Binary_sch(array1, 0, 14, 5) != -1) {
		cout << "key 5 is the element array1[" << Binary_sch(array1, 0, 14, 5) << "] " << "in the array" << endl;;
	}
	else {
		cout << "key 5 is not found" << endl;
	}

	if (Binary_sch(array1, 0, 14, 100) != -1) {
		cout << "key 100 is the element array1[" << Binary_sch(array1, 0, 14, 100) << "] " << "in the array" << endl;;
	}
	else {
		cout << "key 100 is not found" << endl;
	}
	
	if (Binary_sch(array2, 0, 15, 450) != -1) {
		cout << "key 450 is the element array1[" << Binary_sch(array2, 0, 15, 450) << "] " << "in the array" << endl;;
	}
	else {
		cout << "key 450 is not found" << endl;
	}
	
	if (Binary_sch(array2, 0, 15, 451) != -1) {
		cout << "key 451 is the element array1[" << Binary_sch(array2, 0, 15, 451) << "] " << "in the array" << endl;;
	}
	else {
		cout << "key 451 is not found" << endl;
	}


}

// recursive version

int Binary_sch(int a[], int i, int j, int key) {
	if (i > j) {
		return -1;
	}
	if (j>=i) {
		if (a[((i+j)/2)] == key) {
			return (i + j) / 2;
		}
		else if (a[(i + j) / 2] > key) {
			return Binary_sch(a,i, (i + j) / 2-1,key);
		}
		else if (a[(i + j) / 2] < key) {
			return Binary_sch(a, (i + j) / 2+1, j,key);
		}
	}

}


//non recursive version
/*
int Binary_sch(int a[], int key, int count) {
	int i = 0;
	int j = count-1;
	int k = 0;
	while (i <= j) {
		k = (int)((i + j) / 2);
		if (a[k] == key) {
			return k;
		}
		else
		{
			if (key > a[k]) {
				i = k + 1;
			}
			if (key < a[k]) {
				j = k - 1;
			}
		}
	}
	return -1;
}
*/