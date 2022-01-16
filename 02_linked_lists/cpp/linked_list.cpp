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
			Node* cur_node = this;

			while (cur_node->next != NULL) {
				cur_node = cur_node->next;
			}

			cur_node->next = new_node;

		}
			
};


int main() {

	Node* linked_list = new Node(0);

	int n=10;
	for (int i=1; i<n; i++) {
		linked_list->append(i);
	}

	Node* node = linked_list;
	for (int i=0; i<n; i++) {
    	cout << node->data << endl;
		if (node->next != NULL) {
			node = node->next;
		}
	}

	return 0;
}
