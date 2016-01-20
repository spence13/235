/*
 * Station.cpp
 *
 *  Created on: Feb 23, 2015
 *      Author: spence13
 */

#include "Station.h"


using namespace std;


Station :: Station ()
{
	currentcar = -1;

}
Station :: ~Station()
{

}

bool Station :: addToStation(int car)
{

	if (currentcar == -1 && car >= 0 && mystack.contains(car) == true && myqueue.contains(car) == true && mydeck.contains(car) == true && myir.contains(car) == true && myor.contains(car) == true)
		{
			currentcar = car;
			return true;
		}

	else
	{
		return false;
	}

}


int Station :: showCurrentCar()
{
	return currentcar;
}


bool Station :: removeFromStation()
{
	if (currentcar == -1)
	{
		return false;
	}

	else
	{
		currentcar = -1;
		return true;
	}
}










bool Station :: addToStack()
{
	if (currentcar == -1 || mystack.size() == 5)
	{
		return false;
	}
	else
	{
		mystack.push(currentcar);
		currentcar = -1;
		return true;
	}
}
bool Station :: removeFromStack()
{
	if(currentcar != -1 || mystack.size() == 0)
	{
		return false;
	}
	else
	{
	currentcar = mystack.top();
	mystack.pop();
	return true;
	}
}

int Station :: showTopOfStack()
{
	if (mystack.size() == 0)
	{
		return -1;
	}
	else
	{
	return mystack.top();
	}
}

int Station :: showSizeOfStack()
{
	return mystack.size();
}












bool Station :: addToQueue()
{
	if (currentcar == -1 || myqueue.SizeQueue() == 5)
	{
		return false;
	}
	else
	{
		myqueue.addQueue(currentcar);
		currentcar = -1;
		return true;
	}
}

bool Station :: removeFromQueue()
{
	if(currentcar != -1 || myqueue.SizeQueue() == 0)
	{
		return false;
	}
	else
	{
	currentcar = myqueue.TopQueue();
	myqueue.removeQueue();
	return true;
	}
}

int Station :: showTopOfQueue()
{
	if (myqueue.SizeQueue() == 0)
	{
		return -1;
	}
	else
	{
	return myqueue.TopQueue();
	}
}

int Station :: showSizeOfQueue()
{
	return myqueue.SizeQueue();
}
















bool Station :: addToDequeLeft()
{
	if (currentcar == -1 || mydeck.SizeDeque() == 5)
	{
		return false;
	}
	else
	{
		mydeck.addDequeLeft(currentcar);
		currentcar = -1;
		return true;
	}
}

bool Station :: addToDequeRight()
{
	if (currentcar == -1 || mydeck.SizeDeque() == 5)
	{
		return false;
	}
	else
	{
		mydeck.addDequeRight(currentcar);
		currentcar = -1;
		return true;
	}
}

bool Station :: removeFromDequeLeft()
{
	if(currentcar != -1 || mydeck.SizeDeque() == 0)
	{
		return false;
	}
	else
	{
	currentcar = mydeck.TopDequeLeft();
	mydeck.removeDequeLeft();
	return true;
	}
}

bool Station :: removeFromDequeRight()
{
	if(currentcar != -1 || mydeck.SizeDeque() == 0)
	{
		return false;
	}
	else
	{
	currentcar = mydeck.TopDequeRight();
	mydeck.removeDequeRight();
	return true;
	}
}

int Station :: showTopOfDequeLeft()
{
	if (mydeck.SizeDeque() == 0)
	{
		return -1;
	}
	else
	{
	return mydeck.TopDequeLeft();
	}
}

int Station :: showTopOfDequeRight()
{
	if (mydeck.SizeDeque() == 0)
	{
		return -1;
	}
	else
	{
	return mydeck.TopDequeRight();
	}
}

int Station :: showSizeOfDeque()
{
	mydeck.SizeDeque();
}












				 bool Station :: addToIRDequeLeft()
				 {
						if (currentcar == -1 || myir.sizeir() == 5)
						{
							return false;
						}
						else
						{
							myir.addirleft(currentcar);
							currentcar = -1;
							return true;
						}
				 }


				 bool Station :: removeFromIRDequeLeft()
				 {
					 if(currentcar != -1 || myir.sizeir() == 0)
					 	{
					 		return false;
					 	}
					 	else
					 	{
					 	currentcar = myir.topirleft();
					 	myir.removeirleft();
					 	return true;
					 	}
				 }


				 bool Station :: removeFromIRDequeRight()
				 {
						if(currentcar != -1 || myir.sizeir() == 0)
						{
							return false;
						}
						else
						{
						currentcar = myir.topirright();
						myir.removeirright();
						return true;
						}
				 }

				 int Station :: showTopOfIRDequeLeft()
				 {
					 if (myir.sizeir() == 0)
					 	{
					 		return -1;
					 	}
					 	else
					 	{
					 	return myir.topirleft();
					 	}
				 }


				 int Station :: showTopOfIRDequeRight()
				 {
						if (myir.sizeir() == 0)
						{
							return -1;
						}
						else
						{
						return myir.topirright();
						}
				 }


				 int Station :: showSizeOfIRDeque()
				 {
						myir.sizeir();
				 }








				 bool Station :: addToORDequeLeft()
				 {
						if (currentcar == -1 || myor.sizeor() == 5)
						{
							return false;
						}
						else
						{
							myor.addorleft(currentcar);
							currentcar = -1;
							return true;
						}
				 }


				 bool Station :: addToORDequeRight()
				 {
						if (currentcar == -1 || myor.sizeor() == 5)
						{
							return false;
						}
						else
						{
							myor.addorright(currentcar);
							currentcar = -1;
							return true;
						}
				 }


				 bool Station :: removeFromORDequeLeft()
				 {
					 if(currentcar != -1 || myor.sizeor() == 0)
					 	{
					 		return false;
					 	}
					 	else
					 	{
					 	currentcar = myor.toporleft();
					 	myor.removeorleft();
					 	return true;
					 	}
				 }

				 int Station :: showTopOfORDequeLeft()
				 {
					 if (myor.sizeor() == 0)
					 	{
					 		return -1;
					 	}
					 	else
					 	{
					 	return myor.toporleft();
					 	}
				 }


				 int Station :: showSizeOfORDeque()
				 {
						myor.sizeor();
				 }




















