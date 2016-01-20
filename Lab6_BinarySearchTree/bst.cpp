/*
 * bst.cpp
 *
 *  Created on: Mar 19, 2015
 *      Author: spence13
 */

#include "bst.h"


using namespace std;

bst :: bst()
{
	root = NULL;
}
bst ::  ~bst()
{

}


 NodeInterface * bst :: getRootNode()
 {
	 return root;
 }




 bool bst :: add(int data)
 {

	if(root == NULL)
	{
		node * ptr = new node (data);
		root = ptr;
		return true;
	}
	if(recAdd(root, data))
	{
		return true;
	}

	return false;

 }
bool bst :: recAdd(node* & n, int recdata)
{
	if(n == NULL)
	{
		node * ptr = new node (recdata);
		n = ptr;
		return true;
	}
	if(n->val == recdata)
	{
		return false;
	}
	if(recdata > n->val)
	{
		recAdd(n->right, recdata);
	}
	else if(recdata < n->val)
	{
		recAdd(n->left, recdata);
	}
}





 bool bst :: remove(int data)
 {


	 if(recRemove(root, data))
	 {
		 return true;
	 }

	 return false;
 }

bool bst :: recRemove(node* & n, int recdata)
{
	if(n == NULL)
	{
		return false;
	}
	if(n->val == recdata)
	{
		if(n->right == NULL && n->left == NULL) ////////////// zero children
		{
			node*temp = n;
			delete temp;
			n = NULL;
			return true;
		}
		if (n->right == NULL && n->left != NULL)//////////// has a left child
		{
			if(root->val == recdata)
			{
				node*temp = n;
				root = root->left;
				delete temp;
				return true;
			}
			node*temp = n;
			n = n->left;
			delete temp;
			return true;
		}
		if (n->right != NULL && n->left == NULL)/////////////// has a right child
		{
			if(root->val == recdata)
			{
				node*temp = n;
				root = root->right;
				delete temp;
				return true;
			}
			node*temp = n;
			n = n->right;
			delete temp;
			return true;
		}
		if(n->right != NULL && n->left != NULL)///////////////// 2 children
		{
			if(iop(n,n->left))
			{
				return true;
			}
			else
			{
				return false;
			}


		}
	}
	else if(recdata > n->val)
	{
		return recRemove(n->right, recdata);
	}
	else if(recdata < n->val)
	{
		return recRemove(n->left, recdata);
	}
}

 void bst :: clear()
 {
	 while(root != NULL)
	 {
		 remove(root->val);
	 }
	//root = NULL;
 }

bool bst :: iop(node* & R, node* & L)
{
	if(L->right != NULL)
	{
	return iop(R,L->right);
	}
	else
	{
		int dummy = R->val;
		R->val = L->val;
		L->val = dummy;
		recRemove(L, L->val);
	}
}



