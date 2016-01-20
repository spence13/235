/*
 * Fighter.h
 *
 *  Created on: Jan 27, 2015
 *      Author: spence13
 */

#pragma once
#include "FighterInterface.h"


using namespace std;


class Fighter : public FighterInterface
{




	public:
				Fighter(string name, int hp, int strength, int speed, int magic);
				virtual ~Fighter();


				 string getName() ;
				 int getMaximumHP();
				 int getCurrentHP() ;
				 int getStrength() ;
				virtual int getSpeed();
				 int getMagic() ;
				virtual int getDamage() ;
				 virtual void takeDamage(int damage) ;
				virtual void reset()=0;
				virtual void regenerate();
				virtual bool useAbility() = 0;


	protected:
				 string name;
				 int hp;
				 int strength;
				 int speed;
				 int magic;

				 int currenthp;


};
