#include <iostream>
#include <vector>
using namespace std;


struct Node {
	int value;
	Node *next;
};

Node* makeNode(int value) {
	Node *node = new Node;
	node->value = value;
	node->next = NULL;

	return node;
}

void add(Node **head, int value) {
	Node *current = *head;

	while(current->next) {
		current = current->next;
	}

	Node * newNode = new Node;
	newNode->value = value;
	newNode->next = NULL;

	current->next = newNode;
}

bool hasCyle(Node* head) {

	Node *ptr = head;
	Node *fastPtr = head;


	do {
		cout << "slow: " << ptr->value << " " << "fast: " << fastPtr->value << endl;
		if(!fastPtr->next || !fastPtr->next->next) {
			cout << "END" << endl;
			return false;  // the end
		}

		ptr = ptr->next;
		fastPtr = fastPtr->next->next;

	} while(ptr != fastPtr);

	return true;
}

Node* reverse(Node* head) {

	if(!head) {
		return head;
	}

	Node *headPtr = head->next;
	Node *newHead = makeNode(-1);

	while(headPtr) {

		// Save the pointers to the next list members
		Node * nextNode = headPtr->next;
		Node * newHeadNext = newHead->next;

		newHead->next = headPtr;
		head->next = headPtr->next;		

		newHead->next->next = newHeadNext;

		headPtr = nextNode;
	}

	return newHead;

}


// ========================================
void print(Node* head) {
	cout << endl;
	Node *node = head;
	 while(node) {
	 	cout << node->value << " ";

	 	node = node->next;
	 }

	 cout << endl;
}

int main() {

	Node *head = makeNode(-1);

	add(&head, 6);
	add(&head, 1);
	add(&head, 8);
	add(&head, 2);
	add(&head, 22);
	add(&head, 12);

	// print(head);

	head = reverse(head);

	// print(head);

	head = reverse(head);

	// print(head);


	Node *cycle = makeNode(-1);
	Node *node1 = makeNode(1);
	Node *node2 = makeNode(2);
	Node *node3 = makeNode(3);
	Node *node4 = makeNode(4);

	cycle->next = node1;
	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = NULL;  //cycle

	if(hasCyle(cycle))
		cout << "CYCLE!" << endl;
	else
		cout << "No cycle" << endl;

	return 0;
}