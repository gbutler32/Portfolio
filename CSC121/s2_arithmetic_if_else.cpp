/*
=================================================================================
	Course: Harper CSC121, Fall 2014

	Program name: Program_2
	Progrma description: 	
		This program is designed to show how if-else statment and basic aithmetic
		opreations will be used.

	File(s): s2_arithmetic_if_else.cpp

	Created: 	1/26/2012 by Jin Guo
	Modified:	9/10/2014 by Jin Guo.

=================================================================================
*/

#include <iostream> 
using namespace std;

int main()
{
	// a and b are used for two input integers, c is for result.
	int a, b, c; 

	cout << "Harper CSC121, Sample Program_2\n";
	cout << "===============================\n";
	cout << "This program is to show how if-else statment and basic aithmetic\n";
	cout << "opreations will be used.\n\n";

	cout << "Input the first integer a ==> ";
	cin >> a;
	cout << "Input the second integer number b ==> ";
	cin >> b;
	cout << "\n";

	c = a + b;
	cout << "a + b = " << c << endl;

	c = a - b;
	cout << "a - b = " << c << endl;
	
	cout << "a * b = " << (a * b) << endl; // you can directly use an expression.

	// "if" and "else" are used together.
	if (b != 0) 
	{
		c = a / b;
		cout << "a / b = " << c << endl;
	}
	else
	{
		cout << "Since b is 0, (a / b) cannot be done!\n\n";
		return 1; // abnormal exit from this program.
	}
	cout << endl; // get a new line.
	
	if ( a > 0 && b > 0) // only "if" is used. "&&" means "and"
		cout << "Both integers are positive!\n";

	if ( a < 0 && b < 0) // only "if" is used. "||" means "or"
		cout << "Both integers are negative!\n";

	// use "if"-"else if"-"else"
	if (a > b)
		cout << "a is greater than b.\n";
	else if ( a < b)
		cout <<  "a is smaller than b.\n";
	else
		cout << "a and b are the same.\n";

	cout << endl; // get a new line.

   return 0; 
} 
