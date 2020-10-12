#pragma once
#include <iostream>

struct Node {
	int key;
	struct Node *left, *right, *parent;
	Node(int key, Node* parent = NULL) {
		this->key = key;
		this->parent = parent;
		this->left = this->right = NULL;
	}
};
//calculate height
//insert and rotate
//delete and rotate
//next week B trees

class BST
{
	int key;
	int height;
	BST *left, *right;

public:
	BST();

	BST(int);

	BST* InsertNode(BST *, int);

	BST* DeleteNode(BST* root, int value);

	BST* rightRotate(BST *y);

	BST* leftRotate(BST *x);

	int getBalance(BST *N);


	void printPostorder(BST* tree);

	void Inorder(BST *);

	BST* Search(int value, BST* tree);

	BST* minValueNode(BST* node);


	int GetHeight(BST *N);

	int GetKey() { return this->key; }
};

int max(int a, int b);


//Node* InsertNode(int nkey, Node* tree = NULL);
//
//void Search(int skey, Node* tree);
//
//void DeleteNode(int nkey, Node* tree);
//
//void Print(Node* tree);