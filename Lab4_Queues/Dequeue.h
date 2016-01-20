/*
 * Dequeue.h
 *
 *  Created on: Feb 23, 2015
 *      Author: spence13
 */

#pragma once
#include "LinkedList.h"


using namespace std;

class Dequeue
{
public:
	Dequeue();
	virtual ~Dequeue();

	      bool addDequeLeft(int alpha);

		  bool addDequeRight(int beta);

		  bool removeDequeLeft();

		  bool removeDequeRight();

		  int TopDequeLeft();

		  int TopDequeRight();

		  int SizeDeque();

		  bool contains(int echo);


private:
	LinkedList <int> mylinkedlist; //different class so it can be the same name as others



};
