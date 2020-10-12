#include <iostream>
#include "b-tree.h"
#include <list>
#include <queue>
using namespace std;


BTreeNode::BTreeNode(int t1, bool leaf1)
{
	t = t1;
	leaf = leaf1;

	keys = new int[2 * t - 1];
	Children = new BTreeNode *[2 * t];

	CurrentKeysNum = 0;
}

void BTreeNode::traverse(int level)
{
	int i;
	printKeys();
	if (level == 0) {
		cout << endl << "       ";
		for (int n = 0; n <= CurrentKeysNum; n++)
			cout << "|   ";
		cout << endl;
	}

	for (i = 0; i < CurrentKeysNum; i++)
	{
		if (leaf == false) {
			Children[i]->traverse(++level);
			cout << "  ";
		}
	}

	if (leaf == false) {
		Children[i]->traverse(++level);
	}
}



void BTreeNode::printKeys()
{
	cout << "[";
	for (int i = 0; i < CurrentKeysNum; i++) 
	{
		cout << keys[i] << " ";
	}
	cout << "]";
}


BTreeNode *BTreeNode::search(int k)
{
	int i = 0;
	while (i < CurrentKeysNum && k > keys[i])
		i++;
	if (keys[i] == k)
		return this;
	if (leaf == true)
		return NULL;
	return Children[i]->search(k);
}


void BTreeNode::insertNotFull(int k)
{
	int i = CurrentKeysNum - 1;

	if (leaf == true)
	{
		while (i >= 0 && keys[i] > k)  //Finding location for new key
		{
			keys[i + 1] = keys[i];   //moving all keys one place ahead
			i--;
		}
		keys[i + 1] = k;
		CurrentKeysNum = CurrentKeysNum + 1;
	}
	else  
	{
		while (i >= 0 && keys[i] > k)  //finding child for the new key
			i--;
		if (Children[i + 1]->CurrentKeysNum == 2 * t - 1)  //if this child is full
		{
			splitChild(i + 1, Children[i + 1]);  //splitting child into two
			if (keys[i + 1] < k)      //checking which of two "splitted" child will have the key
				i++;
		}
		Children[i + 1]->insertNotFull(k);
	}
}


void BTreeNode::splitChild(int i, BTreeNode *y)
{
	BTreeNode *z = new BTreeNode(y->t, y->leaf);  //new node to store t-1 keys of y
	z->CurrentKeysNum = t - 1;

	for (int j = 0; j < t - 1; j++)  //copying 
		z->keys[j] = y->keys[j + t];

	if (y->leaf == false)  //copy from y to z
	{
		for (int j = 0; j < t; j++)
			z->Children[j] = y->Children [j + t];
	}
	y->CurrentKeysNum = t - 1;  //we reduce keys in y

	for (int j = CurrentKeysNum; j >= i + 1; j--)   //create space for new child
		Children[j + 1] = Children[j];

	Children[i + 1] = z; //linking new child to current node

	for (int j = CurrentKeysNum - 1; j >= i; j--)  //finding location for one additional key from y
		keys[j + 1] = keys[j];

	keys[i] = y->keys[t - 1];  //copy the middle key
	CurrentKeysNum = CurrentKeysNum + 1;  //now we have one more keys in current node
}



void BTree::insertNode(int k)
{
	if (root == NULL)
	{
		root = new BTreeNode(t, true);
		root->keys[0] = k;
		root->CurrentKeysNum = 1;
	}
	else  
	{
		if (root->CurrentKeysNum == 2 * t - 1)
		{
			BTreeNode *s = new BTreeNode(t, false);
			s->Children[0] = root;
			s->splitChild(0, root);

			int i = 0;
			if (s->keys[0] < k)
				i++;
			s->Children[i]->insertNotFull(k);

			root = s;
		}
		else   
			root->insertNotFull(k);
	}
}