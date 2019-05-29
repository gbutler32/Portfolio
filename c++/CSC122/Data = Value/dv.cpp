#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "gettype.h"

using namespace std;


class info{
	string name;
	string id;
	string gpa;
	string gen;

public:

	
	void add_name(string in){ name = in; }
	void add_id(string in){ id = in; }
	void add_gpa(string in){ gpa = in; }
	void add_gen(string in){ gen = in; }

	string get_name(){ return name; }
	string get_id(){ return id; }
	string get_gpa(){ return gpa; }
	string get_gen(){ return gen; }

	
	void reset()
	{
		name = "0";
		id = "0";
		gpa = "0";
		gen = "0";
	}

	info()
		:name("0"), id("0"), gpa("0"), gen("0")
	{}
};

string cat[4] = { "name", "id", "gpa", "gender" };

int main()
{
	string fn;
	string temp;
	fstream filei;
	ofstream fileo;


	vector<info> list;
	vector<info>::iterator i;
	info temp_o;


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
	filei.peek();
	while (!(filei.eof()))
	{
		getline(filei, temp);
		
		while (!temp.empty())
		{
			switch (get_type(temp, cat))
			{
			case 1://name
			{
					   temp.erase(0, (temp.find_first_of('>', 0) + 1));
					   temp.erase(temp.find_first_of('<', 0), temp.find_first_of('>', 0));
					   temp_o.add_name(temp);
					   temp.clear();
			} break;
			case 2://id
			{
					   temp.erase(0, (temp.find_first_of('>', 0) + 1));
					   temp.erase(temp.find_first_of('<', 0), temp.find_first_of('>', 0));
					   temp_o.add_id(temp);
					   temp.clear();
			}break;
			case 3://gpa
			{
					   temp.erase(0, (temp.find_first_of('>', 0) + 1));
					   temp.erase(temp.find_first_of('<', 0), temp.find_first_of('>', 0));
					   temp_o.add_gpa(temp);
					   temp.clear();
			}break;
			case 4://gender
			{
					   temp.erase(0, (temp.find_first_of('>', 0) + 1));
					   temp.erase(temp.find_first_of('<', 0), temp.find_first_of('>', 0));
					   temp_o.add_gen(temp);
					   temp.clear();
			}break;
			case 50://end of student, flush vars
			{
						temp.clear();
						list.push_back(temp_o);
						temp_o.reset();
			}break;

			default:
			{
					   temp.clear();
			}

			}break;
			filei.peek();

		}
	}
	filei.close();

	cout << "Enter file to be written to: ";
	cin >> fn;
	if (fn.find_first_of('.') == -1)
	{
		fn.append(".txt");
	}
	if (isalpha(fn[0]) || isdigit(fn[0]))
	{
		cout << "\nwriting to: " << fn;
	}
	else
	{
		while ((!isalpha(fn[0])) && (!isdigit(fn[0])))
		{
			fn.clear();
			cout << "\nTry again";
			cout << "\nEnter file to be written to: ";
			cin >> fn;
			if (fn.find_first_of('.') == -1)
			{
				fn.append(".txt");
			}
		}
	}
	fileo.open(fn.c_str());

		for ((i = list.begin()); (i != list.end()); (i++))
		{
			fileo << "<student>\n";
			if ((i->get_name()) != "0")
			{
				fileo << "<name>" << i->get_name() << "</name>\n";
			}
			if ((i->get_gpa()) != "0")
			{
				fileo << "<gpa>" << i->get_gpa() << "</gpa>\n";
			}
			if ((i->get_id()) != "0")
			{
				fileo << "<id>" << i->get_id() << "</id>\n";
			}
			if ((i->get_gen()) != "0")
			{
				fileo << "<gender>" << i->get_gen() << "</gender>\n";
			}
			fileo << "</student>"<<"\n";
		}
		fileo.close();
	
	return 0;
}

