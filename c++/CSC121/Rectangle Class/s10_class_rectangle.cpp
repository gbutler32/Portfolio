/* 
=============================================================================
Course: Harper CSC-121, Fall 2014

Program name: Class Rectangular.

Program description: 
	The class has two private data members: width and length. Its 
	public member functions include the following:
		Rectangular(...) // constructor
		void setSides(...) {...}
		double getArea(...) {...}			
		double getPerimeter(...) {...}
		bool isSameArea(...) {...}

In the main() function, some objects of class Rectangle are created and
are used to test the class definition and its member funtions.
	
File(s): s10_class_rectangular.cpp

Created: 	9/8/2007 by Jin Guo
Modified:	6/3/2012 by Jin Guo. Format changed.
Modified:	11/10/2014 by Jin Guo. Customized for Harper.
Modified:	11/10/2014 by Jin Guo. Added member functino isSameArea().
================================================================================
*/
#include <iostream>
#include <iomanip>	// for fixed, setprecision()

using namespace std;

class Rectangle
{
public:
	Rectangular(double w, double l) // this is a constructor
	{ 
		width = w;
		length = l; 
	}
	void setSides(double w, double l) { width = w, length = l; }
	void printInfo()const;
	void printSides() const { cout << "Sides: " << width << " x " << length;};
	double getArea() const { return (width * length); }
	double getPerimeter() const { return (2 * width + 2 * length); }
	bool isSameArea(Rectangular rect) const { return (getArea() == rect.getArea()); }


private: 
	double width;
	double length;
};


int main ()
{
	cout << "=======================================================================\n";
	cout << "Harper CSC-121, s_10_class_rectangle.cpp\n";
	cout << "This program constructs and tests the Rectangular class. User is asked \n";
	cout << "to enter width and length from keyboard.\n";
	cout << "=======================================================================\n\n";

	cout << fixed << setprecision( 2 );

	cout << "Constuct a rectangle of 10.00 x 20.00...\n";
	Rectangle rect1(10,20);
	cout << "rect1: \n";
	rect1.printInfo();
	cout << "\n";

	double w, l;
	cout << "Construct another rectangle...\n";
	cout << "Input width and length for a rectangular\n";
	cout << "(seperated by a space) ==> ";
	cin >> w >> l;
	Rectangle rect2(w,l); // use constructor to create an object.

	cout << "\nrect2: \n";
	rect2.printInfo();
	cout << "\n";

	cout << "After resetting sides of rect2 to 5 x 8...\n";
	rect2.setSides(5, 8); // re-set the width and length	
	cout << "rect2: \n";
	rect2.printInfo();
	cout << "\n";

	cout << "\nCompare if rect1 and rect2 are the same large...\n";
	if (rect1.isSameArea(rect2))
		cout << "rect1 and rect2 are the same large.\n";
	else
		cout << "rect1 and rect2 have different areas!\n\n";

	return 0;
}

void Rectangle::printInfo()const
{
	printSides();
	cout << "; Area: " << getArea() << "; Perimeter: " << getPerimeter() << endl;
}
