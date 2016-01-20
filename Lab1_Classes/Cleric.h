/*
 * Cleric.h
 *
 *  Created on: Jan 27, 2015
 *      Author: spence13
 */
#pragma once
#include "Fighter.h"

class Cleric : public Fighter
{

	public:
		Cleric(string name, int hp, int strength, int speed, int magic);
		virtual ~Cleric();

		int getDamage();
		void reset();
		void regenerate();
		bool useAbility();



private:

		int maxmana;
		int currentmana;



};
