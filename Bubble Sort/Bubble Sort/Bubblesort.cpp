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



		for (int i = 15; i >= 0; i--) {
			for (int j = 0; j < i - 1; j++) {
				if (a[j] > a[j + 1]) {
					tmp = a[j];
					a[j] = a[j + 1];
					a[j + 1] = tmp;
				}

			}
			if (-(i - 16) == 16) {
				cout << "The sorted array is: " << endl;
			}
			else {
				cout << "Pass " << -(i - 16) << ":" << endl;
			}
			for (int k = 0; k < 15; k++) {
				cout << a[k] << " ";
			}
			cout << endl;

		}
		cin.get();
		return 0;
}

int random() {
	return (rand() % 100 + 1);
}
