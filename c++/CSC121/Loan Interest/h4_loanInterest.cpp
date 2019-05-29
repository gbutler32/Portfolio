/*
==================================================================================

	Course: Harper CSC121, Fall 2014
	Student Name: Gary Butler

	Program name: Compound Interet Calculation

	Progrma description: 	
		This program calculates and lists each year's balance for a compound 
		interest of a loan.

		Inpput: A rate, a principal and how many years fron keyboard.
		Output: Print the result to screen.

	File(s): h4_loanInterest_<yr_login>.cpp

	Instructions: 
		1. First, read, compile and run the given code before you do any change.
		2. Change those constants by asking user to input from keyboard.
		3. Make the main calculation into a function. 
		4. The given variables can be re-used.
		5. Submit only the .cpp file with your change. The given file name is 
			h4_loanInterest.cpp, you should change the file name to something 
			like h4_loanInterest_jguo.cpp

	Notes: 
		cout << fixed; // display numbers in fixed format.
		cout << setw(5); // set a field width.
		cout << setprecision(2); // set digits after decimal point.
		pow(3,2); // math function power, pow(3,2) = 3^2 = 9;

	Created: 	1/31/2012 by Jin Guo
	Modified:	9/24/2014 by Jin Guo. Custmoized for Harper.

==================================================================================
*/
#include <iostream>	// for cin, cout, fixed
#include <iomanip>	// for setw, setprecision
#include <cmath>	// standard C++ math library, for function pow

using namespace std;

// The following function calculates and lists balance of each year.
// @ n: how many years.
// @ rate: the given rate.
// @ principal: the given principal.
//
void interestCalculate( double rate, double principal, int n);

int main()
{
	// print out header.
	cout << "=============================================================\n";
	cout << "Harper CSC121-003: Assignment #4, 2014 Fall\n";
	cout << "Student: Gary Butler\n\n";
	cout << "This program will do compound interest calculations.\n"; 
	cout << "=============================================================\n\n";

	double balance; // amount on deposit at end of each year
	double principal = 1000.0; // initial amount before interest
	double rate = .5; // interest rate
	int N = 10; // how many years for this loan.

	// set floating-point number format
	cout << fixed << setprecision( 2 );

	cout << "Principal = $" << principal << ", Interest = " << rate 
		<< ", Years = " << N << "\n\n";

	// display header
	cout << "Year" << setw( 15 ) << "Balance" << endl;
	cout << "~~~~" << setw( 15 ) << "~~~~~~~" << endl;
	
	for ( int year = 1; year <= N; year++ ) 
	{
		// calculate new amount for specified year
		balance = principal * pow( 1.0 + rate, year );

		// display the year and the amount
		cout << setw( 4 ) << year << setw( 15 ) << balance << endl;
	}
	cout << endl;
	
	return 0;
} 


// Your output should like the following:
/*
=============================================================
Harper CSC121-003: Assignment #4, 2014 Fall
Student: Gary Butler

This program will do compound interest calculations.
=============================================================

Input the rate ==> 0.5
Input the principal ==> 1000
Input how many years ==> 10

Year        Balance
~~~~        ~~~~~~~
   1        1500.00
   2        2250.00
   3        3375.00
   4        5062.50
   5        7593.75
   6       11390.63
   7       17085.94
   8       25628.91
   9       38443.36
  10       57665.04

Press any key to continue . . .
*/
