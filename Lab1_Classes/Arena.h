/*
 * Arena.h
 *
 *  Created on: Jan 27, 2015
 *      Author: spence13
 */

#pragma once
#include "ArenaInterface.h"

using namespace std;

class Arena : public ArenaInterface
{
private:
	vector <FighterInterface*> list;
public:
	Arena(){}
	virtual ~Arena(){}

	bool addFighter(string info);
	bool removeFighter(string name);
	FighterInterface* getFighter(string name);
	int getSize();





};

