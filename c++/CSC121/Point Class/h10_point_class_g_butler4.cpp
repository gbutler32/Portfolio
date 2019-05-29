/*
================================================================================
Course: Harper CSC121 by Mr. Jin Guo, Fall 2014

Program name: Point class

Program description: 	
	This program defines and test class Point.

Your job:
	1. Understand and run the given program without any change.
	2. Split the program into three files: one is the .h file which contains 
		the class declaration, a .cpp file to define the class and another 
		.cpp file to test the class.
	3. Notes: include header files only as needed for each file.
	4. You need to submit three files as follows.

Notes:
	1. Include header files only as needed for each file.
	2. A function defined within class declaration is "inline".
	3. You add "inline" at the beginning for a function definition
		outside of the class declaration.

Files: 
	You are given one file s10_point_class.cpp. You need submit three
	files as follows:
	h10_point_class_<yr_login>.h: class Point declaration.
	h10_point_class_<yr_login>.cpp: define class Point.
	h10_point_class_test_<yr_login>.cpp: test the class Point.

Created:	6/28/2012 by Jin Guo
Modified:	11/18/2014 by Jin Guo. Customized for Harper.
===============================================================================
*/
#include "stdafx.h"
#include "h10_point_class_g_butler4.h"
#include <iostream>
#include <math.h>  // for sqrt()


using namespace std;
// ============================================
// Definitions of some Point member functions
// ============================================
void Point::print()
{
	cout << "(" << x << ", " << y << ")" << endl;
}

void Point::resetXY(double new_x, double new_y)
{
	x = new_x;
	y = new_y;
}

Point Point::add(const Point &p2) const
{
	return Point(x + p2.x, y + p2.y);
}

Point Point::sub(const Point &p2) const
{
	return Point(x - p2.x, y - p2.y);
}

void Point::move(double a, double b)
{
	x += a;
	y += b;
}

double Point::distanceTo(const Point &p2) const
{
	double xDiff = x - p2.x;
	double yDiff = y - p2.y;

	return sqrt(xDiff * xDiff + yDiff * yDiff);
}
