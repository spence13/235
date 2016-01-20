/*
 * pathfinder.h
 *
 *  Created on: Mar 10, 2015
 *      Author: spence13
 */
#pragma once
 #include <cstdlib>
#include "PathfinderInterface.h"
#include <sstream>
#include <algorithm>
#include <fstream>


using namespace std;


class pathfinder : public PathfinderInterface
{

public:
	pathfinder();
	virtual ~pathfinder();

			virtual string getMaze();

			virtual void createRandomMaze();

			virtual bool importMaze(string file_name);

			virtual vector<string> solveMaze();

			bool findit(int x, int y, int z, int tempcurrentmaze [5][5][5]);




private:



			int currentmaze [5][5][5] ;

			vector<string> path;





};