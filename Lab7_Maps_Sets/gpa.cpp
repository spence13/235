/*
 * gpa.cpp
 *
 *  Created on: Mar 26, 2015
 *      Author: spence13
 */


#include "gpa.h"

using namespace std;

gpa :: gpa()
{


}
gpa :: ~gpa()
{
	clear();
}

map<unsigned long long int,StudentInterface*> gpa :: getMap()
{
	return mymap;
}

set<StudentInterface*,Comparator> gpa :: getSet()
{
	return myset;
}

bool gpa :: importStudents(string mapFileName, string setFileName)
{
	if (check(mapFileName) && check(setFileName))
	{
		ifstream inputset;
		inputset.open(setFileName.c_str());
		while(!inputset.eof())
			{
			string tempid;
			getline(inputset, tempid);
			string name;
			getline(inputset, name);
			string address;
			getline(inputset, address);
			string phone;
			getline(inputset, phone);

			stringstream ss;
			ss << tempid;
			unsigned long long int id;
			ss >> id;

			myset.insert(new student(id, name, address, phone));
			inputset.peek();
			}
			inputset.close();


			ifstream input;
			input.open(mapFileName.c_str());
			while(!input.eof())
				{
				string tempid;
				getline(input, tempid);
				string name;
				getline(input, name);
				string address;
				getline(input, address);
				string phone;
				getline(input, phone);

				stringstream ss;
				ss << tempid;
				unsigned long long int id;
				ss >> id;

				mymap[id] = new student(id, name, address, phone);
				input.peek();
				}
				input.close();
		return true;
	}

	else
	{
		return false;
	}



}

bool gpa :: importGrades(string fileName)
{
	if(chex(fileName))
	{
		ifstream input;
		input.open(fileName.c_str());
		while(!input.eof())
			{
			string tempid;
			getline(input, tempid);
			string classe;
			getline(input, classe);
			string lettergrade;
			getline(input, lettergrade);

			double pointgrade = 0.0;

			if(lettergrade == "A")
			{
				pointgrade = 4.0;
			}
			if(lettergrade == "A-")
			{
				pointgrade = 3.7;
			}
			if(lettergrade == "B+")
			{
				pointgrade = 3.4;
			}
			if(lettergrade == "B")
			{
				pointgrade = 3.0;
			}
			if(lettergrade == "B-")
			{
				pointgrade = 2.7;
			}
			if(lettergrade == "C+")
			{
				pointgrade = 2.4;
			}
			if(lettergrade == "C")
			{
				pointgrade = 2.0;
			}
			if(lettergrade == "C-")
			{
				pointgrade = 1.7;
			}
			if(lettergrade == "D+")
			{
				pointgrade = 1.4;
			}
			if(lettergrade == "D")
			{
				pointgrade = 1.0;
			}
			if(lettergrade == "D-")
			{
				pointgrade = 0.7;
			}
			if(lettergrade == "E")
			{
				pointgrade = 0.0;
			}

			stringstream ss;
			ss << tempid;
			unsigned long long int id;
			ss >> id;

				for (pair<unsigned long long int, StudentInterface*> m : mymap)
				{
					if(m.first == id)
					{
						m.second->addGPA(pointgrade);
					}
				}

				for (StudentInterface* si : myset)
				{
					if(si->getID() == id)
					{
						si->addGPA(pointgrade);
					}
				}

			input.peek();
			}

	input.close();
	}



	else
	{
		return false;
	}



}

string gpa :: querySet(string fileName)
{
	string ultimate;

	ifstream input;
	input.open(fileName.c_str());
	if (input.fail())
	{
		return ultimate;
	}
	while(!input.eof())
		{
		string tempid;
		getline(input, tempid);

		stringstream ss;
		ss << tempid;
		unsigned long long int id;
		ss >> id;



			for (StudentInterface* si : myset)
			{
				if(si->getID() == id)
				{
					stringstream sas;
					string newid;
					sas << si->getID();
					sas >> newid;

					ultimate = ultimate + newid + " " + si->getGPA() + " " + si->getName() + "\n";
				}
			}


		input.peek();
		}
	input.close();


	return ultimate;



}

string gpa :: queryMap(string fileName)
{
	string ultimate;

	ifstream input;
	input.open(fileName.c_str());
	if (input.fail())
	{
		return ultimate;
	}
	while(!input.eof())
		{
		string tempid;
		getline(input, tempid);

		stringstream ss;
		ss << tempid;
		unsigned long long int id;
		ss >> id;


		for (pair<unsigned long long int, StudentInterface*> m : mymap)
			{
				if(m.first == id)
				{
					stringstream sas;
					string newid;
					sas << m.second->getID();
					sas >> newid;
					ultimate = ultimate + newid + " " + m.second->getGPA() + " " + m.second->getName() + "\n";
				}
			}


		input.peek();
		}
	input.close();


	return ultimate;

}

void gpa :: clear()
{
	for (pair<unsigned long long int, StudentInterface*> m : mymap)
	{
		delete m.second;
	}
	mymap.clear();

	for (StudentInterface* si : myset)
	{
		delete si;
	}
	myset.clear();






}


bool gpa :: check(string bob)
{
	ifstream input;
	input.open(bob.c_str());

		string line;
		int counter = 0;
		while (getline(input, line))
		{
			counter++;
			input.peek();
		}
	    input.close();

		if(counter == 0)
		{
			return false;
		}
	    if (counter % 4 == 0)
	    {
	    	return true;
	    }
	    else
	    {
	    	return false;
	    }
}

bool gpa :: chex(string mary)
{
	ifstream input;
	input.open(mary.c_str());

	string line;
	int counter = 0;
	while (getline(input, line))
	{
		counter++;
		input.peek();
	}
	input.close();

	if(counter == 0)
	{
		return false;
	}

	if (counter % 3 == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}




