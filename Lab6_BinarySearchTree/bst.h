/*
 * bst.h
 *
 *  Created on: Mar 19, 2015
 *      Author: spence13
 */
#pragma once
#include "BSTInterface.h"
#include "node.h"


using namespace std;

class bst : public BSTInterface
{
public:
	bst();
	virtual ~bst();


	virtual NodeInterface * getRootNode();


	virtual bool add(int data);


	virtual bool remove(int data);

	virtual void clear();

	virtual bool recAdd(node* & n, int recdata);

	virtual bool recRemove(node* & n, int recdata);

	virtual bool iop(node* & R, node* & L);

private:

	node*root;


};