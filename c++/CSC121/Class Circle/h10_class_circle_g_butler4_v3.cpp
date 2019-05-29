/*
======================================================================
Course: Harper CSC121-003 by Mr. Jin Guo, Fall 2014

Student Name: Gary Butler

Program name: Class Rectangualar.

Progrma description: 
	The class should have one private data member: radius. Its 
	public member functions include the following:
		Rectangular(...) // this is a constructor
		void setRadius(...) {...}
		double getArea(...) {...}			
		double getCircumference(...) {...} 
		void printInfo();
		( Notes: Circumference = 2 * PT * R. )

Your job:
	Imitate the sample program s10_class_rectangular.cpp to 
	implement the Circle class and write testing code in the 
	main() function. At least two objects of Circle should be 
	created.
	
File(s): h10_class_circle_g_butler4.cpp

Created: 	4/3/2012
Modified:	11/10/2014 by Jin Guo. Customized for Haper.
========================================================================
*/
#include "stdafx.h"
#include <iostream>
using namespace std;

const double PI = 3.14159; // an alias for a constant

class Circle
{
public:
	// <<<<< Your job here <<<<<<
	Circle(double r)
	{
		radius=r;
	}
	void setRadius(double r) {radius =r;}// re-set radius
	double getArea() const {return (PI*pow(radius,2));}// return area
	double getCircumference() const {return (2*PI*radius);}// return circumference
	void printInfo() {cout<<"Radius: " << getRadius() << "\nArea: " << getArea() << "\nCircumference: " << getCircumference() << endl;}// print out info
	double getRadius()const {return radius;}

private: 
	// <<<<< Your job here <<<<<<
	double radius;// radius;
};

int main ()
{
	cout << "==================================================================\n";
	cout << "Harper CSC121-003: Assignment #9, 2014 Fall\n";
	cout << "Student: Gary Butler\n\n";
	cout << "This program will create a circle class and test it. \n";
	cout << "==================================================================\n\n";

	// <<<<< Your job here <<<<<<
	// Imitate the code of s10_class_rectangular.cpp to test your class definition.
	Circle c1(5);
	cout<<"Declared a circle c1 with a radius of "<<c1.getRadius()<<" ...\n";
	c1.printInfo();
	cout<<"\n";
	cout<<"After doubling the radius to "<<2*c1.getRadius()<<" ...\n";

	c1.setRadius(2*c1.getRadius());
	c1.printInfo();
	cout<<"___________________________________________\n";

	Circle c2(7);
	cout<<"Declared a circle c2 with a radius of "<<c2.getRadius()<<" ...\n";
	c2.printInfo();
	cout<<"\n";
	cout<<"After doubling the radius to "<<2*c2.getRadius()<<" ...\n";

	c2.setRadius(2*c2.getRadius());
	c2.printInfo();
	cout<<"\n";

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
