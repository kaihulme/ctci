#include <stdio.h>
#include <iostream>

using namespace std;


class Node {
	
	public:
	
		Node* next;
		int data;
	
		Node(int x) {
			this->data = x;
		}		

};


int main() {

	Node linked_list = Node(5);

    cout << linked_list.data << endl;

	return 0;
}
