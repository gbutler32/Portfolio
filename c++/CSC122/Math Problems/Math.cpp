// Example program
//#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	string test;
	int n = 0;
	bool t = false;
	int tarr[50];
	int temp_h, temp_l;
	cout << "Enter a section followed by the problem set:\n";
	cin >> ws;
	if (cin.peek() == '\"')
	{
		getline(cin, test, '\"');
	}
	while (!isdigit(cin.peek()))
	{

		if (!isdigit(cin.peek()))               //assign string
		{
			test.push_back(cin.get());

		}
		if (isdigit(cin.peek()))
		{
			t = true;
		}
	}

	while (t == true)                             //assign array
	{
		if (!isdigit(cin.peek()))
		{
			if (cin.peek() == '-')
			{
				cin.ignore();

				if (isdigit(cin.peek()))
				{
					cin >> temp_h;
				}
				temp_l = tarr[n-1];
			
				while (temp_h != temp_l)
				{
					tarr[n] = temp_h;
					temp_h--;
					n++;
				}
			}
			if ((cin.peek() == ',') || (cin.peek() == ' '))
			{
				cin.ignore();
			}
		}
		if (isdigit(cin.peek()))
		{

			cin >> tarr[n];
			n++;
		}
		else
		{
			t = false;
			n=n-1;
		}

	}

	cout << "Do Problems: ";
	temp_l = 0;
	do
	{
		if (temp_l >= 10)
		{
			cout << "\n";
		}
		cout << tarr[n] << ", ";
		n--;
		temp_l++;
	} while (n != 0);
	cout << " and " << tarr[n] << " of " << test<<"\n";

	//system("pause");
	return 0;
	
}
