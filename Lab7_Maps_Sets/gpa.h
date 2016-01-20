/*
 * gpa.h
 *
 *  Created on: Mar 26, 2015
 *      Author: spence13
 */

#pragma once
#include "GPAInterface.h"
#include "student.h"


using namespace std;

class gpa : public GPAInterface
{

public:
	gpa();
	virtual ~gpa();


	virtual map<unsigned long long int,StudentInterface*> getMap();

	virtual set<StudentInterface*,Comparator> getSet();

	virtual bool importStudents(string mapFileName, string setFileName);

	virtual bool importGrades(string fileName);

	virtual string querySet(string fileName);

	virtual string queryMap(string fileName);

	virtual void clear();

	virtual bool check(string bob);

	virtual bool chex(string mary);






private:

	set<StudentInterface*, Comparator> myset;
	map<unsigned long long int, StudentInterface* > mymap;












};