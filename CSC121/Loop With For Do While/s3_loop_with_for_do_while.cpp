//////////////////////////////////////////////////////////////////////////////////
//
//	Course: Harper CSC121, Fall 2014
//	Student Name: Gary Butler
//
//	Program name: Program_3
//  Progrma description: 	
//	    This program is designed to show how three loop control statements are used.
//
//  File(s): s3_sammple_arithmetic_if_else.cpp
//
//	Created: 	1/26/2012 by Jin Guo
//	Modified:	9/10/2014 by Jin Guo.
//
///////////////////////////////////////////////////////////////////////////////////

#include <iostream> 
using namespace std;

int main()
{
	cout << "Harper CSC121, Program_3\n";
	cout << "===============================\n";
	cout << "This program is to show how three loop control statements are used.\n\n";

	int i;

	// use "for loop" to print out sqaure of (1,2,3,...20).
	cout << "use \"for loop\" to print out sqaure of <1,2,3,...20>.\n";
	for (i = 1; i <= 20; i++) // i starts with 1, ends with 20, increased by 1 every time.
	{
		cout << (i * i) << " "; // leave a space between numbers.
		if (i == 5 || i == 10 || i == 15 || i == 20)
			cout << "\n"; // starts a new line afer every five numbers.
	}
	cout << endl; // get another new line.

	// use "while loop" to print out sqaure of (1,2,3,...20).
	cout << "use \"while loop\" to print out sqaure of <1,2,3,...20>.\n";
	i = 1; // reset i to 1.
	while (i <= 20)
	{
		cout << (i * i) << " "; // leave a space between numbers.
		if (i == 5 || i == 10 || i == 15 || i == 20)
		cout << "\n"; // starts a new line afer every five numbers.

		i++; // i increassed by 1.
	}
	cout << endl; // get another new line.

	// use "do loop" to print out sqaure of (1,2,3,...20).
	cout << "use \"do loop\" to print out sqaure of <1,2,3,...20>.\n";
	i = 1; // reset i to 1.
	do 
	{
		cout << (i * i) << " "; // leave a space between numbers.
		if (i == 5 || i == 10 || i == 15 || i == 20)
		cout << "\n"; // starts a new line afer every five numbers.

		i++; // i increassed by 1.
	} while (i <= 20);
	cout << endl; // get another new line.

	return 0; 
} 