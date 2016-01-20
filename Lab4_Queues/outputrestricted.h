/*
 * outputrestricted.h
 *
 *  Created on: Feb 27, 2015
 *      Author: spence13
 */

#pragma once
#include "LinkedList.h"


using namespace std;

class outputrestricted
{
public:
	outputrestricted();
	virtual ~outputrestricted();




	 bool addorleft(int alpha);

	 bool addorright(int beta);

	 bool removeorleft();

	 int toporleft();

	 int sizeor();

	 bool contains(int bob);



private:
	 LinkedList <int> mylinkedlist;






};