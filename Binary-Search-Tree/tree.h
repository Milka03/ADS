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


class BST
{
	int key;
	BST *left, *right;

public:
	BST();

	BST(int);

	BST* InsertNode(BST *, int);

	// Postorder traversal
	void Inorder(BST *);

	BST* Search(int value, BST* tree);

	BST* DeleteNode(int nkey, BST* tree);

	void printPostorder(BST* tree);

	BST* minValueNode(BST* node);

	int GetKey() { return this->key; }
};


//Node* InsertNode(int nkey, Node* tree = NULL);
//
//void Search(int skey, Node* tree);
//
//void DeleteNode(int nkey, Node* tree);
//
//void Print(Node* tree);