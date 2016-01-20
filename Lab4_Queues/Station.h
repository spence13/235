/*
 * Station.h
 *
 *  Created on: Feb 23, 2015
 *      Author: spence13
 */

#pragma once
//#include "StationInterface.h"
#include "StationInterfaceExtra.h"
#include "Stack.h"
#include "Dequeue.h"
#include "Queue.h"
#include "inputrestricted.h"
#include "outputrestricted.h"

using namespace std;


class Station : public StationInterfaceExtra
{

public:
	Station();
	virtual ~Station();



			 virtual bool addToStation(int car);

			 virtual int showCurrentCar();

			 virtual bool removeFromStation();



			 virtual bool addToStack();

			 virtual bool removeFromStack();

			 virtual int showTopOfStack();

			 virtual int showSizeOfStack();



			 virtual bool addToQueue();

			 virtual bool removeFromQueue();

			 virtual int showTopOfQueue();

			 virtual int showSizeOfQueue();



			 virtual bool addToDequeLeft();

			 virtual bool addToDequeRight();

			 virtual bool removeFromDequeLeft();

			 virtual bool removeFromDequeRight();

			 virtual int showTopOfDequeLeft();

			 virtual int showTopOfDequeRight();

			 virtual int showSizeOfDeque();




			 	 	virtual bool addToIRDequeLeft();


					virtual bool removeFromIRDequeLeft();


					virtual bool removeFromIRDequeRight();

					virtual int showTopOfIRDequeLeft();


					virtual int showTopOfIRDequeRight();


					virtual int showSizeOfIRDeque();








					virtual bool addToORDequeLeft();


					virtual bool addToORDequeRight();


					virtual bool removeFromORDequeLeft();

					virtual int showTopOfORDequeLeft();


					virtual int showSizeOfORDeque();












private:

			 int currentcar;
			 Stack mystack;
			 Queue myqueue;
			 Dequeue mydeck;
			 inputrestricted myir;
			 outputrestricted myor;




};