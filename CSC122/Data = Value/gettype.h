#ifndef GETTYPE_H
#define GETTYPE_H

#include <string>

int get_type(std::string in,std::string (&cat)[4])
{
	char type;
	bool f = false;

	int t = (in.find_first_of('<', 0) + 1);
	type = in[t];
	if ((type == 's'))//<student>
	{
		return 48;
	}
	if (type == '/')//</student>
	{
		return 50;
	}
	for (int i = 0; i < 3; i++)
	{
		if (type == cat[i][0])//check in to wordset
		{
			type = in[t + 1];
			if (type == cat[i][1])
			{
				f = true;
				return (i + 1);
			}
			else if (type == cat[i + 1][1])
			{
				f = true;
				return (i + 2);
			}

		}
	}
	if (f == false)//word not found
	{
		return 49;
	}

}

#endif