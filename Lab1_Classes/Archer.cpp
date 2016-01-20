/*
 * Archer.cpp
 *
 *  Created on: Jan 27, 2015
 *      Author: spence13
 */

#include "Archer.h"


using namespace std;


Archer :: Archer ( string name, int hp, int strength, int speed, int magic) : Fighter (name, hp, strength, speed, magic)
{
	currentspeed = speed;
}
Archer :: ~Archer()
{

}



int Archer :: getDamage()
{

	int damage = currentspeed;
	return damage;
}


void Archer :: takeDamage(int damage)
				 {
					 int inflicted;
				     inflicted = damage - (currentspeed/4) ;
					  if (inflicted >= 1)
					  {
					      currenthp = currenthp - inflicted ;
					  }
					  else if (inflicted == 0)
					  {
						 currenthp-- ;
					  }
				 }





int Archer :: getSpeed()
{
	return currentspeed;
}

void Archer :: reset()
{

	currenthp = hp;
	currentspeed = speed;

}

bool Archer :: useAbility()
{
	currentspeed++;
	return true;

}



