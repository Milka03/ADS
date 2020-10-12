#include <iostream>
#include "tree.h"
using namespace std;

void main() {
	int arr[] = { 7, 10, 5, 1, 8, 6, 9 };
	BST tree;
	BST* root = NULL;

	int size = sizeof(arr) / sizeof(arr[0]);
	for (int i = 0; i < size; i++) {
		root = tree.InsertNode(root, arr[i]);
	}

	cout << "Binary Search Tree:" << endl;
	tree.printPostorder(root);
	cout << endl;
	BST* root2 = tree.Search(2, root);
	if (root2 == NULL)
		cout << "Tree does not contain given number" << endl << endl;
	else
		cout << "Searching succeeded: " << root2->GetKey() << endl << endl;

	/*cout << "Delete node 9:" << endl;
	root = tree.DeleteNode(9, root);
	tree.printPostorder(root);*/

	cout << "Delete node 7:" << endl;
	root = tree.DeleteNode(7, root);
	tree.printPostorder(root);

	system("pause");
}


//int main()
//{
//	BST b, *root = NULL;
//	root = b.Insert(root, 50);
//	b.Insert(root, 30);
//	b.Insert(root, 20);
//	b.Insert(root, 40);
//	b.Insert(root, 70);
//	b.Insert(root, 60);
//	b.Insert(root, 80);
//
//	b.Inorder(root);
//	return 0;
//}