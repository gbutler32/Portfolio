#ifndef FRAME_H
#define FRAME_H

#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include "ctype.h"
class frame
{
public:
	std::vector<std::string> wl;
	int cpos;
	int l_pos;
	int max_l;
	char j;
	char bt;
	char b2;

	frame()
		:wl(),cpos(0),l_pos(0),max_l(0), j('\0'), bt('\0'), b2('\0')
		{}
	

	void reset()
	{
		cpos = 0;
		wl.clear();
		max_l = 0;
		l_pos = 0;
	}

	inline int get_max_length()
	{
		return max_l;
	}

	inline void set_max_length(int in)
	{
		max_l = in;
	}

	inline std::string get_wl(int pos)
	{
		return wl[pos];
	}


	inline void set_bt(char in)
	{
		if (isprint(in))
		{
			bt = in;
		}
	}
	inline char get_bt(void)
	{
		return bt;
	}

	inline void set_board2(char in)
	{
		if (isprint(in))
		{
			b2 = in;
		}
	}

	inline char get_board2(void)
	{
		return b2;
	}
	inline void set_just(char & in)
	{
		if (((in == 'l') || (in == 'c') || (in == 'r')))
		{
			if (in == 'l')
			{
				j = 'l';
			}
			if (in == 'c')
			{
				j = 'c';
			}
			if (in == 'r')
			{
				j = 'r';
			}
		}
		else(j == 'l');
	}
	inline char get_just(void)
	{
		return j;
	}

	inline std::ostream & output(std::ostream & out)
	{
		int l = get_max_length();
		std::string word = get_wl(0);
		char bt = get_bt();
		char b2 = get_board2();
		int count = 1;
		if (((bt == 'S') || (bt == 's')) || ((bt == 'd') || (bt == 'D')))
		{
			if ((bt == 'S') || (bt == 's'))
			{
				out << '+' << std::string((l + 2), '-') << '+' << std::endl;
			}
			if (((bt == 'd') || (bt == 'D')))
			{
				out << '+' << std::string((l + 2), '=') << '+' << std::endl;
			}
		}
		else
		{
			out << std::string((l + 4), bt) << std::endl;
		}
		while (word != "\0")
		{
			if (((bt == 's') || (bt == 'S')) || ((bt == 'd') || (bt == 'D')))
			{
				if ((bt == 's') || (bt == 'S'))
				{
					out << "| ";
				}

				if ((bt == 'd') || (bt == 'D'))
				{
					out << "||";
				}
			}
			else
			{
				out << bt << " ";
			}
			if (get_just() == 'l')
			{

				if (word.length() != l)
				{
					out.width(l);
					out << std::left << word;

				}
				else(out << word);
			}
			if (get_just() == 'c')
			{

				out << std::string(((l - word.length()) / 2), ' ');
				out << word;
				out << std::string((((l - word.length()) / 2)), ' ');

			}
			if (get_just() == 'r')
			{
				if (word.length() != l)
				{
					out.width(l);
					out << std::right << word;

				}
				else(out << word);
			}
			if (((bt == 's') || (bt == 'S')) || ((bt == 'd') || (bt == 'D')))
			{
				if ((bt == 's') || (bt == 'S'))
				{
					out << " |";
				}
				if ((bt == 'd') || (bt == 'D'))
				{
					out << "||";
				}
			}
			else
			{
				out << " " << bt;
			}
			if (b2 != ('\0'))
			{
				out << b2 << std::endl;
			}
			else(out << std::endl);

			word = get_wl(count);
			++count;
		}
		if ((bt == 's') || (bt == 'S') || (bt == 'd') || (bt == 'D'))
		{
			if ((bt == 's') || (bt == 'S'))
			{
				out << "+" << std::string((l + 2), '-') << "+";
				if (b2 != '\0')
				{
					out << b2;
				}
			}
			if ((bt == 'd') || (bt == 'D'))
			{
				out << "+" << std::string((l + 2), '=') << "+";
				if (b2 != '\0')
				{
					out << b2;
				}
			}
			out << std::endl;
		}
		else
		{
			out << std::string((l + 4), bt);
			if (b2 != '\0')
			{
				out << b2;
			}
			out << std::endl;
		}
		if (b2 != ('\0'))
		{
			out << " " << std::string((l + 4), b2) << std::endl;
		}
		return out;

	}

	inline void in_str(std::string in)
	{
		int a = 0;
		int s = 0;
		std::string temp;
		if (in != ("\0"))
		{
			while (a < in.length())
			{
				if ((!isspace(in[a])))
				{
					temp.push_back(in[a]);
				}
				if (isspace(in[a]))
				{
					s = a;
					if (cpos == 0)
					{
						wl.push_back(temp);
						set_max_length(temp.length());
						l_pos = 0;
						cpos++;
					}
					else
					{
						wl.push_back(temp);
						if (wl[cpos].length() > wl[l_pos].length())
						{
							l_pos = cpos;
							set_max_length(wl[cpos].length());
						}
						++cpos;
					}
					temp.clear();
				}
				a++;
			}
		}
		wl.push_back(temp);
	}

	friend std::ostream & operator<<(std::ostream & out,frame & b);//output
	
};

inline std::ostream & operator<< (std::ostream & out, frame & b)//output
{
	b.output(out);
	return out;
}


#endif