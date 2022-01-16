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
			while (curr_node->next != NULL) curr_node = curr_node->next;
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

		void remove_head() {
			Node* next_node = this->next;
			this->data = next_node->data;
			this->next = next_node->next;
			delete(next_node);
		}

		void remove_at(int idx) {
			if (idx == 0) {
				if (this->next != NULL) this->remove_head();
				else throw invalid_argument("Cannot remove head if there are no other nodes in the list!");
			}
			Node* curr_node = this;
			Node* prev_node;
			for (int i=0; i<idx; i++) {
				if (curr_node->next != NULL) {
					prev_node = curr_node;
					curr_node = curr_node->next;
				}
				else if (i == idx) this->remove_tail();
				else throw out_of_range("Index out of range for linked list!");
			}
			prev_node->next = curr_node->next;
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
	// create head node
	Node* linked_list = new Node(0);
	// append items to reach list of length 10
	int n=10;
	for (int i=1; i<n; i++) {
		linked_list->append(i);
	}
	linked_list->print();
	// remove tail node
	linked_list->remove_tail();
	linked_list->print();
	// remove head node
	linked_list->remove_head();
	linked_list->print();
	// remove node at index 3
	linked_list->remove_at(3);
	linked_list->print();

	return 0;
}
