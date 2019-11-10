#include <iostream>

using namespace std;

struct Node {
	int key;
	int bf;		// bf = Balancing Factor
	Node* left;
	Node* right;
};

class AVL {
private:
	Node* root;
	int rType;	// rotateType : 0 = NO, 1 = LL
public:			// 2 = LR, 3 = RL, 4 = RR
	AVL();
	void insertBST(int newKey);
	void insertBST(Node* T, int newKey);
	void checkBalance(Node* T, int newKey, Node* p, Node* q);
	void rotateTree(Node* T, Node *p, Node *q);
	void inorderBST();
	void inorderBST(Node* T);
	Node* getNode(int newKey);
};

AVL::AVL() {
	root = NULL;
	rType = 0;
}

void AVL::insertBST(int newKey) {
	insertBST(root, newKey);
}

void AVL::insertBST(Node *T, int newKey) {
	Node *q = NULL;
	Node *p = T;
	while (p != NULL) {
		if (newKey == p->key)
			return;
		q = p;
		if (newKey < p->key)
			p = p->left;
		else
			p = p->right;
	}
	Node *newNode = getNode(newKey);

	if (T == NULL)
		root = newNode;
	else if (newKey < q->key)
		q->left = newNode;
	else
		q->right = newNode;

	checkBalance(T, newKey, p, q);
	rotateTree(T, p, q);
	return;
}

void AVL::checkBalance(Node *T, int newKey, Node *p, Node *q) {

}

void AVL::rotateTree(Node *T, Node *p, Node *q) {

}

void AVL::inorderBST() {
	inorderBST(root);
	cout << endl;
}

void AVL::inorderBST(Node* T) {
	if (T) {
		inorderBST(T->left);
		cout << T->key << " ";
		inorderBST(T->right);
	}
}

Node* AVL::getNode(int value) {
	Node* temp = new Node;
	temp->key = value;
	temp->bf = 0;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}