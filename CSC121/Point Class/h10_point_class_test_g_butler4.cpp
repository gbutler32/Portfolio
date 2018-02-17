
#include "stdafx.h"
#include <iostream>
#include <iomanip> // for setprecision
#include <math.h>  // for sqrt()
#include "Header1.h"
// =====================================
// main() function to test class Point.
// =====================================
int main()
{
	cout << "====================================================\n";
	cout << "Harper CSC-121, Sample Program: class Point\n";
	cout << "This program defines and test class Point.  \n";
	cout << "====================================================\n\n";	
	
	cout << fixed << setprecision(2); // set format of printing a floating number

	cout << "==> Test contructors, p1 with default construction, \n"
		<< "p2 with regular constructor and p3 with copy constructor...\n";
	Point p1;
	cout << "p1"; p1.print();
	Point p2(4.0, 2.0);
	cout << "p2"; p2.print();
	Point p3( p2 );
	cout << "p3"; p3.print();
	cout << "\n";

	cout << "==> Test getX() and getY() ...\n";
	cout << "x-coordinate of p2 is : " << p2.getX() << endl;
	cout << "y-coordinate of p2 is : " << p2.getY() << endl;
	cout << "\n";

	cout << "==> Reset p1 with p1.reSetXY(5.0, 5.0)...\n";
	p1.resetXY(5.0, 5.0);
	cout << "p1"; p1.print();
	cout << "\n";	

	cout << "==> After p4 = p1.add( p2 ) ...\n";
	Point p4 = p1.add( p2 );
	cout << "p4"; p4.print();
	cout << "\n";

	cout << "A==> fter p4 = p1.sub( p2 ) ...\n";
	p4 = p1.sub( p2 );
	cout << "p4"; p4.print();
	cout << "\n";

	cout << "==> Move p3 by (3, 3)...\n";
	p3.move( 3, 3 );
	cout << "p3"; p3.print();
	cout << "\n";

	cout << "==> Find distance between p3 and p4 is: " 
		<< p3.distanceTo( p4 ) << endl;

	cout << endl;

	system("pause");
	return 0;
}