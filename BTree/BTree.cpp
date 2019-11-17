#include <iostream>
#include <vector>

using namespace std;

struct Node {
	int n;	// Node ³» data °³¼ö
	int m;
	int *key;
	Node **point;
};

class Stack {
private:
	int top;
	vector<int> stack;
public:
	Stack() {
		top = -1;
		stack = { 0 };
	}
	void push(int value);
	int pop(int value);
};

void Stack::push(int value) {
	stack[++top] = value;
}

int Stack::pop(int value) {
	if (top == -1)
		return -1;
	else {
		int num = *stack.end();
		stack.erase(stack.end());
		return num;
	}
}

class BTree {
private:
	Node *root;
	Stack stack;
public:
	BTree() { root = NULL; }
	Node* getNode(int m);
	void insertBT(int m, int newKey);
	void insertBT(Node *T, int m, int newKey);
};

Node* BTree::getNode(int m) {
	Node *temp = new Node;
	temp->n = 0;
	temp->m = m;
	temp->key = new int[m - 1];
	temp->point = new Node*[m];
	temp->key = NULL;
	temp->point = NULL;
	return temp;
}

void BTree::insertBT(int m, int newKey) {
	insertBT(root, m, newKey);
}

void BTree::insertBT(Node *T, int m, int newKey) {
	if (T == NULL) {
		T = getNode(m);
		T->n = 1;
		T->key[0] = newKey;
		root = T;
		return;
	}
	Node *x = T;

}