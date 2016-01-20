/*
 * Stack.h
 *
 *  Created on: Feb 23, 2015
 *      Author: spence13
 */

#pragma once
#include "LinkedList.h"


using namespace std;

class Stack
{
public:
	Stack();
	virtual ~Stack();




	 bool push(int copynotpassedbyreference);

	 bool pop();

	 int top();

	 int size();

	 bool contains(int bob);



private:
	 LinkedList <int> mylinkedlist;






};