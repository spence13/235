/*
 * Queue.h
 *
 *  Created on: Feb 23, 2015
 *      Author: spence13
 */

#pragma once
#include "LinkedList.h"

using namespace std;

class Queue
{
public:
	Queue();
	virtual ~Queue();


	  bool addQueue(int charlie);

	  bool removeQueue();

	  int TopQueue();

	  int SizeQueue();

	  bool contains(int echo);

private:
	  LinkedList <int> mylinkedlist; // doesn't matter that its the same name as in stack cuz this is in a different class




};