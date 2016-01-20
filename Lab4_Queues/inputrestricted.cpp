/*
 * extra.cpp
 *
 *  Created on: Feb 27, 2015
 *      Author: spence13
 */



#include "inputrestricted.h"


using namespace std;


inputrestricted :: inputrestricted()
{


}

inputrestricted :: ~inputrestricted()
{

}





bool inputrestricted :: addirleft(int alpha)
{
	 mylinkedlist.insertHead(alpha);
}

bool inputrestricted :: removeirleft()
{
	 mylinkedlist.remove(mylinkedlist.at(0));
}

bool inputrestricted :: removeirright()
{
	 mylinkedlist.remove(mylinkedlist.at(mylinkedlist.size()-1));
}

int inputrestricted :: topirleft()
{
	 mylinkedlist.at(0);
}

int inputrestricted :: topirright()
{
	 mylinkedlist.at(mylinkedlist.size()-1);
}

int inputrestricted :: sizeir()
{
	 mylinkedlist.size();
}



bool inputrestricted :: contains(int bob)
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
