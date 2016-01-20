/*
 * Cleric.cpp
 *
 *  Created on: Jan 27, 2015
 *      Author: spence13
 */


#include "Cleric.h"


using namespace std;


Cleric :: Cleric ( string name, int hp, int strength, int speed, int magic) : Fighter (name, hp, strength, speed, magic)
{

	maxmana = magic*5;
	currentmana = magic*5;
}
Cleric :: ~Cleric()
{

}



int Cleric :: getDamage()
{

	int damage = magic;
	return damage;



}

void Cleric :: regenerate()
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

	int increase = magic/5;

			if (increase >= 1)
			{
				currentmana = currentmana +increase;
			}
			else if (increase == 0)
			{
				currentmana++;
			}


			if (currentmana > maxmana)
			{
				currentmana = maxmana;
			}

}



void Cleric :: reset()
{
	currenthp = hp;
	currentmana = maxmana;
}


bool Cleric :: useAbility()
{



	if (currentmana >= CLERIC_ABILITY_COST)
	{
		int bonus = magic/3;

		if(bonus >= 1)
		{
			currenthp = currenthp + bonus;
		}

		if (bonus == 0)
		{
			currenthp++;
		}

		if (currenthp > hp)
		{
			currenthp = hp;
		}

		currentmana = currentmana - CLERIC_ABILITY_COST;
		return true;
	}

	else
	{
		return false;
	}


}


