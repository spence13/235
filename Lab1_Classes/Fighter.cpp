/*
 * Fighter.cpp
 *
 *  Created on: Jan 27, 2015
 *      Author: spence13
 */



#include "Fighter.h"


using namespace std;

			Fighter :: Fighter (string name, int hp, int strength, int speed, int magic)
			{
				this->name = name;
				this->hp = hp;
				this->strength = strength;
				this->speed = speed;
				this->magic = magic;
				currenthp = hp;



			}
			Fighter :: ~Fighter()
			{

			}



				string Fighter :: getName()
				 {
					 return name;
				 }


				 int Fighter :: getMaximumHP()
				 {
					return hp;
				 }


				 int Fighter :: getCurrentHP()
				 {
					 return currenthp;
				 }


				 int Fighter :: getStrength()
				 {
					 return strength;
				 }


				 int Fighter :: getSpeed()
				 {
					 return speed;
				 }

				 int Fighter :: getMagic()
				 {
					 return magic;
				 }

				 int Fighter :: getDamage()
				 {
					 return 0;
				 }

				 void Fighter :: takeDamage(int damage)
				 {
					 int inflicted;
				     inflicted = damage - (speed/4) ;
					  if (inflicted >= 1)
					  {
					      currenthp = currenthp - inflicted ;
					  }
					  else if (inflicted == 0)
					  {
						 currenthp-- ;
					  }
				 }

				 /* void Fighter :: reset()
				 {

				 }*/

				 void Fighter :: regenerate()
				 {
					int regeneration = (strength/6);
						if( regeneration >= 1)
						{
							currenthp = currenthp + regeneration;
						}

						else if (regeneration == 0)
						{
							currenthp++;
						}
						if (currenthp > hp)
						{
							currenthp = hp;
						}
				 }

				 /*bool Fighter :: useAbility()
				 {
					 return 0;
				 }*/



