#ifndef STREXTRA_H
#define STREXTRA_H

#include <string>

int find(std::string test, char find, int fPos)
{
	return test.find_first_of(find, fPos);
}

int find(std::string test, std::string find, int fPos)
{
	return test.find(find, fPos);
}

#endif
