/*
 * extra.h
 *
 *  Created on: Feb 27, 2015
 *      Author: spence13
 */


#pragma once
#include "LinkedList.h"


using namespace std;

class inputrestricted
{
public:
	inputrestricted();
	virtual ~inputrestricted();




	 bool addirleft(int alpha);

	 bool removeirleft();

	 bool removeirright();

	 int topirleft();

	 int topirright();

	 int sizeir();

	 bool contains(int bob);



private:
	 LinkedList <int> mylinkedlist;






};