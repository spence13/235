/*
 * qs.h
 *
 *  Created on: Apr 7, 2015
 *      Author: spence13
 */

#pragma once
#include "QSInterface.h"
#include <sstream>

using namespace std;

class qs : public QSInterface
{
public:
	qs();
	virtual ~qs();


		virtual void sortAll();

		virtual int medianOfThree(int left, int right);

		virtual int partition(int left, int right, int pivotIndex);

		virtual string getArray();

		virtual int getSize();

		virtual void addToArray(int value);

		virtual bool createArray(int capacity);

		virtual void clear();

		virtual void recursion(int left, int right);


private:
		int * a;
		int size;
		int maxcapacity;



};