#include <string>
#include <iostream>
#include "point.h"

using namespace std;

int main()
{
	
	Point A;
	Point B;
	Point C;

	A.set_x(5);
	A.set_y(10);

	B.set_x(25);
	B.set_y(25);

	cout << "Point A: " << A;
		cout<<"\n";
		cout << "Point B: " << B;
		cout<< "\n";

		cout << "Midpoint (A/B): " << (A / B);
		cout<< "\n";
		cout << "A+B: " << (A + B);
		cout<< "\n";
		cout << "A-B: " << (A - B);
		cout<< "\n";
		cout << "B-A: " << (B - A);
		cout<< "\n";
	cout << "B=A?: " << (A == B?"True":"False") << "\n";
	cout << "B!=C? " << (A != B ? "True" : "False") << "\n";

	B = A;
	cout << "B is now equal to A:" << B;

	if (C.get_y() == 0.0)
	{
		cout << "\nInput Point C in (x,y) format\n";
		cin >> C;
		while ((C.get_x() == 0.0) || (C.get_y() == 0.0))
		{
			cout << "\nTry again: ";
			cin.clear();
			cin >> C;
		}
		cout << "\n";
	}
	cout << "Your Point C: " << C;
	cout<< "\n";
	cout << "Midpoint (B/C): " << (B / C);
	cout<< "\n";
	cout << "B+C: " << (B + C);
	cout<< "\n";
	cout << "B-C: " << (B - C);
	cout<< "\n";
	cout << "C-B: " << (C - B);
	cout<< "\n";
	cout << "B=C?: " << (B == C ? "True" : "False") << "\n";
	cout << "B!=C? " << (B != C ? "True" : "False") << "\n";
	
	
	return 0;
}