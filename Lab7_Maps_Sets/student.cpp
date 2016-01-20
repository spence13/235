/*
 * student.cpp
 *
 *  Created on: Mar 26, 2015
 *      Author: spence13
 */



#include "student.h"

using namespace std;

student :: student(unsigned long long int id, string name, string address, string phone)
{


	this->id = id;
	this->name = name;
	this->address = address;
	this->phone = phone;

	this->numberofclasses = 0.0;
	this->runningtotal = 0.0;

}
student :: ~student()
{

}

unsigned long long int student :: getID()
{

	return id;
}


string student :: getName()
{
	return name;
}


string student :: getGPA()
{
	if (numberofclasses == 0.0)
	{
		return "0.00";
	}
	stringstream ss;
	ss << fixed << setprecision(2) << runningtotal/numberofclasses;
	string gpa ;
	ss >> gpa;
	return gpa;

}


void student :: addGPA(double classGrade)
{
runningtotal = runningtotal + classGrade;
numberofclasses++;
	getGPA();
}


string student :: toString()
{
stringstream ss;
ss << id;
string newstudent;
ss >> newstudent;

newstudent = newstudent + "\n" + name + "\n" + address + "\n" + phone + "\n" + getGPA();

return newstudent;
}








