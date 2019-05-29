//////////////////////////////////////////////////////////////////////////////////
//
//	Course: Harper CSC121, Fall 2014
//
//	Program name: Program_8
//  Progrma description: 	
//		This program should help you to understand concepts of address of
//		a variable and pointer variable. The important comcepts are: any variable 
//		has a l-value which is its address and a r-value which is its content.
//		A pointer variable can take an address of a variable, which is its r-value, 
//		but it also has its l-value which is the address of this pointer variable.
//
//		I may give you some questions out of this program for the final.  
//		Please understand it and  run it. You may add some code of your own to 
//		verify something you are not so sure about address and pointer.
//
//  File(s): s8_play_pointer.cpp
//
//	Created: 	11/19/2007 by Jin Guo
//	Modified:	3/2/2012 by Jin Guo
//  Modified:	3/7/2012 by Jin Guo, minor change.
//	Modified:	10/11/2014. Custmoized for Haper
//
///////////////////////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

int main()
{
	cout << "==================================================================\n";
	cout << "This program is to verify some comcepts of address and pointer.\n";
	cout << "You may add more code to verify behavior of address and pointer.\n";
	cout << "==================================================================\n\n";

	cout << "i, j are variables of int.\n";
	cout << "intPtr1, intPtr2 are pointer variables of int.\n";
	cout << "alias_i is an alias of i.\n\n";

	int i, j;	// declare i as int and initialize it with 15;
	i = 15;		// l-value of i is used
	cout << "i = " << i << endl; // r-value of i is used
	cout << "address of i is &i = " << &i << endl; // l-value is used
	
	j = i + 20;	// l-value of j is used and r-value of i is used
	cout << "j = i + 20 = " << j << endl;	// r-value of j is used
	cout << "address of j is &j = " << &j << endl;	// l-value is used

	int* intPtr1;	// declare a variable which can accept an address of int variable
	int* intPtr2;	// declare another int pointer variable
	intPtr1 = &i;	// address of i (l-value of i) is assigned to intPtr1
	cout << "\nAfter intPtr1 = &i:\n";
	cout << "intPtr1 contains address of i, which is: " << intPtr1 << endl; 
	cout << "The address (l-value) of intPtr1 is : " << &intPtr1 << endl; 
	//cout << (&(*intPtr1)); 
	

	intPtr2 = intPtr1;	// now both intPtr2 and intPtr1 has &i (address of i) as their content
	cout << "\nAfter intPtr2 = intPtr1; \n";
	cout << "intPtr2 also contains address of i, which is: " << intPtr2 << endl; 
	cout << "The address (l-value) of intPtr2 is : " << &intPtr2 << endl; 

	cout << "\nYou can access i via intPtr1 by de-reference (using \"*\"),\n";
	cout << "i.e., you can use (*intPtr1) as if you are using i:\n";
	cout << "\nChange value of i by *intPtr1 = 555\n";
	*intPtr1 = 555;
	cout << "Now i = " << i << endl;
	cout << "Or j = 111 + (*intPtr1) = " << (j = 111 + (*intPtr1)) << endl;
	cout << "\nYou can also print what's in i by print (*intPtr1)\n";
	cout << "*intPtr1 = " << *intPtr1 << endl;

	// declare an alias of i. You may do anything with alias_i just like you do it with i.
	// note that alias has to be initialized.
	int& alias_i = i; 

	intPtr2 = &j;
	int& alias_j = *intPtr2; //i.e, int& alias_j = j;

	alias_i = 99;	// note that r-value of i is changed to 99 via this alias.
	cout << "\nalias_i is an alias of i, after alias_i = 99:\n";
	cout << "alias_i = " << alias_i << endl;
	cout << "i = " << i << endl;
	cout << "\nAddress of i is: " << &i << endl;
	cout << "Address of alias_i is: " << &alias_i << endl;

	cout << "\nalias_j is an alias of j and it is initialized to *intPtr2.\n";
	cout << "intPtr2 is assgined address of j (&j):\n";
	cout << "\nalias_j = " << alias_j << endl;
	cout << "*intPtr2 = " << *intPtr2 << endl;
	cout << "&(*intPtr2) is address of j: " << &( *intPtr2) << endl;

	cout << "\nThis is fun. I want to play more...\n";
	cout << "-----------------------------------\n";
	cout << "...\n";

	// print out time stamp
	cout << "Time Stamp of Running: \n";
	system("time /T");
	system("date /T");
	system("pause");

	return 0; 
}
