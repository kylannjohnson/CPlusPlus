#include <iostream>
#include <climits>
using namespace std;

struct Node {
	int value;
    Node * left;
    Node * right;
};

void inOrder(struct Node ** root) {	

	Node *current = *root;

	if(!current) {
		cout << " | ";
		return;
	}

	if(current->left) {
		inOrder(&(current->left));
	}

	cout << current->value << " ";
	  
	if(current->right) {
		inOrder(&(current->right));
	}

}

Node* makeNode(int value) {

 	Node * node = new Node;
 	node->value = value;
 	node->left = NULL;
 	node->right = NULL;

 	 // cout << "-- " << node << endl;

 	return node;
}

void insert(Node** node, int value) {

	// cout << "-- " << value << endl;

	Node *current = *node;

	if(!current) {
		// cout << "LEAF" << endl;
	 	*node = makeNode(value);
	 	return;
	 }

	 if(value > current->value) {
	 	// cout << "insert right" << endl;
	 	insert(&(*node)->right, value);
	 }
	else {
		// cout << "insert left" << endl;
	 	insert(&(*node)->left, value);
	 }
	 
}

int findMin(Node **node, int currentMin) {

	Node *current = *node;
	if(current == NULL) {
		return currentMin;
	}

	if(current->value < currentMin) {
		return findMin(&(current->left), current->value);
	}

	return currentMin;	
}

void remove(Node **node, Node *parent, int targetValue) {

	Node *current = *node;

	if(!current) {
		cout << "NULL" << endl;
		return;
	}

	cout << "observing " << current->value << " for " << targetValue << endl;

	// You shall not pass
	if(current->value == targetValue) {

		cout << "FOUND IT" << endl;

		if(!current->left && !current->right) {
			if(parent->left && (parent->left->value == current->value)) {
				cout << "kill left" << endl;
				delete parent->left;
				parent->left = NULL;
			} else {
				cout << "kill right" << endl;
				delete parent->right;
				parent->right = NULL;
			}
		}

		else if(current->left && !current->right) {
			cout << "delete left " << current->left->value << endl;

			*current = *(current->left);
		}
	  
		else if(current->right && !current->left) {
			cout << "delete right " << current->right->value << endl;
						
			*current = *(current->right);
		}
		else {
			int minRight = findMin(&(current->right), INT_MAX);

			cout << "Min is " << minRight << endl;

			current->value = minRight;

			remove(&(current->right), current, minRight);
		}	
	} 
	else if(targetValue < current->value) {
		cout << "go left" << endl;
		remove(&(current->left), current, targetValue);
	}
	else {
		cout << "go right" << endl;
		remove(&(current->right), current, targetValue);
	}

	return;
}

int main ()
{
  
  Node * tree = NULL;

  insert(&tree, 12);
  insert(&tree, 7);
  insert(&tree, 15);
  insert(&tree, 6);
  insert(&tree, 17);
  insert(&tree, 13);
  insert(&tree, 34);
  insert(&tree, 1);
  insert(&tree, 89);
  insert(&tree, 5);
  insert(&tree, 43);

	inOrder(&tree);  
	cout << endl;

	remove(&tree, NULL, 43);
	inOrder(&tree);

	cout << endl << "_____" << endl;

	remove(&tree, NULL, 89);

   cout << endl;
   inOrder(&tree);
  
  return 0;
}