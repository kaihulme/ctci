#include <stdio.h>
#include <iostream>

using namespace std;


class Node {
	
	public:
	
		Node* next;
		int data;
	
		Node(int x) {
			this->next = NULL;
			this->data = x;
		}

		void append(int x) {
			Node* new_node = new Node(x);
			Node* curr_node = this;
			while (curr_node->next != NULL) {
				curr_node = curr_node->next;
			}
			curr_node->next = new_node;
		}
			
		void remove_tail() {
			Node* curr_node = this;
			Node* prev_node;
			while (curr_node->next != NULL) {
				prev_node = curr_node;
				curr_node = curr_node->next;
			}
			prev_node->next = NULL;
			delete(curr_node);
		}

		void print() {
			Node* curr_node = this;
			while (curr_node->next != NULL) {
				cout << "[" << curr_node->data << "] -> ";
				curr_node = curr_node->next;
			}
			cout << "[" << curr_node->data << "] -> NULL;" << endl;
		}

};


int main() {

	Node* linked_list = new Node(0);

	int n=10;
	for (int i=1; i<n; i++) {
		linked_list->append(i);
	}

	linked_list->print();

	linked_list->remove_tail();

	linked_list->print();

	return 0;
}
