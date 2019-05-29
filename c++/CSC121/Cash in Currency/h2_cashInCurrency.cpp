/*
==================================================================================

	Course: Harper CSC121, Fall 2014
	Student Name: Gary Butler

	Program name: Cash in curreny
	Progrma description: 	
		For students to understand int type and double type and simple arithmetic
		operations such as +, -, *, / and %. The input dollars will be broken into
		hundred-bills, twenty-bills, ten-bills, five-bills, dollars, quaters, dimes, 
		nickles and cents.

		Inpput: One double number from keyboard.
		Output: Print the result to screen.

	File(s): h2_cashInCurrency_<yr_login>.cpp

	Instructions: 
		1. First, read,compile and run the given code before you do any change.
		2. I have done the job of the "dollar part". You need to implement the 
			"cent part", i.e., to turn the remaining cents into dimes, 
			 nickles and cents.
		3. Add your code to wherever is marked "Add your code below..."
		4. Please do not remove any existing statements.
		5. The given variables can be re-used.
		6. Submit only the .cpp file with your change.The given file name is 
			h2_cashInCurrency.cpp, you should change the file name to something 
			like h1_cashInCurrency_jguo.cpp
		
	Created: 	1/31/2012 by Jin Guo
	Modified:	9/11/2014 by Gary Butler

==================================================================================
*/
#include "stdafx.h"
#include <iostream>
#include <cmath> // for function floor(), consult www.cplusplus.com for info.

using namespace std;

int main()
{
	// print out header.
	cout << "=============================================================\n";
	cout << "Harper CSC121-003: Assignment #2, 2014 Fall\n";
	cout << "Student: <Your Name>\n\n";
	cout << "This program will cash the amount of money into bills of 100,\n"; 
	cout << "20, 10, 5 and 1 dollars and coins of quaters, dimes, nickles\n";
	cout << "and cents.\n";
	cout << "=============================================================\n\n";

	double dollars;
	int i_hundred = 0;	// for the number of $100 bills
	int i_twenty = 0;	// for the number of $20 bills
	int i_ten = 0;		// for the number of $10 bills
	int i_five = 0;		// for the number of $5 bills
	int i_one = 0;		// for the number of $1 bills

	int i_dollars;	// used for converting variable dollars into int
	double d_cents;	// cents of double type.
	int cents = 0;	// used for converting variable cents into int

	cout << "How much money do you want to cash? ==> ";
	cin >> dollars;

	// Convert the double into integer and decimal part is truncated.
	i_dollars = static_cast<int> (dollars); 

	d_cents = dollars - floor( dollars ); // get the remaining cents.
	cents = static_cast<int> (d_cents * 100.0); // conver to int without rounding.
	//cents = static_cast<int> (d_cents * 100.0 + 0.5); // conver to int with rounding.
	cout << "You have asked to cash " << i_dollars << " dollars and " << cents << " cents.\n\n";
	
	if (i_dollars >= 100)
	{
		i_hundred = i_dollars / 100;
		i_dollars = i_dollars - i_hundred * 100;
	}
	if (i_dollars >= 20)
	{ 
		i_twenty = i_dollars / 20;
		i_dollars = i_dollars - i_twenty * 20;
	}
	if (i_dollars >= 10)
	{
		i_ten = i_dollars / 10;
		i_dollars = i_dollars - i_ten * 10;
	}
	if (i_dollars >= 5)
	{
		i_five = i_dollars / 5;
		i_dollars = i_dollars - i_five * 5;
	}	

	cout << "Please count, you have \n";
	if (i_hundred)
	cout << i_hundred << " one hundred bills \n";
	if(i_twenty)
	cout<< i_twenty << " twenty bills \n";
	if(i_ten)
	cout<< i_ten << " ten bills \n";
	if(i_five)
	cout<< i_five << " five bills \n";
	if(i_dollars)
	cout<< i_dollars << " dollars. \n";

	
	int quarters = 0;	// for the number of quaters
	int dimes = 0;		// for the number of dimes
	int nickles = 0;	// for the number of nickles
	
	if (cents >= 100)
	{
		cout << "Something is wrong! The remaining cents cannot be greater than 99!\n";
		return 1; // abnormal exit
	}
	//// Insert your code below 
	//// Started with the value in the int vavariable "cents".
	if (cents > 0)
	{
		if (cents >= 25)
		{
			quarters=cents / 25;
			cents-= quarters*25;
		}
		if (cents>=10)
		{
			dimes=cents / 10;
			cents-= dimes*10;
		}
		if (cents>=5)
		{
			nickles=cents / 5;
			cents -= dimes*5;
		}
	}
	cout<<"\n";
	if (quarters)
	cout << quarters << " quarters \n";
	if (dimes)
	cout << dimes << " dimes \n";
	if (nickles)
	cout << nickles << " nickles \n";
	if (cents)
	cout<< cents << " pennies \n";
	system("pause");
	return 0;
}
/*
 ************************************************
 * (C) Copyright 2007 - by Jin Guo
 *
 * This program is free for my class students.
 * For any other purpose of using this program, 
 * please ask for permisson by sending email to: 
 * taijiguo@comcast.net
 ************************************************
*/
