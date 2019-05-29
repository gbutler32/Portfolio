#include <string>
#include <iostream>
#include <istream>
#include <vector>
#include <fstream>
#include "ctype.h"
#include "frame.h"

using namespace std;

int main()
{
	int menu = 0;
	int menu2 = 0;
	string work;
	ifstream file;
	ofstream ofile;
	char c;


	frame A;
	cout << "Input from file(1) or from keyboard(2):";
	cin >> menu;
	cout << "\n";
	if (menu == 1)
	{
		cout << "Enter Filename:\n";
		cin >> work;
		if (work.find_first_of('.') == -1)
		{
			work.append(".txt");
		}
		if (isalpha(work[0]) || isdigit(work[0]))
		{
			file.open(work.c_str());
		}
		else
		{
			while ((!isalpha(work[0])) && (!isdigit(work[0])))
			{
				work.clear();
				cout << "\nTry again";
				cout << "\nEnter file to be written to: ";
				cin >> work;
				if (work.find_first_of('.') == -1)
				{
					work.append(".txt");
				}
			}
		}
		work.clear();
		getline(file, work);
		A.in_str(work);
	}
	cout << "Output to file(1) or screen(2):\n";
		cin >> menu2;
		if (menu2 == 1)
		{
			cout << "Enter filename to write to: ";
			cin >> work;
			if (work.find_first_of('.') == -1)
			{
				work.append(".txt");
			}
			ofile.open(work.c_str());
		}
	if (menu == 2)
	{
		cout << "Enter string:\n";
		cin>>ws;
		getline(cin, work);
		A.in_str(work);
	}
	cin.clear();

	cout << "\nBorder type: (S)ingle Line, (D)ouble Line, or a char:\n";
	cin >> c;
	A.set_bt(c);

	cout << "\nShaded?(Y/N):";
	cin >> c;
	if ((c == 'Y') || (c == 'y'))
	{
		cout << "\nEnter shaded char: ";
		cin >> c;
		A.set_board2(c);
	}

	cout << "\nEnter Justification: (C)enter (L)eft (R)ight\n";
	cin >> c;
	A.set_just(c);
	
	A.in_str("\0");
	if (menu2 == 2)
	{
		cout << "Your output: \n" << A<<endl;
		if (menu == 1)
		{
			A.reset();
			while (!(file.eof()))
			{
				getline(file, work);
				A.in_str(work);
				A.in_str("\0");
				cout << A<<endl;
				A.reset();
			}
		}
	}

	if (menu2 == 1)
	{
		ofile << A;
		A.reset();
		while (!(file.eof()))
		{
			getline(file, work);
			A.in_str(work);
			A.in_str("\0");
			ofile << A;
			A.reset();
		}
	}
	file.close();
	ofile.close();

	return 0;
}

