/*
 * pathfinder.cpp
 *
 *  Created on: Mar 10, 2015
 *      Author: spence13
 */
#include "pathfinder.h"


using namespace std;


pathfinder :: pathfinder()
{
	srand(time(0));



	for(int g = 0; g<5 ; g++)
	{
		for(int k = 0; k<5; k++)
		{
			for (int i = 0; i<5; i++)
			{
				currentmaze [g][k][i] = 1;
			}
		}
	}

}

pathfinder :: ~pathfinder()
{

}


string pathfinder :: getMaze()
{
	string awesome;

	for(int g = 0; g<5 ; g++)
	{
		for(int k = 0; k<5; k++)
		{
			for (int i = 0; i<5; i++)
			{

					stringstream ss;
					ss << currentmaze[g][k][i];
					string temp = "";
					ss >> temp;
					if(i==4)
					{
						awesome = awesome + temp +"\n";
					}
					else
					{
						awesome = awesome + temp + " ";
					}

			}
		}
		awesome = awesome + "\n\n";
	}

	return awesome;
}

void pathfinder :: createRandomMaze()
{
	int maze [5][5][5];
	string mazenumbers = "";

	for(int g = 0; g<5 ; g++)
	{
		for(int k = 0; k<5; k++)
		{
			for (int i = 0; i<5; i++)
			{
				if(g==0 && k==0 && i==0)
				{
					maze[g][k][i] = 1;
				}
				else if(g==4 && k==4 && i==4)
				{
					maze[g][k][i] = 1;
				}
				else
				{
					int randnum = rand() % 2;
					maze[g][k][i] = randnum;
				}
			}
		}
	}

	for(int g = 0; g<5 ; g++)
	{
		for(int k = 0; k<5; k++)
		{
			for (int i = 0; i<5; i++)
			{
				currentmaze [g][k][i] = maze[g][k][i];
			}
		}
	}


}

bool pathfinder :: importMaze(string file_name)
{
	int tempcurrentmaze [5][5][5];
	for(int g = 0; g<5 ; g++)
	{
		for(int k = 0; k<5; k++)
		{
			for (int i = 0; i<5; i++)
			{
				tempcurrentmaze [g][k][i] = 1;
			}
		}
	}
	ifstream input;
	input.open(file_name.c_str());
	int bob;

	if (input.fail())
	{
		return false;
	}

	else
	{
		for(int g = 0; g<5 ; g++)
		{
			for(int k = 0; k<5; k++)
			{
				for (int i = 0; i<5; i++)
				{
				  if(input >> bob)
				  {
					if(g==0 && k==0 && i==0 )
					{
						if(bob != 1)
						{
							return false;
						}
					}
					else if(g==4 && k==4 && i==4 )
					{
						if(bob != 1)
						{
							return false;
						}
					}
					else if(bob == 0 || bob == 1)
					{
						tempcurrentmaze[g][k][i] = bob;

					}
					else
					{
						return false;
					}
				  }
				  else
				  {
					  return false;
				  }
				}
			}
		}


	}
	if (input >>bob)//check to see if there are any leftovers in txt
	{
		return false;
	}
	input.close();

	for(int g = 0; g<5 ; g++)
	{
		for(int k = 0; k<5; k++)
		{
			for (int i = 0; i<5; i++)
			{
				currentmaze [g][k][i] = tempcurrentmaze[g][k][i];
			}
		}
	}

	return true;
}








vector<string> pathfinder :: solveMaze()
{
	path.clear();
	int temp [5][5][5];

	for(int g = 0; g<5 ; g++)
	{
		for(int k = 0; k<5; k++)
		{
			for (int i = 0; i<5; i++)
			{
				temp [g][k][i] = currentmaze[g][k][i];
			}
		}
	}


	int a=0;
	int b=0;
	int c=0;

	findit(a,b,c,temp);


		reverse(path.begin(), path.end());
		return path;


}

bool pathfinder :: findit(int x, int y, int z, int tempcurrentmaze[5][5][5])
{


	if (x==4 && y==4 && z==4)
	{
		stringstream sx;
		stringstream sy;
		stringstream sz;
		sx << x;
		sy << y;
		sz << z;
		string posx;
		string posy;
		string posz;
		sx >> posx;
		sy >> posy;
		sz >> posz;
		string ya = "(" + posx + ", " + posy + ", " + posz +")";

		path.push_back(ya);

		return true;

	}







else
{

	if((x+1)<5)
	{
		if(tempcurrentmaze[x+1][y][z] == 1)
		{
			tempcurrentmaze[x][y][z] = 2;

			if(findit(x+1,y,z, tempcurrentmaze))
			{

				stringstream sx;
				stringstream sy;
				stringstream sz;
				sx << x;
				sy << y;
				sz << z;
				string posx;
				string posy;
				string posz;
				sx >> posx;
				sy >> posy;
				sz >> posz;
				string ya = "(" + posx + ", " + posy + ", " + posz +")";

				path.push_back(ya);

				return true;
			}
			else
			{
				//return false;
			}
		}
	}
	if((y-1)>-1)
	{

			if(tempcurrentmaze[x][y-1][z] == 1)
			{
				tempcurrentmaze[x][y][z] = 2;

				if(findit(x,y-1,z, tempcurrentmaze))
				{

					stringstream sx;
					stringstream sy;
					stringstream sz;
					sx << x;
					sy << y;
					sz << z;
					string posx;
					string posy;
					string posz;
					sx >> posx;
					sy >> posy;
					sz >> posz;
					string ya = "(" + posx + ", " + posy + ", " + posz +")";

					path.push_back(ya);

					return true;
				}
				else
				{
					//return false;
				}

			}
	}
		if((x-1)>-1)
		{
				if(tempcurrentmaze[x-1][y][z] == 1)
				{
					tempcurrentmaze[x][y][z] = 2;

					if(findit(x-1,y,z, tempcurrentmaze))
					{

						stringstream sx;
						stringstream sy;
						stringstream sz;
						sx << x;
						sy << y;
						sz << z;
						string posx;
						string posy;
						string posz;
						sx >> posx;
						sy >> posy;
						sz >> posz;
						string ya = "(" + posx + ", " + posy + ", " + posz +")";

						path.push_back(ya);

						return true;
					}
					else
					{
						//return false;
					}

				}
		}
			if((y+1)<5)
			{
					if(tempcurrentmaze[x][y+1][z] == 1)
					{
						tempcurrentmaze[x][y][z] = 2;

						if(findit(x,y+1,z, tempcurrentmaze))
						{

							stringstream sx;
							stringstream sy;
							stringstream sz;
							sx << x;
							sy << y;
							sz << z;
							string posx;
							string posy;
							string posz;
							sx >> posx;
							sy >> posy;
							sz >> posz;
							string ya = "(" + posx + ", " + posy + ", " + posz +")";

							path.push_back(ya);

							return true;
						}
						else
						{
							//return false;
						}
					}
			}
				if((z+1)<5)
				{
						if(tempcurrentmaze[x][y][z+1] == 1)
						{
							tempcurrentmaze[x][y][z] = 2;

							if(findit(x,y,z+1, tempcurrentmaze))
							{

								stringstream sx;
								stringstream sy;
								stringstream sz;
								sx << x;
								sy << y;
								sz << z;
								string posx;
								string posy;
								string posz;
								sx >> posx;
								sy >> posy;
								sz >> posz;
								string ya = "(" + posx + ", " + posy + ", " + posz +")";

								path.push_back(ya);

								return true;
							}
							else
							{
								//return false;
							}
						}
				}
					if((z-1)>-1)
					{
							if(tempcurrentmaze[x][y][z-1] == 1)
							{
								tempcurrentmaze[x][y][z] = 2;

								if(findit(x,y,z-1, tempcurrentmaze))
								{

									stringstream sx;
									stringstream sy;
									stringstream sz;
									sx << x;
									sy << y;
									sz << z;
									string posx;
									string posy;
									string posz;
									sx >> posx;
									sy >> posy;
									sz >> posz;
									string ya = "(" + posx + ", " + posy + ", " + posz +")";

									path.push_back(ya);

									return true;
								}
								else
								{
									//return false;
								}
							}
					}


	if((x+1)<5)
	{
		if(tempcurrentmaze[x+1][y][z] == 2)
		{
			//tempcurrentmaze[x][y][z] = 3;

			return false;
		}
	}
	if((y-1)>-1)
	{

			if(tempcurrentmaze[x][y-1][z] == 2)
			{
				//tempcurrentmaze[x][y][z] = 3;

				return false;
			}
	}
		if((x-1)>-1)
		{
				if(tempcurrentmaze[x-1][y][z] == 2)
				{
					//tempcurrentmaze[x][y][z] = 3;

					return false;
				}
		}
			if((y+1)<5)
			{
					if(tempcurrentmaze[x][y+1][z] == 2)
					{
						//tempcurrentmaze[x][y][z] = 3;

						return false;
					}
			}
				if((z+1)<5)
				{
						if(tempcurrentmaze[x][y][z+1] == 2)
						{
							//tempcurrentmaze[x][y][z] = 3;

							return false;
						}
				}
					if((z-1)>-1)
					{
							if(tempcurrentmaze[x][y][z-1] == 2)
							{
								//tempcurrentmaze[x][y][z] = 3;

								return false;
							}
					}

}


	return true;




}













