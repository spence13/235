/*
 * avl.cpp
 *
 *  Created on: Apr 8, 2015
 *      Author: spence13
 */

#include "avl.h"

using namespace std;

avl :: avl()
{
	root = NULL;
	increase = false;
	decrease = false;
}
avl ::  ~avl()
{
	clear();
}


NodeInterface * avl :: getRootNode()
{
	return root;
}

bool avl :: add(int data)
{
	if(root == NULL)
	{
		node* ptr = new node (data, 1, 0);
		root = ptr;

		return true;
	}
	if(recAdd(root, data))
	{
		return true;
	}

	return false;
}

bool avl :: recAdd(node* & n, int recdata)
{
	if(n == NULL)
	{
		node * ptr = new node (recdata, 1, 0);
		n = ptr;
		increase = true;
		return true;
	}
	if(n->val == recdata)
	{
		return false;
	}

	if(recdata > n->val)
	{
		if(recAdd(n->right, recdata) == true)
		{
			if(n->height == n->right->height)
			{
				n->height++;
			}

			if(increase == true)
			{
				n->balance++;
			}
			if(n->balance == 0)
			{
				increase = false;
			}
			if(getdiff(n) > 1)//(n->balance > 1)
			{
				increase = false;
				rebalance_right(n);
			}


			return true;
		}
		else
		{
			return false;
		}

	}
	else if(recdata < n->val)
	{
		if(recAdd(n->left, recdata) == true)
		{
			if(n->height == n->left->height)
			{
				n->height++;
			}

			if(increase == true)
			{
				n->balance--;
			}
			if(n->balance == 0)
			{
				increase = false;
			}
			if(getdiff(n) < -1)//(n->balance < -1)
			{
				increase = false;
				rebalance_left(n);
			}

			return true;
		}
		else
		{
			return false;
		}
	}

}



bool avl :: remove(int data)
{
	 if(recRemove(root, data))
	 {
		 return true;
	 }

	 return false;
}

bool avl :: recRemove(node* & n, int recdata)
{
	if(n == NULL)
	{
		return false;
	}

	if(n->val == recdata)
	{
		if(n->right == NULL && n->left == NULL)			 ////////////// zero children
		{
			node*temp = n;
			delete temp;
			n = NULL;
			decrease = true;
			return true;
		}
		if (n->right == NULL && n->left != NULL)			//////////// has a left child
		{
			if(root->val == recdata)
			{
				node*temp = n;
				root = root->left;
				delete temp;
				decrease = true;
				return true;
			}
			node*temp = n;
			n = n->left;
			delete temp;
			decrease = true;
			return true;
		}
		if (n->right != NULL && n->left == NULL)/////////////// has a right child
		{
			if(root->val == recdata)
			{
				node*temp = n;
				root = root->right;
				delete temp;
				decrease = true;
				return true;
			}
			node*temp = n;
			n = n->right;
			delete temp;
			decrease = true;
			return true;
		}
		if(n->right != NULL && n->left != NULL)///////////////// 2 children
		{
			if(iop(n,n->left))
			{
			if(n->left != NULL && n->right != NULL)
			{
				iopheight(n);

				if(n->left->balance == 0 && n->right->balance == 0 && n->balance == -1)
				{
					decrease = true;
				}
			}
				if(decrease == true)
				{
					n->balance++;
				}

				if(/*n->balance == -1 ||*/ n->balance == 1)
				{
					decrease = false;
				}
				if(getdiff(n) > 1)									//(n->balance > 1)
				{
					decrease = false;
					Remove_rebalance_right(n);
				}

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
		if(recRemove(n->right, recdata) == true)				//PULL RIGHT
		{
			iopheight(n);

			if(n->left != NULL && n->right != NULL)
			{
			if(n->left->balance == 0 && n->right->balance == 0 && n->balance == 1)
			{
				decrease = true;

				if(n->right->height > n->left->height)
				{
					decrease = false;
				}
			}
			}
			if(decrease == true)
			{
				n->balance--;
			}

			if(n->balance == -1 /*|| n->balance == 1*/)
			{
				decrease = false;
			}
			if(getdiff(n) < -1)									//(n->balance < -1)
			{
				decrease = false;
				Remove_rebalance_left(n);
			}

			return true;
		}
		else
		{
			return false;
		}
	}
	else if(recdata < n->val)
	{
		if(recRemove(n->left, recdata) == true)					///////PULL LEFT
		{
			iopheight(n);

			if(n->left != NULL && n->right != NULL)
			{
			if(n->left->balance == 0 && n->right->balance == 0 && n->balance == -1)
			{
				decrease = true;

			}
			}
			if(decrease == true)
			{
				n->balance++;
			}

			if(n->balance == -1 || n->balance == 1)
			{
				decrease = false;
			}
			if(getdiff(n) > 1)									//(n->balance > 1)
			{
				decrease = false;
				Remove_rebalance_right(n);
			}

			return true;
		}
		else
		{
			return false;
		}
	}
}

bool avl :: iop(node* & R, node* & L)
{
	if(L->right != NULL)
	{
		iop(R,L->right);

			iopheight(L);

			if(decrease == true)
			{
				L->balance--;
			}

			if(L->balance == -1 || L->balance == 1)
			{
				decrease = false;
			}
			if(getdiff(L) < -1)									//(L->balance < -1)
			{
				decrease = false;
				Remove_rebalance_left(L);
			}

		return true;

	}
	else
	{
		int dummy = R->val;
		R->val = L->val;
		L->val = dummy;
		recRemove(L, L->val);
		return true;
	}
}



void avl :: rebalance_left(node* & n)
{

	if(getdiff(n->left) > 0)//(n->left->balance > 0)//(left-right case)
	{
		if(getdiff(n->left->right) < 0)//(n->left->right->balance < 0)//(left-right-left case)
		{
			n->left->balance = 0;n->left->height--;
			n->left->right->balance = 0;n->left->right->height++;				////I CHANGED THIS LINE CUZ SLIDE WAS WRONG
			n->balance= +1;n->height = n->height - 2;
		}
		else if(getdiff(n->left->right) > 0)//(n->left->right->balance > 0)//(left-right-right case)
		{
			n->left->balance = -1;n->left->height--;
			n->left->right->balance = 0;n->left->right->height++;				////I CHANGED THIS LINE CUZ SLIDE WAS WRONG
			n->balance = 0;n->height = n->height - 2;
		}
		else//(left-right Balanced case)
		{
			n->left->balance = 0;n->left->height--;
			n->left->right->balance = 0;n->left->right->height++;				////I CHANGED THIS LINE CUZ SLIDE WAS WRONG
			n->balance = 0;n->height = n->height - 2;
		}

	//rotate left around child
	node*temp = n->left->right;
	n->left->right = temp->left;
	temp->left = n->left;
	n->left = temp;

	}

	else//(left-left case)
	{
		n->left->balance = 0;
		n->balance = 0;n->height = n->left->height - 1;
	}

	//rotate right
	node* temp = n->left;
	n->left = temp->right;
	temp->right = n;
	n = temp;

}

void avl :: rebalance_right(node* & n)
{
	if(getdiff(n->right) < 0)//(n->right->balance < 0)//(right-left case)
	{
		if(getdiff(n->right->left) > 0)//(n->right->left->balance > 0)//(right-left-right case)
		{
			n->right->balance = 0;n->right->height--;
			n->right->left->balance = 0;n->right->left->height++;				//I CHANGE THIS LINE CUZ SLIDE WAS WRONG
			n->balance= -1;n->height = n->height - 2;
		}
		else if(getdiff(n->right->left) < 0)//(n->right->left->balance < 0)//(right-left-left case)
		{
			n->right->balance = +1;n->right->height--;
			n->right->left->balance = 0;n->right->left->height++;				//I CHANGE THIS LINE CUZ SLIDE WAS WRONG
			n->balance = 0;n->height = n->height - 2;
		}
		else//(right-left Balanced case)
		{
			n->right->balance = 0;n->right->height--;
			n->right->left->balance = 0;n->right->left->height++;				//I CHANGE THIS LINE CUZ SLIDE WAS WRONG
			n->balance = 0;n->height = n->height - 2;
		}

	//rotate right around child
	node* temp = n->right->left;
	n->right->left = temp->right;
	temp->right = n->right;
	n->right = temp;

	}

	else//(right-right case)
	{
		n->right->balance = 0;
		n->balance = 0;n->height = n->right->height - 1;
	}

	//rotate left
	node*temp = n->right;
	n->right = temp->left;
	temp->left = n;
	n = temp;

}



void avl :: Remove_rebalance_left(node* & n)
{
	if(getdiff(n->left) > 0)//(n->left->balance > 0)//(left-right case)
	{
		if(getdiff(n->left->right) < 0)//(n->left->right->balance < 0)//(left-right-left case)
		{
			n->left->balance = 0;n->left->height--;
			n->left->right->balance = 0;n->left->right->height++;				////I CHANGED THIS LINE CUZ SLIDE WAS WRONG
			n->balance= +1;n->height--;
		}
		else if(getdiff(n->left->right) > 0)//(n->left->right->balance > 0)//(left-right-right case)
		{
			n->left->balance = -1;n->left->height--;
			n->left->right->balance = 0;n->left->right->height++;				////I CHANGED THIS LINE CUZ SLIDE WAS WRONG
			n->balance = 0;n->height--;
		}
		else//(left-right Balanced case)
		{
			n->left->balance = 0;	n->left->height--;
			n->left->right->balance = 0;n->left->right->height++;				////I CHANGED THIS LINE CUZ SLIDE WAS WRONG
			n->balance = 0;n->height = n->height - 2;
		}

	//rotate left around child
	node*temp = n->left->right;
	n->left->right = temp->left;
	temp->left = n->left;
	n->left = temp;

	}

	else//(left-left case)
	{
		if(getdiff(n->left) < 0)//(n->left->balance < 0)		//left left
		{
			n->left->balance = 0;
			n->balance = 0;n->height = n->left->height - 1;
		}
		else			//left balanced
		{
			n->left->balance = +1;n->left->height++;
			n->balance = -1;

			if(n->left->right != NULL)										// STOP GAP MEASURE
			{
				n->height = n->left->right->height + 1;
			}
			else
			{
				n->left->height--;
				n->height = 1;
			}
		}
	}

	//rotate right
	node* temp = n->left;
	n->left = temp->right;
	temp->right = n;
	n = temp;

}

void avl :: Remove_rebalance_right(node* & n)
{
	if(getdiff(n->right) < 0)//(n->right->balance < 0)//(right-left case)
	{
		if(getdiff(n->right->left) > 0)//(n->right->left->balance > 0)//(right-left-right case)
		{
			n->right->balance = 0;n->right->height--;
			n->right->left->balance = 0;n->right->left->height++;				//I CHANGE THIS LINE CUZ SLIDE WAS WRONG
			n->balance= -1;n->height--;
		}
		else if(getdiff(n->right->left) < 0)//(n->right->left->balance < 0)//(right-left-left case)
		{
			n->right->balance = +1;n->right->height--;
			n->right->left->balance = 0;n->right->left->height++;				//I CHANGE THIS LINE CUZ SLIDE WAS WRONG
			n->balance = 0;n->height--;
		}
		else//(right-left Balanced case)
		{
			n->right->balance = 0;n->right->height--;
			n->right->left->balance = 0;n->right->left->height++;				//I CHANGE THIS LINE CUZ SLIDE WAS WRONG
			n->balance = 0;n->height = n->height - 2;
		}

	//rotate right around child
	node* temp = n->right->left;
	n->right->left = temp->right;
	temp->right = n->right;
	n->right = temp;

	}

	else//(right-right case)
	{

		if(getdiff(n->right) > 0)//(n->right->balance > 0)//right-right
		{
			n->right->balance = 0;
			n->balance = 0;n->height = n->right->height - 1;
		}
		else			//right-balanced
		{
			n->right->balance = -1;n->right->height++;
			n->balance = +1;
			if(n->right->left != NULL)										// STOP GAP MEASURE
			{
				n->height = n->right->left->height + 1;
			}
			else
			{
				n->right->height--;
				n->height = 1;
			}
		}
	}

	//rotate left
	node*temp = n->right;
	n->right = temp->left;
	temp->left = n;
	n = temp;


}

int avl :: iopheight(node* & n)
{
	int le = 0;
	int ri = 0;
	if(n->left != NULL)
	{
		le = n->left->height;
	}
	if(n->right != NULL)
	{
		ri = n->right->height;
	}
	if(le > ri)
	{
		n->height = le + 1;
	}
	if(ri > le)
	{
		n->height = ri + 1;
	}
	if(le == ri)
	{
		n->height = le +1;
	}
	if(n->left == NULL && n->right == NULL)
	{
		n->height = 1;
	}

	return n->height;
}



int avl :: getdiff(node* & n)
{

	if(n->left == NULL && n->right == NULL)
	{
		return 0;
	}
	if(n->left != NULL && n->right != NULL)
	{

		return n->right->height - n->left->height;
	}
	if(n->right == NULL && n->left != NULL)
	{
		return 0 - n->left->height;
	}
	if(n->right != NULL && n->left == NULL)
	{
		return n->right->height - 0;
	}

}

void avl :: clear()
{
	 while(root != NULL)
	 {
		 remove(root->val);
	 }
	//root = NULL;
}



