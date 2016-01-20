/*
 * node.cpp
 *
 *  Created on: Mar 19, 2015
 *      Author: spence13
 */
#include "node.h"

using namespace std;


node :: node(int val)
{
	  	this->val = val;
	    left = NULL;
        right = NULL;


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



