#include <iostream>
#include "avltree.h"
using namespace std;

void main() {
	int arr[] = { 1, 2, 3, 5 };
	
	BST tree;
	BST* root = NULL;

	int size = sizeof(arr) / sizeof(arr[0]);
	for (int i = 0; i < size; i++) {
		root = tree.InsertNode(root, arr[i]);
	}

	cout << "AVL Tree:" << endl;
	tree.printPostorder(root);
	cout << endl << "Insertion of 4:" << endl;

	tree.InsertNode(root, 4);
	tree.printPostorder(root);
	cout << endl << "Deletion of 1:" << endl;
	root = tree.DeleteNode(root, 5);
	root = tree.DeleteNode(root, 1);
	tree.printPostorder(root);

	system("pause");
}