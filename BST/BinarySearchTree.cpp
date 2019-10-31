#include <iostream>

using namespace std;

struct Node {
	Node *left;
	Node *right;
	int key;
};

class BST {
private:
	Node *root;
public:
	BST();
	void insertBST(int newKey);
	void insertBST(Node *T,int newKey);
	void deleteBST(int deleteKey);
	void deleteBST(Node *T,int deleteKey);
	Node* searchBST(int searchKey);
	Node* searchBST(Node *T, int searchKey);
	Node* searchParentBST(int searchKey);
	Node* searchParentBST(Node *T, int searchKey);
	Node* getNode(int newKey);
	Node* minNode(Node* T);
	Node* maxNode(Node* T);
	int height(Node* T);
	int noNodes();
	int noNodes(Node* T);
	void inorder(Node *T);
	void inorderBST();
};

BST::BST() {
	root = 0;
}

void BST::insertBST(int newKey) {
	insertBST(root, newKey);
}

void BST::insertBST(Node *T, int newKey) {
	Node *q = 0;
	Node *p = T;
	while (p != 0) {
		if (newKey == p->key)
			return;
		q = p;
		if (newKey < p->key)
			p = p->left;
		else
			p = p->right;
	}
	Node *newNode = getNode(newKey);

	if (T == 0)
		root = newNode;
	else if (newKey < q->key)
		q->left = newNode;
	else
		q->right = newNode;
	return;
}

void BST::deleteBST(int deleteKey) {
	deleteBST(root, deleteKey);
}

void BST::deleteBST(Node *T, int deleteKey) {
	Node *p = searchBST(deleteKey);	// 삭제할 노드
	Node *q = searchParentBST(deleteKey);	// 삭제할 노드의 부모 노드
	if (p == 0)		// delete 대상 노드가 없음
		return;
	if (p->left == 0 && p->right == 0) {
		if (q == 0) {	// delete 대상 노드가 root인 경우
			root = 0;
		}
		else {
			if (q->left == p)
				q->left = 0;
			else
				q->right = 0;
		}
	}
	else if (p->left == 0 || p->right == 0) {
		if (q == 0) {	// delete 대상 노드가 root인 경우
			if (p->left != 0) {
				q = p;
				p = p->left;
				root = p;
				q->left = 0;
			}
			else {
				q = p;
				p = p->right;
				root = p;
				q->right = 0;
			}
		}
		else {
			if (p->left != 0) {
				if (q->left == p)
					q->left = p->left;
				else
					q->right = p->left;
			}
			else {
				if (q->left == p)
					q->left = p->right;
				else
					q->right = p->right;
			}
		}
	}
	else {
		Node *r = 0;
		bool flag;	//flag = 0 <-> left, flag = 1 <-> right;
		if (height(p->left) > height(p->right)) {
			r = maxNode(p->left);
			flag = 0;
		}
		else if (height(p->left) < height(p->right)) {
			r = minNode(p->right);
			flag = 1;
		}
		else {
			if (noNodes(p->left) >= noNodes(p->right)) {
				r = maxNode(p->left);
				flag = 0;
			}
			else {
				r = minNode(p->right);
				flag = 1;
			}
		}
		if (flag == 0)
			deleteBST(p->left, r->key);
		else
			deleteBST(p->right, r->key);
		p->key = r->key;
	}
}

Node* BST::searchBST(int searchKey) {
	return searchBST(root, searchKey);
}

Node* BST::searchBST(Node *T, int searchKey) {
	Node *p = root;
	while (p != 0) {
		if (p->key < searchKey)
			p = p->right;
		else if (p->key > searchKey)
			p = p->left;
		else
			return p;
	}
	return p;
}

Node* BST::searchParentBST(int searchKey) {
	return searchParentBST(root, searchKey);
}

Node* BST::searchParentBST(Node *T, int searchKey) {
	Node *p = T;
	Node *q = 0;
	while (p != 0) {
		if (p->key < searchKey) {
			q = p;
			p = p->right;
		}
		else if (p->key > searchKey) {
			q = p;
			p = p->left;
		}
		else
			return q;
	}
	return q;
}

Node* BST::getNode(int newKey) {
	Node *temp = new Node();
	temp->key = newKey;
	temp->left = 0;
	temp->right = 0;
	return temp;
}

Node* BST::minNode(Node *T) {
	Node *q = 0;
	Node *p = T;
	while (p != 0) {
		q = p;
		p = p->left;
	}
	return q;
}

Node* BST::maxNode(Node *T) {
	Node *q = 0;
	Node *p = T;
	while (p != 0) {
		q = p;
		p = p->right;
	}
	return q;
}

int BST::height(Node *T) {
	if (!T)
		return 0;
	else {
		int lLevel = height(T->left);
		int rLevel = height(T->right);
		return 1 + (lLevel > rLevel ? lLevel : rLevel);
	}
}

int BST::noNodes() {
	return noNodes(root);
}

int BST::noNodes(Node *T) {
	int cnt = 0;
	if (T) {
		cnt = cnt + noNodes(T->left);
		cnt++;
		cnt = cnt + noNodes(T->right);
	}
	else {
		return 0;
	}
	return cnt;
}

void BST::inorder(Node *T) {
	if (T) {
		inorder(T->left);
		cout << T->key<< " ";
		inorder(T->right);
	}
}

void BST::inorderBST() {
	inorder(root);
	cout << endl;
}

int main() {
	BST tree1;
	BST tree2;
	int input[19] = { 40,11,77,33,20,90,99,70,88,80,66,10,22,30,44,55,50,60,100 };
	

	cout << "==================================Insert 1==================================" << endl;
	for (int i = 0; i < sizeof(input) / sizeof(int); i++) {
		tree1.insertBST(input[i]);
		cout << "insert " << input[i] << " : ";
		tree1.inorderBST();
	}
	cout << endl;

	cout << "==================================Delete 1==================================" << endl;
	for (int i = 0; i < sizeof(input) / sizeof(int); i++) {
		tree1.deleteBST(input[i]);
		cout << "delete " << input[i] << " : ";
		tree1.inorderBST();
	}
	cout << endl;

	cout << "==================================Insert 2==================================" << endl;
	for (int i = 0; i < sizeof(input) / sizeof(int); i++) {
		tree2.insertBST(input[i]);
		cout << "insert " << input[i] << " : ";
		tree2.inorderBST();
	}
	cout << endl;

	cout << "==================================Delete 2==================================" << endl;
	for (int i = sizeof(input) / sizeof(int) - 1; i >= 0; i--) {
		tree2.deleteBST(input[i]);
		cout << "delete " << input[i] << " : ";
		tree2.inorderBST();
	}
	cout << endl;

	return 0;
}