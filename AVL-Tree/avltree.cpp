#include <iostream>
#include "avltree.h"
#include <list>
using namespace std;


BST::BST() : key(0), left(NULL), right(NULL), height(0) {}

BST::BST(int value)
{
	key = value;
	left = right = NULL;
	height = 1;
}


BST* BST::InsertNode(BST *node, int value)
{
	if (node == NULL)
		return new BST(value);

	if (value < node->key)
		node->left = InsertNode(node->left, value);
	else if (value > node->key)
		node->right = InsertNode(node->right, value);
	else // Equal keys are not allowed in BST  
		return node;

	node->height = 1 + max(GetHeight(node->left), GetHeight(node->right)); //new height

	int balance = getBalance(node); 

	if (balance > 1 && value < node->left->key)
		return rightRotate(node);

	if (balance < -1 && value > node->right->key)
		return leftRotate(node);

	if (balance > 1 && value > node->left->key)
	{
		node->left = leftRotate(node->left);
		return rightRotate(node);
	}

	if (balance < -1 && value < node->right->key)
	{
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}

	return node;
}


BST* BST::DeleteNode(BST* root, int value)
{
	if (root == NULL)
		return root;

	if (value < root->key)
		root->left = DeleteNode(root->left, value);

	else if (value > root->key)
		root->right = DeleteNode(root->right, value);
	
	else
	{
		if ((root->left == NULL) || (root->right == NULL))
		{
			BST *temp = root->left ? root->left : root->right;
			if (temp == NULL)
			{
				temp = root;
				root = NULL;
			}
			else   
				*root = *temp;  
			free(temp);
		}
		else
		{
			BST* temp = minValueNode(root->right);
			root->key = temp->key;
			root->right = DeleteNode(root->right, temp->key);
		}
	}

	if (root == NULL)
		return root;

	root->height = 1 + max(GetHeight(root->left), GetHeight(root->right)); //update height
 
	int balance = getBalance(root);

	if (balance > 1 && getBalance(root->left) >= 0)
		return rightRotate(root);

	if (balance > 1 && getBalance(root->left) < 0)
	{
		root->left = leftRotate(root->left);
		return rightRotate(root);
	}

	if (balance < -1 && getBalance(root->right) <= 0)
		return leftRotate(root);

	if (balance < -1 && getBalance(root->right) > 0)
	{
		root->right = rightRotate(root->right);
		return leftRotate(root);
	}

	return root;
}


BST* BST::rightRotate(BST *y)
{
	BST *x = y->left;
	BST *T2 = x->right;

	x->right = y;
	y->left = T2;

	y->height = max(GetHeight(y->left), GetHeight(y->right)) + 1;
	x->height = max(GetHeight(x->left), GetHeight(x->right)) + 1;

	return x;
}

BST* BST::leftRotate(BST *x)
{
	BST *y = x->right;
	BST *T2 = y->left;

	y->left = x;
	x->right = T2;

	x->height = max(GetHeight(x->left), GetHeight(x->right)) + 1;
	y->height = max(GetHeight(y->left), GetHeight(y->right)) + 1;

	return y;
}

int BST::getBalance(BST *N)
{
	if (N == NULL)
		return 0;
	return GetHeight(N->left) - GetHeight(N->right);
}


//HELPING FUNCTIONS
int BST::GetHeight(BST *N)
{
	if (N == NULL)
		return 0;
	return N->height;
}

int max(int a, int b)
{
	return (a > b) ? a : b;
}


void BST::printPostorder(BST* node)
{
	if (!node)
		return;
	printPostorder(node->left);
	printPostorder(node->right);
	cout << " " << node->key  << " h=" << node->height << endl;
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
