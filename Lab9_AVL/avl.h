/*
 * avl.h
 *
 *  Created on: Apr 8, 2015
 *      Author: spence13
 */

#pragma once
#include "AVLInterface.h"
#include "node.h"

using namespace std;

class avl : public AVLInterface
{

public:
	avl();
	virtual ~avl();


	virtual NodeInterface * getRootNode();

	virtual bool add(int data);

	virtual bool remove(int data);

	virtual bool recAdd(node* & n, int recdata);

	virtual bool recRemove(node* & n, int recdata);

	virtual bool iop(node* & R, node* & L);

	virtual void rebalance_left(node* & n);

	virtual void rebalance_right(node* & n);

	virtual void Remove_rebalance_left(node* & n);

	virtual void Remove_rebalance_right(node* & n);

	virtual int iopheight(node* & n);

	virtual int getdiff(node* & n);

	virtual void clear();

private:

	node * root;
	bool increase;
	bool decrease;



};