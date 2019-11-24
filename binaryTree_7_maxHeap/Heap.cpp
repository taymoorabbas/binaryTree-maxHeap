#include"Classes.h"
#include<queue>
#include<iostream>
using namespace std;

//public functions

Heap::Heap() {

	this->root = nullptr;
	this->last = nullptr;
}

void Heap::insert(int data) {

	Node *newNode = new Node;
	newNode->data = data;
	newNode->left = nullptr;
	newNode->right = nullptr;

	if (!this->root) {

		newNode->parent = nullptr;
		this->root = newNode;
	}

	else {

		queue<Node*> q;
		bool inserted = false;
		Node *current;

		q.push(this->root);

		while (!inserted) {

			current = q.front();
			q.pop();

			if (!current->left) {

				current->left = newNode;
				newNode->parent = current;
				inserted = true;
			}

			else if (!current->right) {

				current->right = newNode;
				newNode->parent = current;
				inserted = true;
			}

			else {

				q.push(current->left);
				q.push(current->right);
			}
		}

		this->last = newNode;
		percolateUp(newNode);
	}
}

void Heap::remove() {
	
	if (!this->root) {

		cout << "ERROR: Nothing to delete" << endl;
	}

	else {

		int data = this->root->data;
		this->root->data = this->last->data;

		Node *del = this->last;

		if (this->last->parent->right == this->last) {

			this->last->parent->right = nullptr;
			this->last = this->last->parent->left;
		}

		else {

			this->last->parent->left = nullptr;
			this->adjustLast();
		}

		delete del;
		cout << "Data \'" << data << "\' deleted from HEAP" << endl;
		this->percolateDown(this->root);
	}
}

void Heap::search(int data) {

	if (this->searchNode(data)) {

		cout << "Data \'" << data << "\' found in heap" << endl;
	}

	else {

		cout << "Data \'" << data << "\' found in heap" << endl;
	}
}

void Heap::breadthFirst() {

	if (!this->root) {

		cout << "Error: cannot traverse an empty heap." << endl;
	}

	else {

		Node *current = nullptr;
		queue<Node*> q;
		q.push(this->root);

		while (!q.empty()) {

			current = q.front();
			q.pop();
			cout << current->data << " ";

			if (current->left) {

				q.push(current->left);
			}

			if (current->right) {

				q.push(current->right);
			}
		}

		cout << endl;
	}
}

//private functions

void Heap::percolateUp(Node *node) {

	bool heapProperty = false;

	while (!heapProperty && root->parent) {

		if (node->data > node->parent->data) {

			swap(node->data, node->parent->data);

			node = node->parent;
		}

		else {

			heapProperty = true;
		}
	}
}

void Heap::percolateDown(Node *root) {

	bool heapProperty = false;

	while (root->right || root->left && !heapProperty) {

		if (root->right && root->right->data > root->left->data) {

			if (root->right->data > root->data) {

				swap(root->data, root->right->data);

				root = root->right;
			}

			else {

				heapProperty = true;
			}
		}

		else {

			if (root->left->data > root->data) {

				swap(root->data, root->left->data);

				root = root->left;
			}

			else {

				heapProperty = true;
			}
		}
	}
}

void Heap::adjustLast() {

	Node *current = nullptr;
	queue<Node*> q;
	q.push(this->root);

	while (!q.empty()) {

		current = q.front();
		q.pop();

		if (current->left) {

			q.push(current->left);
		}

		if (current->right) {

			q.push(current->right);
		}
	}

	this->last = current;
}

Node* Heap::searchNode(int data) {

	Node *current = this->root;

	while (current) {

		if (current->data == data) {

			break;
		}

		else if (current->data > data) {

			current = current->left;
		}

		else if (current->data < data) {

			current = current->right;
		}
	}

	return current;
}