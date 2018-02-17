#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;


int main()
{
	vector<int> pos;
	vector<int>::iterator i_p=pos.begin();

	fstream filei;
	string fn;
	string temp, find;
	bool found = false;
	bool again = true;
	bool p = false;
	char c_temp;
	int lines = 0;

	cout << "Enter name of file: ";
	getline(cin >> ws, fn);
	if (fn.find_first_of('.') == -1)
	{
		fn.append(".txt");
	}
	filei.open(fn.c_str());

	if (filei.fail())
	{
		while (filei.fail())
		{
			filei.close();
			filei.clear();
			cout << "\nTry again";
			cout << "\nEnter name of file: ";
			getline(cin >> ws, fn);
			if (fn.find_first_of('.') == -1)
			{
				fn.append(".txt");
			}

			filei.open(fn.c_str());
		}
	}
	else
	{
		cout << "Opening: " << fn<<"\n";
	}
	while (again == true)
	{
		cout << "Enter name to be searched for: ";
		getline(cin, find);
		c_temp = find[0];
		filei.peek();
		while (!(filei.eof()))
		{
			getline(filei, temp);
			lines++;
			if ((temp[0] == c_temp) || (temp[0] == (toupper(c_temp))))
			{
				found = true;

				pos.push_back(lines);//add line number

				for (int a = 1; a < find.length(); a++)
				{
					c_temp = find[a];
					if ((temp[a] != c_temp) && (temp[a] != (toupper(c_temp))))
					{
						if (p == false)
						{
							cout << "Partal match on line: " << lines << "\n";
							cout << "Did you mean: " << temp << "?\n";
							p = true;
						}
						found = false;
					}
				}
				filei.peek();
				c_temp = find[0];
			}


		}
		
		if (found == false)
		{
			cout << "name not found";
		}
		else
		{
			cout << "Name found on line(s): ";
			for (i_p = pos.begin(); i_p != pos.end(); i_p++)
			{
				cout << *i_p;
				if ((i_p+1) != pos.end())
				{
					cout << " & ";
				}
					
			}
		}
		cout << "\nAgain? (Y/N)";
		cin >> fn;
		if ((fn == "Y") || (fn == "y"))
		{
			again = true;
			found = false;
			p = false;
			lines=0;
			pos.clear();
			cin.clear();
			filei.clear();
			filei.seekg(0,ios::beg);
			getline(cin,find);
		}
		else
		{
			filei.close();
			again = false;
		}
	}
	return 0;
}