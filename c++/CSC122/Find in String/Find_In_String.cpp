
#include <iostream>
#include <string>
#include "strextra.h"

using namespace std;

int main()
{
	string test;
	string in;
	char m = '\0';
	int a = 0;
	int pos = 1;
	int fpos = NULL;
	int cpos = 0;
	int t = 0;
	bool neg = false;

	cout << "String,pos,Find what:\n";

	if ((cin.peek() == '\"'))
	{
		cin.ignore();
		getline(cin, test, '\"');

		while(!isdigit(cin.peek()))
		{
		cin.ignore();
		}
		
		if (isdigit(cin.peek()))
		{
			cin >> cpos;
			while ((cin.peek() != '\'') && (cin.peek() != '\"'))
			{
				cin.ignore();
			}

			if (cin.peek() == '\'')
			{
				cin.ignore();
				m = getchar();
				//a = in.length();
				fpos = find(test, m, cpos);
			}
			if (cin.peek() == '\"')
			{
				cin.ignore();
				getline(cin, in, '\"');
			}
		}
		
	}

	
	while ((a != in.length()) && (cpos != -1) && (fpos != -1))
	{
		if (fpos == NULL)
		{

			if (in[0] == '*')
			{
				fpos = 0;
			}

			if (in[0] == '/')
			{
				m = getchar();
				fpos = (test, in[1], cpos);
				
				a = in.length();
			}
			if (in[0] == '?')
			{
				neg = true;
				while (fpos == NULL)
				{
					if (in[pos] == '?')
					{
						pos++;
					}
					else
					{
						cpos = find(test, in[pos], cpos);
						fpos = cpos;
					}
				}
			}
			if ((in[0] != '*') && (in[0] != '?') && (in[0] != '/'))
			{
				cpos = find(test, in[0], cpos);
				fpos = cpos;
			}

		}


			if (in[a] == '?')
			{
				t++;
				neg = true;
			}

			if (in[a] == '*')
			{
				if ((a+1) < in.length())
				{
					cpos = find(test, in[a++], cpos);
				}
				else if ((a + 1) > in.length())
				{
					cpos = find(test, in[a--], cpos);
				}
				

			}
			if ((in[a] != '?') && (in[a] != '*') && (in[a] != '/'))
			{
				cpos = find(test, in[a], cpos);
			}

			a++;
		
	}



	if (neg == true)
	{

		fpos = fpos - t;
	}

	if ((cpos != -1) || (fpos != -1))
	{
		cout << "\nFound at: " << fpos;
	}
	else(cout << "Not Found, pos : -1");
	
	
	return 0;

}


