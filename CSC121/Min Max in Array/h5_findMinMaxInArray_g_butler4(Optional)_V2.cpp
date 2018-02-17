/*
==================================================================================

    Course: Harper CSC121, Fall 2014
    Student Name: Gary Butler

    Homework type and points: Assignment #5, 20 points.

    Program name: Find max and min elements

    Progrma description: 
        This assignment gives you some exercise about arrays. An array is given
        filled in with randomly generated numbers. You need to find the maximum 
        and minium elements in the array.

    File(s): h5_findMaxMinInArray_<yrlogin>.cpp

    Your job: 
        1. Try to understand and run this program before you do any change.
        2. You need to find the max and min elements in the array. 
        3. Add your code to wherever marked as "Add your code below..."
        4. Please do not remove any existing statements.
        5. Try to use the given variables as much as you can.
        6. Optinal: sort the array and then print out the result.
        7. Submit only the .cpp file with your change. The given file name is 
            h5_findMaxMinInArray, you should change the file name to something 
            like h5_findMaxMinInArray_jguo.cpp

    Created:     9/8/2007 by Jin Guo
    Modified:    11/2/2009 by Jin Guo
    Modified:    2/24/2102 by Jin Guo, both min and max will be calculated.
    Modified:    10/2/2014 by Jin Guo. Custmoized for Harper.

===================================================================================
*/
#include "stdafx.h"
#include <iostream>    // for cin, cout, fixed
#include <iomanip>    // for setw, setprecision
#include <cstdlib>    // for srand(), rand()
#include <ctime>    // for time() as a seed for srand()

using namespace std;

int main()
{

    // Print out header.
    cout << "=============================================================\n";
    cout << "Harper CSC121-003: Assignment #5, 2014 Fall\n";
    cout << "Student: Gary Butler\n\n";
    cout << "This program will find the sum, maximum and minimum elements\n";
    cout << "in an integer array.\n";    
    cout << "=============================================================\n\n";

    const int SIZE = 10; // set size of the array

    // Seed the rand() by using the time function.
    int t = static_cast<int> (time(0)); // convert the return value to int to avoid a warning
    srand( t );    // seed random number generator

    int A[SIZE];    // declare an array of size 10
    int i, j;        // index variables
    int sum = 0;    // for the total

    cout << "Generate some random numbers ([1-1000]) for Array of A.\n\n";
    cout << "Element #" << setw(20) << "Element Value" << endl;
    cout << "~~~~~~~~~" << setw(20) << "~~~~~~~~~~~~~" << endl;
    
    // Assign values into the array and print them out to screen.
    for (i = 0; i < SIZE; i++)
    {
        A[i] = 1 + rand() % 1000;
        cout << setw(9) << i << setw(20) << A[i] << endl;
    }

    cout << "\nNow find the sum of all elements in this array.\n";
    for (i = 0; i < SIZE; i++)
        sum = sum + A[i];

    cout << "The sum is ==> " << sum << endl;

    cout << "\nNow find the maximum value in this array.\n";

    int max, min, max_i, min_i;    // for max value and its indes

    // Hint: assume the first is the max and min at the beginning
    max_i = 0;    // use to store the index of the max element
    min_i = 0;    // use to store the index of the min element
    max = A[0];    // assume A[0] is the max one at the beginning 
    min = A[0];    // assume A[0] is the min one at the beginning

    // Your code below...
    //
    for(int a=0;a<=SIZE-1;a++)
    {
        if(A[a]<min)
        {
            min=A[a];
			min_i=a;
        }
		if(A[a]>max)
		{
			max=A[a];
			max_i=a;
		}
    }
    cout << "The maximum value in this array is ==> A[" << max_i << "] = " << max << endl << endl;
    cout << "The minimum value in this array is ==> A[" << min_i << "] = " << min << endl << endl;

    // The following is for extra credits. There are a few ways to sort a group of data. 
    // You may use your common sense or consult any resource and pick up your favoriate.
    cout << "Now sort the array in asending order...\n\n";

    // Your code below...
    cout << "Element #" << setw(20) << "Element Value" << endl;
    cout << "~~~~~~~~~" << setw(20) << "~~~~~~~~~~~~~" << endl;
	a =0;
	for(j=0;j<=SIZE-1;j++)
	{
		for(i=j;i<=SIZE-1;i++)
		{
			if(A[j]>=A[i])
			{
				a=A[i];
				A[i]=A[j];
				A[j]=a;
			}
		}
		cout << setw(9) << j << setw(20) << A[j] << endl;
	}
	system("pause");

    return 0; 
}