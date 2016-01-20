/*
 * node.h
 *
 *  Created on: Mar 19, 2015
 *      Author: spence13
 */

#pragma once
#include "NodeInterface.h"

using namespace std;

class node : public NodeInterface
{

public:
	node(int val);
	virtual ~node();


	virtual int getData();


	virtual NodeInterface * getLeftChild();


	virtual NodeInterface * getRightChild();

//private:

  int val;
  node* left;
  node* right;




};