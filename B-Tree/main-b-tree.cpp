#include <iostream>
#include "b-tree.h"
using namespace std;


int main()
{
	int arr[] = { 7, 1, 10, 8, 6, 2, 9, 5, 3, 4, 11, 12, 13 };
	BTree tree(3);
	BTreeNode* result;

	int size = sizeof(arr) / sizeof(arr[0]);
	for (int i = 0; i < size; i++) {
		tree.insertNode(arr[i]);
	}

	cout << "B-Tree:" << endl;
	tree.traverse();

	result = tree.search(6);
	if (result == NULL)
		cout << "Not Present" << endl << endl;
	else
		cout << "Present " << endl << endl;

	result = tree.search(7);
	if (result == NULL)
		cout << "Not Present" << endl << endl;
	else
		cout << "Present " << endl << endl;



	system("pause");
	return 0;
}