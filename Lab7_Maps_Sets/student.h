/*
 * student.h
 *
 *  Created on: Mar 26, 2015
 *      Author: spence13
 */

#pragma once
#include "StudentInterface.h"
#include <iomanip>
#include <sstream>
#include <iostream>
#include <fstream>
#include <sstream>
//#include "gpa.h"

using namespace std;

class student : public StudentInterface
{
public:
	student(unsigned long long int id, string name, string address, string phone);
	virtual ~student();


	virtual unsigned long long int getID();


	virtual string getName();


	virtual string getGPA();


	virtual void addGPA(double classGrade) ;


	virtual string toString();




private:

unsigned long long int id;
string name;
string address;
string phone;

double numberofclasses;
double runningtotal;









};