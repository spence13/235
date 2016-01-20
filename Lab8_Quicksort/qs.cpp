/*
 * qs.cpp
 *
 *  Created on: Apr 7, 2015
 *      Author: spence13
 */

#include "qs.h"

using namespace std;

qs :: qs()
{
	a = NULL;
	size = 0;
	maxcapacity = 0;
}
qs :: ~qs()
{
	clear();
}

void qs :: sortAll()
{
	recursion(0, size-1);
}

int qs :: medianOfThree(int left, int right)
{
	if(left >= right || left < 0 || right < 0 || left > (size-1) || right > (size-1) || size == 0)
	{
		return -1;
	}
	else
	{
		int middle = (left + right) / 2;

		if(a[left] > a[middle])
		{
			int dummy = a[left];
			a[left] = a[middle];
			a[middle] = dummy;

			if(a[middle] > a[right])
			{
				int dummy = a[middle];
				a[middle] = a[right];
				a[right] = dummy;

				if(a[left] > a[middle])
				{
					int dummy = a[left];
					a[left] = a[middle];
					a[middle] = dummy;
				}
			}
		}

		if(a[middle] > a[right])
		{
			int dummy = a[middle];
			a[middle] = a[right];
			a[right] = dummy;

			if(a[left] > a[middle])
			{
				int dummy = a[left];
				a[left] = a[middle];
				a[middle] = dummy;
			}
		}

		return middle;
	}
}

int qs :: partition(int left, int right, int pivotIndex)
{
	if(left >= right || left < 0 || right < 0 || pivotIndex >= right || pivotIndex <= left || left > (size-1) || right > (size-1) || a == NULL)
	{
		return -1;
	}

	int dummy = a[pivotIndex];
	a[pivotIndex] = a[right];
	a[right] = dummy;

	int i = left;
	int j = right-1;

	while (i < j)
	{
		while (a[i] < a[right])
		{
			i++;
		}

		while (a[j] > a[right])
		{
			j--;
		}
		int dummy = a[i];
		a[i] = a[j];
		a[j] = dummy;
	}

	int hello = a[i];
	a[i] = a[right];
	a[right] = hello;

	int again = a[j];
	a[j] = a[right];
	a[right] = again;

	return i;

}

string qs :: getArray()
{
	string array = "";
	if(size == 0)
	{
		return array;
	}

	int counter = 0;

	while (counter < size)
	{
		if (counter == 0)
		{
			stringstream ss;
			ss << a[counter];
			string temp;
			ss >> temp;
			array = array + temp;
			counter++;

		}
		else if (counter != 0)
		{
			stringstream ss;
			ss << a[counter];
			array = array + ",";
			string temp;
			ss >> temp;
			array = array + temp;
			counter++;
		}
	}

	return array;

}

int qs :: getSize()
{
	return size;
}

void qs :: addToArray(int value)
{
	if(size < maxcapacity)
	{
		a[size] = value;
		size++;

	}
}

bool qs :: createArray(int capacity)
{
	if(capacity < 0)
	{
		return false;
	}
	else if(a == NULL)
	{
		clear();
		a = new int [capacity];
		maxcapacity = capacity;
		return true;
	}
	else
	{
		a = new int [capacity];
		maxcapacity = capacity;
		return true;
	}
}

void qs :: clear()
{
	delete[] a;
	a = NULL;
	maxcapacity = 0;
	size = 0;
}

void qs :: recursion(int left, int right)
{
	if(left >= right || left < 0 || right < 0 || left > (size-1) || right > (size-1) || size == 0)
	{
		return;
	}

	if(left == right)
	{
		return;
	}

	if((left+1) == right)
	{
		if(a[left] > a[right])
		{
			int dummy = a[left];
			a[left] = a[right];
			a[right] = dummy;
			return;
		}
		return;
	}
	if((left + 2) == right)
	{
		medianOfThree(left, right);
		return;
	}

	else
	{
		int x = medianOfThree(left, right);
		int y = partition(left, right, x);
		recursion(left, y-1);
		recursion(y+1,right);
		return;
	}
}









