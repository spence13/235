/*
 * node.h
 *
 *  Created on: Apr 8, 2015
 *      Author: spence13
 */

#pragma once
#include "NodeInterface.h"
#include <iostream>

using namespace std;

class node : public NodeInterface
{

public:
	node(int val, int height, int balance);
	virtual ~node();


	virtual int getData();

	virtual NodeInterface * getLeftChild();

	virtual NodeInterface * getRightChild();

	virtual int getHeight();

//private:

  int val;
  node* left;
  node* right;
  int height;
  int balance;





};