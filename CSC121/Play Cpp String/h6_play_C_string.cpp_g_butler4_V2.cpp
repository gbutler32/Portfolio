/*
==================================================================================

	Course: Harper CSC121-003 by Mr. Jin Guo, Fall 2014

	Student Name: Gary Butler

	Program name: Play with C string

	Progrma description: 
		This program is for you to understand some of the C string operations. 
		Even though C++ <string> class offers many utilities for string 
		manipulation, programmers sometimes have to go to C string to do some 
		string operations not offerred by C++ <string>. Another advantage 
		about user-defined operations on C strings is less overhead for function 
		calling. In this program, I implemented some operations C++ <string> 
		doesn't offer.

	File(s): h6_play_C_string.cpp_<YrLogin>.cpp

	Instructions: 
		1. Understand and run the given program without any change.
		2. Implement the function strReversed_v1() and strReversed_v2().
		3. Refer to s8_play_pointer.cpp and s9_reverse_arrray_elements.cpp
	
	Created: 	9/8/2007 by Jin Guo
	Modified:	3/7/2102 by Jin Guo.Minor fix, new char[sz+1].
	Modified:	10/7/2014 by Jin Guo. Customized for Haper.

===================================================================================
*/
#include "stdafx.h" 
#include <iostream>
#include <cstring>	// for strleng(), strcpy_s(), etc.
#include <cctype>	// for isalpha() and toupper()

using namespace std;

// Print length and contents of a C string
void printCString( const char* str );

// A new C string is returned as the result of concatenating 
// two C strings.
char* myStrCat(const char* str1, const char* str2);

// Convert contents of a C string into upper case
void strToUpperCase(char* str);

// A new C string is returned as the result of reversing letters
// in a C string, whose contents are reserved.
char* strReversed_v1(const char* str);

// A C string is passed in and passed out with the result of 
// the contents reserved.
void strReversed_v2(char* str);

int main()
{
	// Print out header.
	cout << "=============================================================\n";
	cout << "Harper CSC121-003: Assignment #6, 2014 Fall\n";
	cout << "Student: Gary Butler\n\n";
	cout << "This program is for exercising some of C string operations.\n";
	cout << "=============================================================\n\n";

	// str1 and str2 are not initialized. Their contents are undefined
	char str1[50], str2[50];

	// str3 is initialized. '\0' indicates ending of a string. 
	char str3[100] = {'a', 'b', 'c', 'd', 'e', 'f', '\0'};
	
	 //use strcpy_s from <cstring>
	strcpy_s( str1, "Global warming" );
	strcpy_s( str2, " is coming. " );
	///strcpy( str1, "Global warming" );
	//strcpy( str2, " is coming. " );
	cout << "---- At the beginning ----\n";
	cout << "str1: ";
	printCString(str1);
	cout << "str2: ";
	printCString(str2);
	cout << "str3: ";
	printCString(str3);

	str3[3] = '\0'; // anything after '\0' in the str3 is ignored.
	cout << "\n---- After str3[3] = '\\0' ----\n";
	cout << "str3: ";
	printCString(str3);
	
	// Use string concatenation function from <cstring>.
	// this will cause str1 to store the result after concatenation.
	strcat_s( str1, str2 );
	cout << "\n---- After strcat_s(str1, str2) ----\n";
	cout << "str1: ";
	printCString(str1);
	cout << "str2: ";
	printCString(str2);

	// Change the contents of str3
	strcpy_s(str3, "Polar bear is in danger.");
	//strcpy(str3, "Polar bear is in danger.");
	cout << "\n---- After changing the contents of str3 by strcpy_s----\n";
	cout << "str3: ";
	printCString(str3);

	// Call user-defined myStrCat().
	// the original contents of str1 and str3 are reserved. 
	// str4 is just a pointer to char
	char* str4;

	str4 = myStrCat(str1, str3);
	cout << "\n---- After str4 = myStrCat(str1, str3) ----\n";
	cout << "str1: ";
	printCString(str1);
	cout << "str3: ";
	printCString(str3);
	cout << "str4: ";
	printCString(str4);

	// Your job below:
	// Uncomment the following line after you finished strReversed_v1()
	str4 = strReversed_v1(str4);
	// Call strReversed_v1() to reverse letters in a given string.
	// and a new string is returned.The original one is not changed.
	cout << "\n---- After str4 = strReversed_v1(str1) ----\n";
	cout << "str1: ";
	printCString(str1);
	cout << "str4: ";
	printCString(str4);

	// Your job below:
	// Uncomment the following line after you finished strReversed_v2()
	strReversed_v2(str4);
	cout << "\n---- After strReversed_v2(str4) ----\n";
	cout << "str4: ";	
	printCString(str4); 

	// change every letter to upper case for a given string. 
	strToUpperCase(str1);
	cout << "\n---- After conerting str1 into uppercase ---\n";
	cout << "str1: ";
	printCString(str1);

	cout << endl;

	system("pause");
	return 0;
}

/*
Notes: size_t is an unsigned integral type, commonly used for memory size.
*/
char* myStrCat(const char* str1, const char* str2)
{
	size_t sz1, sz2, sz, i; 

	sz1 = strlen(str1);
	sz2 = strlen(str2);
	sz = sz1 + sz2;
	char* new_str = new char[sz+1];

	for (i = 0; i <sz; i++)
	{
		if (i < sz1)
			new_str[i] = str1[i];
		else
			new_str[i] = str2[i - sz1];
	}
	new_str[i] = '\0'; // add ending 0.

	return new_str;
}

void strToUpperCase(char* str)
{
	size_t i, sz = strlen(str);

	for (i = 0; i < sz; i++)
	{
		if (isalpha(str[i]))
			str[i] = toupper(str[i]);
	}
}

char* strReversed_v1(const char* str)
{
	size_t sz = strlen(str);
	char* new_char = new char[sz + 1]; // get memory for new_char.

	// Your job belwo: put contents of string into new_char
	// in reversed order.
	for(int i=0;i<=sz-1;i++)
	{
		new_char[i]=str[sz-1-i];
	}
	new_char[sz]= '\0';

	return new_char;
}

void strReversed_v2(char* str)
{
	// Your job below:
	size_t sz = strlen(str);

	for(int i=0;i<=sz-1;i++)
	{
		str[i]=str[sz-1-i];
	}
	str[sz]='\0';

}

void printCString( const char* str ) 
{
	cout << "\"" << str << "\" | Size: " << strlen(str) << endl;
}