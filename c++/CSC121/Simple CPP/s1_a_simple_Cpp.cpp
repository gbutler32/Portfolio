//////////////////////////////////////////////////////////////////////////////////
//
//	Course: Harper CSC121, Fall 2014
//
//	Program name: Sample Program_1
//  Progrma description: 	
//	    This is a simple C++ demo program with cout and addition.
//
//  File(s): s1_a_simple_Cpp.cpp
//
//	Created: 	1/18/2012 by Jin Guo
//	Modified:	9/10/2014 by Jin Guo.
//
////////////////////////////////////////////////////////////////////////////////////

#include <iostream> 

int main()
{
	std::cout << "Harper CSC121, Sample Program_1\n";
	std::cout << "===============================\n";
	std::cout << "This program is to show how how cout and addition are used\n\n";
	std::cout << "Welcome to Introsction to C++!\n";
	std::cout << "This is a demo program. It will add two integers together\n";
	std::cout << "and print out the result\n\n";

	// declare variables 
	int num1; 
	int num2; 
	int result; // for result

	std::cout << "Plase enter the first integer ==> "; 
	std::cin >> num1; // wait for an integer

	std::cout << "Plase enter the second integer ==> "; 
	std::cin >> num2; //  wait for an integer

	result = num1 * num2; // multiply the two input integers

	std::cout << "num1 * num2 = " << result << "\n\n"; 

	return 0;

}

/*
 ************************************************
 * (C) Copyright 2007 -  2012 by Jin Guo
 *
 * This program is free for my class students.
 * For any other purpose of using this program, 
 * please ask for permisson by sending email to: 
 * taijiguo@comcast.net
 ************************************************
*/
