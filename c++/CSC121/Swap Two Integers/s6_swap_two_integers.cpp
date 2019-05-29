//////////////////////////////////////////////////////////////////////////////////
//
//	Course: Harper CSC121, Fall 2014
//
//	
//  Progrma description: 	
//	    This program shows how call by value and call by reference work differently.
//
//  File(s): s6_swap_two_integers.cpp
//
//	Created: 	9/30/2009 by Jin Guo
//	Modified:	2/14/2012 by Jin Guo
//	Modified:	7/26/2013 by Jin Guo, added void swapTwoIntegersCallbyPointer
//
//
///////////////////////////////////////////////////////////////////////////////////

#include <iostream> 
using namespace std;

void swapTwoIntegersCallbyValue( int x, int y); // call by value
void swapTwoIntegersCallbyReference( int& x, int& y ); // call by reference
void swapTwoIntegersCallbyPointer( int *x, int *y); // call by pointer
// void swapTwoIntegersCallbyConstReference( const int& x  , const int& y ); // call by const reference, error!

int main()
{
	cout << "Harper CSC121, Program_6\n";
	cout << "===========================================================================\n";
	cout << "This program shows how call by value and call by reference work differently.\n\n";

	int a, b; 

	cout << "Input two integers (seperated by space) => ";
	cin >> a >> b;

	cout << "Before calling swap:\n";
	cout << "a = " << a << endl; 
	cout << "b = " << b << endl;

	cout << "\nTry to swap by calling swapTwoIntegersCallbyValue()...\n";
	swapTwoIntegersCallbyValue(a, b);
	cout << "After calling swap:\n";
	cout << "a = " << a << endl; 
	cout << "b = " << b << endl;
	cout << "Note that values in a and b are NOT swapped!\n";

	cout << "\nTry to swap by calling swapTwoIntegersCallbyReference()...\n";
	swapTwoIntegersCallbyReference(a, b);
	cout << "After calling swap:\n";
	cout << "a = " << a << endl; 
	cout << "b = " << b << endl;
	cout << "Note that values in a and b are swapped!\n\n";	

	swapTwoIntegersCallbyReference(a, b); // swapped back
	cout << "Before calling swap:\n";
	cout << "a = " << a << endl; 
	cout << "b = " << b << endl;

	cout << "\nTry to swap by calling swapTwoIntegersCallbyPointer()...\n";
	swapTwoIntegersCallbyPointer(&a, &b);
	cout << "After calling swap:\n";
	cout << "a = " << a << endl; 
	cout << "b = " << b << endl;
	cout << "Note that values in a and b are swapped!\n\n";	

	// cout << "Try to swap by calling swapTwoIntegersCallbyConstReference()...\n\n";
	// swapTwoIntegersCallbyConstReference(a, b); // this function will fail to compile.
	
	return 0;
}

void swapTwoIntegersCallbyValue( int x, int y)
{
	int temp;

	temp = x;
	x = y;
	y = temp;
}

void swapTwoIntegersCallbyReference( int& x, int& y) 
{
	int temp;

	temp = x;
	x = y;
	y = temp;
}

void swapTwoIntegersCallbyPointer( int *x, int *y) // call by pointer
{
	int temp;

	temp = *x;
	*x = *y;
	*y = temp;
}

//the following code will fail to compile! You cannot change the value
//pointed by a cont reference!
//void swapTwoIntegersCallbyConstReference( const int& x, const int& y)
//{
//	int temp;
//
//	temp = x;
//	x = y;
//	y = temp;
//}
