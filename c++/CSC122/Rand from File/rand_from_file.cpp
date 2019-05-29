#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include <stdlib.h>

using namespace std;

int read_l(string in, ofstream & dex, int line);
string grab(ifstream & infile, int line);

int main()
{
	string fn;
	ifstream filei;
	ifstream ind;
	ofstream to_index;
	string d_fn;
	int wc=0;
	int linec=0, liner;
	int menu;
	string temp;
	char find;



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
		cout << "Opening: " << fn << "\n";
	}

	d_fn = fn[0];
	d_fn.append("_ind.txt");

	to_index.open(d_fn.c_str());

	filei.peek();
	while (!(filei.eof()))
	{
		cout << "Got Line\n";
		++linec;
		getline(filei, temp);
		
			wc = read_l(temp, to_index, linec);
			temp.erase();
			filei.peek();

	}
	cout << "done!\n";
	to_index.close();
	filei.clear();
	filei.seekg(0, ios::beg);

	ind.open(d_fn.c_str());
	cout << "Would you like to:\n1) display random Word\n2) display random Line\n3) Quit\n";
	cin >> ws;
	if (isdigit(cin.peek()))
	{
		cin >> menu;
	}
	else if (!(isdigit(cin.peek())) && (!isspace(cin.peek())))
	{
		cin >> d_fn;
		if ((d_fn == "W") || (d_fn == "w"))
		{
			menu = 1;
		}
		if ((d_fn == "L") || (d_fn == "l"))
		{
			menu = 2;
		}
		if ((d_fn == "Q") || (d_fn == "q"))
		{
			menu = 3;
		}
	}
	if (menu != 3)
	{
		if (menu == 1)//word
		{
			srand(time(NULL));
			liner = (rand() % linec + 1);

			
			ind >> wc;
			while (wc != liner)//find line
			{
				getline(ind,temp);
				ind >> wc;
			}
			if (wc == liner)//find word count in index
			{
				ind >> ws;
				ind >> wc;
			}

			temp = grab(filei, liner);

			srand(time(NULL));
			wc = (rand() % wc + 1);

			liner = 0;//word count
			menu = 0;//parser
			while (liner != wc)//find words based on spaces
			{
				if (isspace(temp[menu]))
				{
					liner++;
				}
				menu++;
			}
			
			if (liner == wc)//if rand pos found
			{
				liner = 0;
				while (!isspace(temp[liner]))
				{
					liner++;
				}
			}
			
				temp =temp.substr(menu, (liner));
		}
		if (menu == 2)//line
		{
			srand(time(NULL));
			linec = rand() % linec + 1;
			temp = grab(filei, linec);
		}
	}
		cout << "output: " << temp;

	system("pause");
	return 0;

}

int read_l(string in, ofstream & dex,int line)
{
	dex << line << " ";
	line = 0;
	for (int c = 0; c != in.length(); c++)
	{
		if (isspace(in[c]))
		{
			line++;
		}
	}
	line++;
	dex << line <<endl;
	return line;
}

string grab(ifstream & infile,int line)
{
	string words;
	int a = 0;
	while (a != line)
	{
		getline(infile, words);
		words.clear();
		a++;
	}
	if (a == line)
	{
		getline(infile, words);
	}
	infile.clear();
	infile.seekg(0);
	return words;
}

