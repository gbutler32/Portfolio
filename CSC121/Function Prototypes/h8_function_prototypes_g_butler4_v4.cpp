/*
==================================================================================
    Course: Harper CSC121-003 by Mr. Jin Guo, Fall 2014
    
    Student Name: Gary Butler

	Program name: Function Prototypes

	Program description: 
		You are given some function requirements. Per each requirement, write down
		a function prototype. 

	File(s): h8_function_prototype_g_butler4.cpp

	Instructions: 
		1. Understand and run this program before you do any change.
		2. When functions prototypes are given, your program should compile and run.
		3. Please follow the given format and convention.

	Created:	11//2014 by Jin Guo
===================================================================================
*/
#include "stdafx.h"
#include <iostream>
#include <stdlib.h>
#include <random>
#include <array>

using namespace std;

/*  ========================
	#1: 
	Appends as much as possible from a C string to another C string.
	@param s1: the string to which t is appended
	@param maxLength: the maximum length of s (not counting '\0')
	@param s2: the string to append
*/             
void append( char *s1, int maxLength, const char *s2 );

/*  ========================
	#2:
	Given a C string, reverse its contents and return the result as a
	new C string. The contents of the original are preserved.
	@param str: the C string which will be reversed.
	@param return: a C string with the reversed contents is returned.
*/             
char* strReversed_v1( const char* str );

/*	=========================
	#3:
	The following function calculates and lists balance of each year.
	@param n: years of investment.
	@param rate: the interest rate.
	@param principal: the given principal.
*/
void interestCalculate( double rate, double principal, int n );

/*	=========================
	#4:
	This function prints out just the contents of a string with double quotes.
	@param strRef: the C++ string passed by reference.
*/
void printStringOnly( const string &strRef );

/////////// Your job below ////////////
/*	=========================
	#5:
	This function will compare three double numbers and return the maximum.
*/
double maxOfThreeDoubles(double first, double second, double last);//defines three doubles to be compared

/*	=========================
	#6:
	This function will compare two double numbers. Return true if they are the
	same otherwise false.
*/
bool areTwoNumsTheSame(double first, double second);//defines two doubles to be compared

/*	=========================
	#7:
	This function will generate a group of random int numbers, with a certain range.
	For example, the range is [1, 999].
*/
void randArr(int *A, int size, int low_bound,int high_bound);//defines an array and the size of the array to be filled, along with the max and min values of the random function

/*	=========================
	#8:
	This function will print out an int array, every line for 10 numbers 
	or for N numbers.
*/
void printArray(int n,const int *arr, int size);//defines the cut off value that the array is to printed, defines the array and the size of the array

/*	=========================
	#9:
	This function will find the average GPA for a group of students. The GPAs 
	are given by an array of double.
*/
void avgGPA(const double *grades,int size);//defines the array itself as well as the size of the array

/*	=========================
	#10:
	This function will sort a group of int numbers and at the same time, 
	return its minimum and maximum.
*/
void findMinMax(const int* group,int size, int& max, int& min);//defines the array, the size of the array, and the max and min values that will be returned


int main()
{
	// Print out header.
	cout << "==================================================================\n";
	cout << "Harper CSC121-003: Assignment #8, 2014 Fall\n";
	cout << "Student: Gary Butler\n\n";
	cout << "This program is for you to understand functions prototypes.\n";
	cout << "==================================================================\n\n";

	cout << ">>> I declared the following functions based on the requirements.\n\n";
	cout << "#1: void append( char *s1, int maxLength, const char *s2 );\n";
	cout << "#2: char* strReversed_v1( const char* str );\n";
	cout << "#3: void interestCalculate( double rate, double principal, int n );\n";
	cout << "#4: void printStringOnly( const string &strRef );\n";

	cout << "\nStudent defined:\n\n";
	cout << "#5 double maxOfThreeDoubles(double first, double second, double last);\n";
	cout << "#6 bool areTwoNumsTheSame(double first, double second);\n";
	cout << "#7 void randArr(int* A, int size, int low_bound,int high_bound);\n";
	cout << "#8 void printArray(int n,const int *arr, int size);\n";
	cout << "#9 void avgGPA(const double *grades,int size);\n";
	cout << "#10 void findMinMax(const int* group,int size, int& max, int& min);\n";

	cout << "\n>>>> Your job below... >>>>\n";
    const int sz=10;

	int low=1;
	int high = 10;
	int arr1[sz];
	randArr(arr1, sz, low, high);

	cout<<"\nprintArray():\n";
	int arr2[sz]={1,2,3,4,5,6,7,8,9,10};
	printArray(7,arr2,sz);
	cout<<"\n";

	system("pause");
	cout << endl;
}

void randArr(int* A, int size, int low_bound,int high_bound)
{
	//#7
	cout<<"randArr():";
	for(int i=0;i<=size-1;i++)
	{
		A[i]= low_bound + (rand() % ( high_bound - low_bound  + 1));
		cout<<"\n"<<A[i];
	}
}

void printArray(int n, const int *arr, int size)
{
	//#8
	int count =1;
	for(int a=0;a<=size-1;a++)
	{
		cout<<arr[a]<<"\t";
		count++;
			if(count==n)
			{
				cout<<"\n";
				count=0;
			}
	}
}
