
/*
 * node.cpp
 *
 *  Created on: Apr 8, 2015
 *      Author: spence13
 */

#include "node.h"

using namespace std;


node :: node(int val, int height, int balance)
{
	this->val = val;
    left = NULL;
    right = NULL;
    this->height = height;
    this->balance = balance;
}
node :: ~node()
{

}


int node :: getData()
{
	return val;
}


NodeInterface * node :: getLeftChild()
{
	return left;
}


NodeInterface * node :: getRightChild()
{
	return right;
}

int node :: getHeight()
{
	return height;
}








