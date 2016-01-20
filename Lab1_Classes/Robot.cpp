/*
 * Robot.cpp
 *
 *  Created on: Jan 27, 2015
 *      Author: spence13
 */


#include "Robot.h"
#include <cmath>

using namespace std;


Robot :: Robot ( string name, int hp, int strength, int speed, int magic) : Fighter (name, hp, strength, speed, magic)
{
	//maxenergy = magic*2	;
	currentenergy = magic * 2;
	bonusdamage = 0;

}
Robot :: ~Robot()
{

}



int Robot :: getDamage()
{

	int damage = strength + bonusdamage;
	bonusdamage = 0;
	return damage;


}




void Robot :: reset()
{

	currenthp = hp;
	currentenergy = magic * 2;
	bonusdamage = 0;

}

bool Robot :: useAbility()
{
	if(currentenergy >= ROBOT_ABILITY_COST)
	{
		double doublecurrentenergy = currentenergy;
		double doublemaxenergy = magic *2;
		double multiplier = pow ( (doublecurrentenergy/doublemaxenergy), 4.0);
		bonusdamage =  strength * multiplier;


		currentenergy = currentenergy - ROBOT_ABILITY_COST;
		return true;
	}

	else
	{
		return false;
	}

}


