/*
 * Arena.cpp
 *
 *  Created on: Jan 27, 2015
 *      Author: spence13
 */

#include <iostream>
#include<string>
#include <vector>
#include <sstream>
#include "Arena.h"
#include "Archer.h"
#include "Robot.h"
#include "Cleric.h"


using namespace std;

bool Arena :: addFighter(string info)
{
	istringstream ss;
	ss.str(info);

	string name;
	ss >> name;
	int i = 0;
	int found = 3;

						while ((i < list.size()) && (found == 3))
							{

								if (list[i]->getName() == name)
								{
									found = 2 ;
									return false;
								}
								else
								{
									i++ ;
								}
							}



							string type ;
							ss >> type ;

							int hp = 0;
							ss >> hp;
							if (hp <= 0)
							{
								return false ;
							}

							int strength = 0;
							ss >> strength ;
							if (strength <= 0)
							{
								return false;
							}

							int speed = 0;
							ss >> speed ;
							if (speed <= 0)
							{
								return false;
							}

							int magic = 0;
							ss >> magic ;
							if (magic <= 0)
							{
								return false ;
							}

							string test = "";
							ss >> test;
							if (test != "")
							{
								return false ;
							}

							if (type == "A")
							{
								FighterInterface * fighters = new Archer(name, hp, strength, speed, magic) ;
								list.push_back(fighters) ;
								return true;
							}
							else if (type == "R")
							{
								FighterInterface * fighters = new Robot(name, hp, strength, speed, magic) ;
								list.push_back(fighters) ;
								return true;
							}
							else if (type == "C")
							{
								FighterInterface * fighters = new Cleric(name, hp, strength, speed, magic) ;
								list.push_back(fighters) ;
								return true;
							}
							else
							{
								return false;
							}




}



bool Arena :: removeFighter(string name)
{
	int i = 0 ;
	int found = 3 ;
	    while (i < list.size() && (found == 3))
	    {
	        if (list[i]->getName() == name)
	        {
	            found = 2 ;
	            list.erase(list.begin() + i);
	            return true;
	        }
	        else
	        {
	            i++ ;
	        }
	    }

	    if (i == list.size())
	    {
	        return false ;
	    }
return false;      //add thissssssssssssssssssssssssssssssssssssssss

}


FighterInterface* Arena :: getFighter(string name)
{
	int i = 0 ;

	    while (i < list.size())
	    {
	        if (name == list[i]->getName())
	        {
	            FighterInterface * address = list[i] ;
	            return address ;
	        }
	        else if (name != list[i]->getName())
	        {
	            i++ ;
	        }
	    }


	    if (i == list.size())
	    {
	        return NULL ;
	    }
return NULL; //ssssssssssssssssssssssssssssssssssssssssssssssssssss

}


int Arena :: getSize()
{
	int size = list.size();

	return size;
}


