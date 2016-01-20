/*
 * shuntingyard.h
 *
 *  Created on: Feb 13, 2015
 *      Author: spence13
 */

#pragma once
#include "ExpressionManagerInterface.h"


using namespace std;

class shuntingyard : public ExpressionManagerInterface
{



	private:


	public:
		shuntingyard(){}
		virtual ~shuntingyard(){}


		 bool isBalanced(string expression);
		 string postfixToInfix(string postfixExpression);
		 string infixToPostfix(string infixExpression);
		 string postfixEvaluate(string postfixExpression);


};