/* 
=============================================================================
 
	Course: Harper CSC-121, Fall 2014

	Program name: Program_9
	Program description: 	
		This program shows three alogrithms to reverse elements in an array.

	File(s): s9_reverse_arrray_elements.cpp

	Created: 	3/11/2012 by Jin Guo
	Modified:	6/3/2012 by Jin Guo. A recursice function is added.
	Modified:	10/11/2014. Custmoized for Haper
	Modified:	10/23/2014 by Jin Guo. Add Algorithm 5 and print array
				void printAnArray(const int* A, int size );
				void inPlaceReverseAnArray(int *A, int size);
				Removed the recursive function.
 
================================================================================
*/
#include <iostream> 
#include <cstring> // for strlen()
using namespace std;

// Reversed contents in str1 is put into str2. Contents of str1 is preserved.  
void CstrReverseRecursively(const char *str1, char *str2, int size);

// Print out an array
void printAnArray(const int* A, int size );

// After alling this functino, array A will have its contents reversed.
void inPlaceReverseAnArray(int *A, int size);

int main()
{
	cout << "===================================================================\n";
	cout << "GSU CPSC-342, Program_9\n";
	cout << "This program shows five alogrithms to reverse elements in an array.\n";
	cout << "===================================================================\n";

	const int SIZE = 10; // pre-defined size for arrays.

	int A[SIZE] = {11, 22, 33, 44, 55, 66, 77, 88, 99,100};
	int B[SIZE], C[SIZE];
	int i, j; // for indexes.

	// Algorithm 1: Reverse elements of A[] and put them into B[];
	cout << "\n==> Using Algorithm 1...\n";
	cout << "Before elements of A[] are reversed: \n";
	cout << "A[]: ";
	printAnArray(A, SIZE);

	for (i = 0; i < SIZE; i++)
		B[i] = A[SIZE - 1 - i];

	cout << "\nAfter elements of A[] are reversed into B[]: \n";
	cout << "B[]: ";
	printAnArray(B, SIZE);

	// Algorithm 2: Reverse elements of A[] and put them into B[];
	cout << "\n==> Using Algorithm 2...\n";
	cout << "Before elements of A[] are reversed: \n";
	cout << "A[]: ";
	printAnArray(A, SIZE);

	for (i = 0; i < SIZE; i++)
		C[SIZE - 1 - i] = A[i];

	cout << "\nAfter elements of A[] are reversed into C[]: \n";
	cout << "C[]: ";
	printAnArray(C, SIZE);

	// Algorithm 3: Reverse str1 and put the result into str2
	cout << "\n==> Using Algorithm 3...\n";
	
	char str1[SIZE] = {'a','b','c','d','e','f','g','\0'};
	cout << "Before c string str1 is reversed: \n";
	cout << "str1: " << str1 << "\n";

	int size = static_cast<int> (strlen(str1)); // real size of str1
	char str2[SIZE];
	for (i = 0, j = size - 1; i < size; i++, j--)
		str2[i] = str1[j];
	str2[size] = '\0'; // append the ending \0.

	cout << "\nAfter str1 is reversed into str2: \n";
	cout << "str2: " << str2 << "\n";

	// Algorithm 4: Reverse an array within itself
	cout << "\n==> Using Algorithm 4...\n";
	cout << "Before elements of A[] is reversed: \n";
	cout << "A[]: ";
	printAnArray(A, SIZE);

	inPlaceReverseAnArray(A, SIZE);
	cout << "\nAfter callling inPlaceReverseAnArray(),\n";
	cout << "A[]: ";
	printAnArray(A, SIZE);

	cout << endl;

	return 0;
}

// Reversed contents in str1 is put into str2. Contents of str1 is preserved.  
void CstrReverseRecursively(const char *str1, char *str2, int size)
{
	while (size > 0)
	{
		str2[0] = str1[size - 1];
		str2++;
		size--;
		CstrReverseRecursively(str1, str2, size);
	}
}

// After alling this functino, array A will have its contents reversed.
void inPlaceReverseAnArray(int *A, int size)
{
	int m = size / 2;
	int temp;

	for (int i = 0; i < m; ++i)
	{
		temp = A[i];
		A[i] = A[size -1 - i];
		A[size -1 - i] = temp;
	}
}

// Print out an array
void printAnArray(const int* A, int size )
{
	for (int i = 0; i < size; i++)
		cout << A[i] << " ";
	cout << endl;
}
