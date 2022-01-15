#include<stdio.h>
#include<iostream>

using namespace std;

class DynamicArray {

	public:

		int *a; // array;
		int n; // current members
		int size; // allocated size

		DynamicArray() {
			this->a = new int[this->size];
			this->n = 0;
			this->size = 1;
		}

		int get_length() {
			return this->n;
		}

		int get_size() {
			return this->size;
		}

		int at(int i) {
			if (i > this->n) {
				throw out_of_range("Index out of range!");
			}
			return *(this->a + i);
		}

		void set_at(int i, int x) {
			if (i > this->n) {
				throw out_of_range("Index out of range!");
			}
			*(this->a + i) = x;
		}

		void append(int x) {
			if (this->n >= this->size) {
				int *b = new int[this->size * 2];
				for (int i; i<this->size; i++) {
					b[i] = this->at(i);
				}
				this->a = b;
				this->size *= 2;
			}
			this->set_at(this->n, x);
			this->n++;
		}	

};

int main(void) {

	DynamicArray arr;
	cout << "n = " << arr.get_length() << ", size = " << arr.get_size() << endl;

	for (int i=0; i<10; i++) {
		arr.append(i);
		cout << "n = " << arr.get_length() << ", size = " << arr.get_size() << endl;
	}

	cout << "\narr = [";
	for (int i=0; i<arr.get_length(); i++) {
		cout << arr.at(i) << ",";
	}
	cout << "]" << endl;

	return 0;
}

