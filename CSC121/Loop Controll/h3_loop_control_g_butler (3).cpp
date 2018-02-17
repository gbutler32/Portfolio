/*
====================================================================================

	Course: Harper CSC121, Fall 2014
	Student Name: Gary Butler

	Program name: Loop control

	Progrma description: 	
		For students to understand three types of loop control. This program takes 
		two integers a and b, and calculate the sum of the naturally increased list 
	   <a, a+1, a+2, ...b>.

		Inpput: Two integers from keyboard.
		Output: Print the result to screen.

	File(s): h1_loop_control_<yr_login>.cpp

	Instructions: 
		1. First, read,compile and run the given code before you do any change.
		2. I have used whole-loop to get this job done. You need to implement the 
			logic with for-loop and do-loop.
		3. Add your code to wherever is marked "Add your code below..."
		4. Please do not remove any existing statements.
		5. The given variables can be re-used.
		6. Submit only the .cpp file with your change.The given file name is 
			h3_loop_control_<yr_login>.cpp, you should change the file name to something 
			like h3_loop_control_jguo.cpp

	Created: 	9/19/2009 by Jin Guo
	Modified:	9/24/2014 by Gary Butler
 
====================================================================================
*/
#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	// Print out header.
	cout << "============================================================================\n";
	cout << "Harper CSC121-003: Assignment #3, 2014 Fall\n";
	cout << "Student: Gary Butler\n\n";

	cout << "This program will add all the items in a list such as <3,4,5,...9> together.\n";
	cout << "The two input integers must be positive and the second one cannot be smaller\n";
	cout << "than the first one.\n";
	cout << "============================================================================\n\n";

	// Two integers used to define the list. a is the first int and b is the last.
	int a, b; 
	
	cout << "Input the first integer ==> ";
	cin >> a;
	cout << "Input the second integer number ==> ";
	cin >> b;
	cout << "\n";

	if (a < 0 || b < 0) // "||" means "or"
	{
		cout << "Sorry, both numbers must be positive - bye!\n";
		return 1; // abnormal exit.
	}
	if (a > b) 
	{
		cout << "Sorry, the second number cannot be smaller than the first one - bye!\n";
		return 1; // abnomal exit.
	}
	if (a == b) 
	{
		cout << "You have input two numbers as the same.\n"
			<< "This means only one item in the list.\n";
		cout << "So the sum = " << a << endl;
		return 0;
	}

	int index = a; // started with a and increased by 1 until b is reached.
	int sum = 0;   // used for summary.

	// Implement it with while loop
	while (index <= b)
	{
		sum = sum + index; // or sum += index;
		index = index + 1; // or index++; ++index;
	}

	while (index <= b)
		sum += index++; // or sum += index;

	cout << "Using \"while loop\", sum = " << sum << "\n";
	// Hint: you may re-use the above variables index and sum again without delacring new viables.
	sum=0;
	/////////// Your code below to implement it with for loop /////////////////////
	for(index=a;index<=b;index++)
	{
		sum += index;
	}
	cout << "Using \"for loop\", sum = " << sum << "\n";
	/////////// Your code below to implement it with do loop  /////////////////////
	sum=0;index=a;
	do
	{
		sum +=index;
		index++;
	}
	while(index<=b);
	cout << "Using \"do loop\", sum = " << sum << "\n";

	cout << endl;
	system("pause");
	return 0;
}
/* Output smaple
============================================================================
Harper CSC121-003: Assignment #3, 2014 Fall
Student: Gary Butler

This program will add all the items in a list such as <3,4,5,...9> together.
The two input integers must be positive and the second one cannot be smaller
than the first one.

============================================================================

Input the first integer ==> 1
Input the second integer number ==> 100

Using "while loop", sum = 5050
Using "for loop", sum = 5050
Using "do loop", sum = 5050

Press any key to continue . . .