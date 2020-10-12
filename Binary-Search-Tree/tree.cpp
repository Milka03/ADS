#include <iostream>
#include "tree.h"
#include <list>
using namespace std;


BST::BST() : key(0), left(NULL), right(NULL) {}

BST::BST(int value)
{
	key = value;
	left = right = NULL;
}

BST* BST::InsertNode(BST *root, int value)
{
	if (!root)
		return new BST(value);

	if (value > root->key)
		root->right = InsertNode(root->right, value);
	else
		root->left = InsertNode(root->left, value);

	return root;
}

void BST::printPostorder(BST* node)
{
	if (!node)
		return;
	printPostorder(node->left);
	printPostorder(node->right);
	cout << node->key << endl;
}


BST* BST::DeleteNode(int nkey, BST* tree) 
{
	if (tree == NULL) 
	{
		//cout << "Tree is empty!" << endl;
		return tree;
	}
	if (nkey < tree->key)
		tree->left = DeleteNode(nkey, tree->left);
	else if (nkey > tree->key)
		tree->right = DeleteNode(nkey, tree->right);
	else
	{
		if (tree->left == NULL)
		{
			BST *temp = tree->right;
			free(tree);
			return temp;
		}
		else if (tree->right == NULL)
		{
			BST *temp = tree->left;
			free(tree);
			return temp;
		}

		BST* temp = minValueNode(tree->right);
		tree->key = temp->key;
		tree->right = DeleteNode(temp->key, tree->right);
	}
	return tree;
}


BST* BST::Search(int value, BST* root)
{
	if (root == NULL || root->key == value)
		return root;

	if (root->key < value)
		return Search(value, root->right);

	return Search(value, root->left);
}


BST* BST::minValueNode(BST* node)
{
	BST* current = node;

	/* loop down to find the leftmost leaf */
	while (current && current->left != NULL)
		current = current->left;

	return current;
}

void BST::Inorder(BST* root)
{
	if (root != NULL)
	{
		Inorder(root->left);
		printf("%d ", root->key);
		Inorder(root->right);
	}
}