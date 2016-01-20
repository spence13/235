/*
 * Queue.cpp


 *
 *  Created on: Feb 23, 2015
 *      Author: spence13
 */

#include "Queue.h"

using namespace std;

Queue :: Queue()
{

}

Queue :: ~Queue()
{

}



bool Queue :: addQueue(int charlie)
{
	mylinkedlist.insertHead(charlie);
}

bool Queue :: removeQueue()
{
	mylinkedlist.remove(mylinkedlist.at(mylinkedlist.size()-1));
}

int Queue :: TopQueue()
{
	mylinkedlist.at(mylinkedlist.size() - 1);
}

int Queue :: SizeQueue()
{
	return mylinkedlist.size();
}

bool Queue :: contains(int echo)
{
	if (mylinkedlist.duplicate(echo) == true)
	{
		return true;
	}
	else
	{
		return false;
	}
}
