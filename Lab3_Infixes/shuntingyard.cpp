/*
 * shuntingyard.cpp
 *
 *  Created on: Feb 13, 2015
 *      Author: spence13
 */

#include "shuntingyard.h"

using namespace std;



	/*
	* Checks whether an expression is balanced on its parentheses
	*
	* - The given expression will have a space between every number or operator
	*
	* @return true if expression is balanced
	* @return false otherwise
	*/

 bool shuntingyard :: isBalanced(string expression)
{
	 stack <string> barrel;

	 stringstream ss;
	 ss << expression;

	 string var;
	 while (ss >> var)
	 {

		 if ( var == "(" || var == "{" || var == "[")
		 {
			 barrel.push(var);

		 }
		 else if(var == ")" || var == "}" || var == "]")
		 {
			 if (barrel.empty())
			 {
			 return false;
			 }

			 if ((barrel.top() == "(" && var == ")") || (barrel.top() == "{" && var == "}") || (barrel.top() == "[" && var == "]"))
			 {
				 	barrel.pop();

			 }

			 else
			 {
				 return false;
			 }
		 }

	 }

	 if (barrel.empty())
	 {
		 return true;
	 }
	 if (!barrel.empty())
	 {
		 return false;
	 }


}

	/**
	 * Converts a postfix expression into an infix expression
	 * and returns the infix expression.
	 *
	 * - The given postfix expression will have a space between every number or operator.
	 * - The returned infix expression must have a space between every number or operator.
	 * - Redundant parentheses are acceptable i.e. ( ( 3 * 4 ) + 5 ).
	 * - Check lab requirements for what will be considered invalid.
	 *
	 * return the string "invalid" if postfixExpression is not a valid postfix expression.
	 * otherwise, return the correct infix expression as a string.
	 */
 string shuntingyard :: postfixToInfix(string postfixExpression)
{
	 stack <string> barrel;

		 	 stringstream ss;
		 	 ss << postfixExpression;

		 	 string var;
		 	 string infix = "";

		 	 string priority = "";
		 	 int numbers = 0;
		 	 int operators = 0;

		  while (ss >> var)
		  {
			 string left = "";
		 	 string right = "";
		 	 string putback = "";

			  for(int i= 0; i <= var.size(); i++)
			  {
			 	 if ( var[i]== '.')
			 	  {
			 	 	 return "invalid";
			 	  }
			  }
			  if(isdigit(var[0]) || var == "(" || var== ")" || var== "{" || var== "}" || var== "[" || var== "]" || var== "*" || var== "/" || var== "%" || var== "+" || var== "-")
			  {
				  if (isdigit(var[0]))
				  {
					  numbers++;
					  barrel.push(var);
				  }
				  if (var == "*" || var == "%" || var == "/" || var == "+" || var == "-")
				  {
					  operators++;
					  if (!barrel.empty())
					  {
					  right = barrel.top();
					  barrel.pop();
					  }
					  else
					  {
						  return "invalid";
					  }
					  if (!barrel.empty())
					  {
					  left = barrel.top();
					  barrel.pop();
					  }
					  else
					  {
						  return "invalid";
					  }
					  putback = "( " + left  + " " + var + " " + right  +  " )";
					  barrel.push(putback);
				  }
			  }
			  else
			  {
				  return "invalid";
			  }
		  }

		  if (!barrel.empty())
		  {
			  infix = barrel.top();
		  }



		  if (numbers != (operators +1))
		  {
		  		return "invalid";
		  }




	return infix;
}

	/*
	 * Converts an infix expression into a postfix expression
	 * and returns the postfix expression
	 *
	 * - The given infix expression will have a space between every number or operator.
	 * - The returned postfix expression must have a space between every number or operator.
	 * - Check lab requirements for what will be considered invalid.
	 *
	 * return the string "invalid" if infixExpression is not a valid infix expression.
	 * otherwise, return the correct postfix expression as a string.
	 */
 string shuntingyard :: infixToPostfix(string infixExpression)
{
	 stack <string> barrel;

	 	 stringstream ss;
	 	 ss << infixExpression;

	 	 string var;
	 	 string postfix = "";
	 	 string priority = "";
	 	 int numbers = 0;
	 	 int operators = 0;

	 	 while (ss >> var)
	 	 {

	 		 for(int i= 0; i <= var.size(); i++)
	 		 {
	 			 if ( var[i]== '.')
	 			 {
	 				 return "invalid";
	 			 }
	 		 }

	 	 if(isdigit(var[0]) || var == "(" || var== ")" || var== "{" || var== "}" || var== "[" || var== "]" || var== "*" || var== "/" || var== "%" || var== "+" || var== "-")
	 	 {
	 		 if (var == "+" || var == "-")
	 		 {
	 			 priority = "low";
	 		 }
	 		 if (var == "*" || var == "/" || var == "%")
	 		 {
	 			 priority = "high";
	 		 }


	 		 if (var == "(" || var == "{" || var == "[")
	 		 {
	 			 barrel.push(var);
	 		 }
	 		 if(var == ")" || var == "}" || var == "]")
	 		 {

	 			 if (barrel.empty())
	 				 {
	 				 return "invalid";
	 				 }
	 			 while(barrel.top() == "*" || barrel.top() == "/" || barrel.top() == "%" || barrel.top() == "+" || barrel.top() == "-")
	 			 {
	 				 postfix += barrel.top() + " ";
	 				 operators++;
	 				 barrel.pop();
	 				 if(barrel.empty())
	 				 {
	 					 return "invalid";
	 				 }
	 			 }
	 			if ((barrel.top() == "(" && var == ")") || (barrel.top() == "{" && var == "}") || (barrel.top() == "[" && var == "]"))
	 				 {
	 						barrel.pop();
	 				 }
	 			else
	 			{
	 				return "invalid";
	 			}
	 		 }


	 		 if (var == "+"|| var == "-" || var == "/" || var == "*" || var == "%")
	 		 {
	 			 if (barrel.empty())
	 			 {
	 				 barrel.push(var);
	 			 }

	 			 else
	 			 {
	 				 if (barrel.top() == "(" || barrel.top() == "[" || barrel.top() == "{")
	 				 {
	 					 barrel.push(var);
	 				 }
	 				 else if ((priority == "high" && barrel.top() == "+") || (priority == "high" && barrel.top() == "-"))
	 				 {
	 				 barrel.push(var);
	 				 }
	 				 else
					 {
	 					 while (!barrel.empty() && ((priority == "high" && barrel.top() == "*") || (priority == "high" && barrel.top() == "/") || (priority == "high" && barrel.top() == "%") || (priority == "low" && barrel.top() == "*") || (priority == "low" && barrel.top() == " %") || (priority == "low" && barrel.top() == "/") || (priority == "low" && barrel.top() == "+") || (priority == "low" && barrel.top() == "-")))
	 						 {
	 						 postfix += barrel.top() + " ";
	 						 operators++;
	 						 barrel.pop();
	 						 }
	 					 barrel.push(var);
					 }
	 			 }
	 		 }

	 		if (isdigit(var[0]))
	 		 {
	 			 postfix += var + " ";
	 			 numbers++;
	 		 }
	 	 }

	 		else
	 		{

	 			return "invalid";
	 		}

	 	 }

	 		 while (!barrel.empty())
	 		 {
	 			 if((barrel.top() == "(" || barrel.top() == "{" || barrel.top() == "["))
	 			 {
	 				return "invalid";
	 			 }

	 			 else
	 			 {
	 			postfix += barrel.top() + " ";
	 			 barrel.pop();
	 			 operators++;
	 			 }
	 		 }

	 	if (numbers != (operators +1))
	 	{
	 		return "invalid";
	 	}

	 	postfix.erase(postfix.end()-1);
	 	 return postfix;
}

	/*
	 * Evaluates a postfix expression returns the result as a string
	 *
	 * - The given postfix expression will have a space between every number or operator.
	 * - Check lab requirements for what will be considered invalid.
	 *
	 * return the string "invalid" if postfixExpression is not a valid postfix Expression
	 * otherwise, return the correct evaluation as a string
	 */
 string shuntingyard :: postfixEvaluate(string postfixExpression)
{
stack <string> barrel;

		 	 stringstream ss;
		 	 ss << postfixExpression;

		 	 string var;
		 	 string posteval = "";
		 	 int numbers = 0;
		 	 int operators = 0;

		  while (ss >> var)
		  {
			 int left = 0;
		 	 int right = 0;
		 	 int putbacknum = 0;
		 	 string putback = "";
		 	 stringstream ssputback;

			  for(int i= 0; i <= var.size(); i++)
			  {
			 	 if ( var[i]== '.')
			 	  {
			 	 	 return "invalid";
			 	  }
			  }
			  if(isdigit(var[0]) || var== "*" || var== "/" || var== "%" || var== "+" || var== "-")
			  {
				  if (isdigit(var[0]))
				  {
					  numbers++;
					  barrel.push(var);
				  }
				  if (var == "*" || var == "%" || var == "/" || var == "+" || var == "-")
				  {
					  operators++;
					  if (!barrel.empty())
					  {
					  stringstream ssright;
					  ssright << barrel.top();
					  ssright >> right;
					  barrel.pop();
					  }
					  else
					  {
						  return "invalid";
					  }
					  if (!barrel.empty())
					  {
					  stringstream ssleft;
					  ssleft << barrel.top();
					  ssleft >> left;
					  barrel.pop();
					  }
					  else
					  {
						  return "invalid";
					  }

					  if (var == "*")
					  {
					  putbacknum = left * right ;
					  ssputback << putbacknum;
					  ssputback >> putback;
					  barrel.push(putback);
					  }
					  if (var == "%")
					  {
						  if(right == 0)
						  {
							  return "invalid";
						  }
						  else
						  {
						  putbacknum = left % right ;
						  ssputback << putbacknum;
						  ssputback >> putback;
						  barrel.push(putback);
						  }
					  }
					  if(var == "/")
					  {
						  if(right == 0)
						  {
							  return "invalid";
						  }
						  else
						  {
						  putbacknum = left / right ;
						  ssputback << putbacknum;
						  ssputback >> putback;
						  barrel.push(putback);
						  }
					  }
					  if(var == "+")
					  {
						  putbacknum = left + right ;
						  ssputback << putbacknum;
						  ssputback >> putback;
						  barrel.push(putback);
					  }
					  if (var == "-")
					  {
						  putbacknum = left - right ;
						  ssputback << putbacknum;
						  ssputback >> putback;
						  barrel.push(putback);
					  }
				  }
			  }
			  else
			  {
				  return "invalid";
			  }
		  }

		  if (!barrel.empty())
		  {
			  posteval = barrel.top();
		  }


		  if (numbers != (operators +1))
		  {
		  		return "invalid";
		  }

return posteval;

}




