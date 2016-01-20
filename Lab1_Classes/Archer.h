/*
 * Archer.h
 *
 *  Created on: Jan 27, 2015
 *      Author: spence13
 */

#pragma once
#include "Fighter.h"


class Archer : public Fighter
{

	public:
		Archer(string name, int hp, int strength, int speed, int magic);
		virtual ~Archer();

		int getDamage();
		void reset();
		bool useAbility();
		int getSpeed();
		void takeDamage(int Damage);


private:
		int currentspeed;





};