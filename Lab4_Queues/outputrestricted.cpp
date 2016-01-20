/*
 * outputrestricted.cpp
 *
 *  Created on: Feb 27, 2015
 *      Author: spence13
 */

#include "outputrestricted.h"

using namespace std;

outputrestricted :: outputrestricted()
{


}

outputrestricted :: ~outputrestricted()
{

}





bool outputrestricted :: addorleft(int alpha)
{
	 mylinkedlist.insertHead(alpha);
}

bool outputrestricted :: addorright(int beta)
{
	 mylinkedlist.insertTail(beta);
}

bool outputrestricted :: removeorleft()
{
	 mylinkedlist.remove(mylinkedlist.at(0));
}

int outputrestricted :: toporleft()
{
	 mylinkedlist.at(0);
}

int outputrestricted :: sizeor()
{
	 mylinkedlist.size();
}






bool outputrestricted :: contains(int bob)
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

