#pragma once
#include <iostream>
#include <list>
#include <queue>
using namespace std;

// A BTree node 
class BTreeNode
{
	int *keys;   
	int t;       
	BTreeNode **Children;  
	int CurrentKeysNum;      
	bool leaf;  

public:
	BTreeNode(int _t, bool _leaf);  

	void insertNotFull(int k);

	void splitChild(int i, BTreeNode *y);

	void traverse(int level);

	BTreeNode *search(int k);   

	void printKeys();

	friend class BTree;
};


class BTree
{
	BTreeNode *root;  
	int t; 

public:

	BTree(int _t) { root = NULL;  t = _t; }

	void traverse()
	{
		cout << "        ";
		if (root != NULL) root->traverse(0);
		cout << endl << endl;
	}

	BTreeNode* search(int k) { return (root == NULL) ? NULL : root->search(k); }

	void insertNode(int k);
};



