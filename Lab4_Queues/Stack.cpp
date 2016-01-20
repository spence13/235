/*
 * Stack.cpp
 *
 *  Created on: Feb 23, 2015
 *      Author: spence13
 */

#include "Stack.h"

using namespace std;


Stack :: Stack()
{


}

Stack :: ~Stack()
{

}


bool Stack :: push(int copynotpassedbyreference)
{
	mylinkedlist.insertHead(copynotpassedbyreference);
}

bool Stack :: pop()
{
	mylinkedlist.remove(mylinkedlist.at(0));
}

int Stack :: top()
{
	mylinkedlist.at(0);
}

int Stack :: size()
{
	return mylinkedlist.size();
}

bool Stack :: contains(int bob)
{

	if (mylinkedlist.duplicate(bob) == true)
		{
		return true;
		}
	else
	{
		return false;
	}
}






