#include <time.h>
#include <iostream>
using namespace std;
int random();

int main(int argc, char **argv) {
	srand((unsigned int)time(NULL));
	int a[15];
	int tmp;
	cout << "the unsorted array is displayed below:" << endl;
	for (int i = 0; i < 15; i++) {
		tmp = random();
		a[i] = tmp;
		cout << tmp << " ";
	}
	cout << endl;
	bool swap = true;
	int j = 0;
	int temp = 0;
	while (swap) {
		swap = false;
		j++;
		for (int k = 0; k < 15 - j; k++) {
			if (a[k+1] < a[k]) {
				temp = a[k];
				a[k] = a[k + 1];
				a[k + 1] = temp;
				swap = true;
			}
		}
		cout << "This is the " << j << "th pass:" << endl;
		for (int l : a) {
			cout << l<<" ";
		}
		cout << endl;
	}
	cout << "done." << endl;


		
		cin.get();
		return 0;
}

int random() {
	return (rand() % 100 + 1);
}
