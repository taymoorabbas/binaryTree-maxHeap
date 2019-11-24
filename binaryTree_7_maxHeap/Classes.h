struct Node {

	int data;
	Node *left, *right, *parent;
};

class Heap {

private:
	Node *root, *last;

	void percolateUp(Node*);
	void percolateDown(Node*);
	void adjustLast();
	Node *searchNode(int data);

public:
	Heap();
	void insert(int);
	void remove();
	void search(int);
	void breadthFirst();

};