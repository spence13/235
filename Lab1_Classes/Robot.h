/*
 * Robot.h
 *
 *  Created on: Jan 27, 2015
 *      Author: spence13
 */

#pragma once
#include "Fighter.h"

class Robot : public Fighter
{

	public:
		Robot(string name, int hp, int strength, int speed, int magic);
		virtual ~Robot();

		int getDamage();
		void reset();
		bool useAbility();


private:

		int currentenergy;
		//int maxenergy;
		int bonusdamage;




};
