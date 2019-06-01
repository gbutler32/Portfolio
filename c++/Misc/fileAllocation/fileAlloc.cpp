//N = new file
//S = search for file
//D = delete file
//M = modify file
//R = rename file
//
//This program simulates file allocation

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <queue>
#include <string>


using namespace std;

void printFileList();
int format(int totalSize, int blockSize);
void newFile(string name, int size);
int findOpen(int size);
void defrag();
void order();
int merge(string name, int size);
int findFile(string name);
int deleteFile(string in);
int rename(string name, string newName);
int modify(string name, int size);
int totalUnused();

struct file
{
private: bool inUse;
private: int size;
private: string name;

public: file(int size)
{
	this->size = size;
	inUse = false;
}

public: file()
{
	size = 0;
	inUse = false;
}

public: file(string name, int size)
{
	this->name = name;
	this->size = size;
	inUse = true;
}

public: int use(string name, int useSize)
{
	int remainder = 0;
	this->name = name;
	inUse = true;
	remainder = size - useSize;
	this->size = useSize;
	return remainder;
}

public: bool getInUse()
{
	return inUse;
}

public: int getSize()
{
	return size;
}

public: string getName()
{
	return name;
}

public: void printInfo()
{
	cout << "In Use: ";
	if (inUse == true)
	{
		cout << "true  ";
		cout << "used by: " << name << "  ";
	}
	else
	{
		cout << "false" << "  ";
	}
	cout << "Size: " << size << endl;
}
public: void setSize(int in)
{
	this->size = in;
}
public: void rename(string name)
{
	this->name = name;
}
};

deque<file> fileList;
int global_clusterSize;
int global_totalSize;


int rename(string name, string newName);
int modify(string name, int size);
int totalUnused();


int main()
{
	int totalSize = 0;
	int clusterSize = 0;
	char cmd;
	string name;
	int size;
	string line;
	int result;
	string newName;

	ifstream input;
	input.open("input.txt");
	input >> totalSize;
	input >> clusterSize;
	::global_clusterSize = clusterSize;
	::global_totalSize = totalSize;

	cout << "Request to format " << totalSize << " into clusters of " << clusterSize << endl;

	result = format(totalSize, clusterSize);
	if (result != -1)
	{
		printFileList();

		while (input)
		{
			input >> cmd;

			if (cmd == 'N')
			{
				cout << "Request for new file";
				input >> name;
				cout << " \"" << name << "\"" << endl;
				input >> size;

				getline(input, line);

				newFile(name, size);
			}
			else if (cmd == 'S')
			{
				input >> name;
				result = findFile(name);

				getline(input, line);

				if (result != -1)
				{
					cout << "File " << name << " found at pos " << result << endl;
				}
				else
				{
					cout << "File " << name << " not found" << endl;
				}
			}
			else if (cmd == 'D')
			{
				cout << "Request to delete file ";
				input >> name;
				cout << "\"" << name << "\"" << endl;

				result = deleteFile(name);

				if (result == -1)
				{
					cout << "File not found" << endl;
				}
				else
				{
					cout << "File " << name << " deleted successfully" << endl;
					printFileList();
				}
			}
			else if (cmd == 'R')
			{
				cout << "Request to rename file \"";
				input >> name;
				cout << name << "\" to \"";
				input >> newName;
				cout << newName <<"\""<< endl;

				result = rename(name,newName);
				if (result != -1)
				{
					cout << "File \""<< name << "\" renamed to \"" << newName <<"\""<< endl<<endl;
				}
				else
				{
					cout << "File " << name << " not found" << endl << endl;
				}
			}
			else if (cmd == 'M')
			{
				input >> name;
				input >> size;
				cout << "Request to modify file \"" << name << "\" to size " << size << endl;
				result = modify(name, size);
				if (result == -1)
				{
					cout << "File " << name << " not found" << endl << endl;
				}
				else if (result == -2)
				{
					cout << "New file is too large" << endl << endl;
				}
				else
				{
					cout << "File " << name << " modified successfully" << endl<<endl;
				}
			}
			cmd = '\0';
			name = "";
			newName = "";
			size = 0;
		}
		input.close();

		return 0;
	}
	else
		return -1;
}

void printFileList()
{
	cout << "List of Files:" << endl;
	if (::fileList.size() != 0)
	{
		for (int a = 0; a != ::fileList.size(); a++)
		{
			::fileList[a].printInfo();
		}
	}
	else
	{
		cout << "(empty)" << endl;
	}
	cout << endl;
}

int format(int totalSize, int blockSize)
{
	if (blockSize < totalSize)
	{
		while (totalSize != 0)
		{
			file temp(blockSize);
			::fileList.push_back(temp);
			totalSize = totalSize - blockSize;
		}
		return 0;
	}
	else
	{
		cout << "block size cannot be larger than total size" << endl;
		return -1;
	}
}

void newFile(string name, int size)
{
	int result;
	result = findFile(name);
	if (result == -1)
	{
		if (size > ::global_totalSize)
		{
			cout << "file size cannot be larger than total size" << endl;
		}
		else
		{
			int open = findOpen(size);
			int left = 0;
			if (open == -1)
			{
				cout << "Unable to find a large enough block" << endl;
				cout << "Attempting merge of multiple blocks for file" << name << endl;
				open = merge(name, size);

				if (open != 0)
				{
					cout << "Unable to to fit file" << endl;
				}
			}
			else
			{
				left = ::fileList[open].use(name, size);
				if (left > 0)
				{
					file temp(left);
					::fileList.push_back(temp);
				}
			}

			defrag();
			printFileList();
		}
	}
	else
	{
		cout << "file \"" << name << "\" already exists\n" << endl;
	}
}

int findOpen(int size)
{
	for (int a = 0; a != ::fileList.size(); a++)
	{
		if (::fileList[a].getSize() >= size && ::fileList[a].getInUse() == false)
		{
			return a;
		}
	}
	return -1;
}

void defrag()
{
	for (int a = 0; a != ::fileList.size(); a++)
	{
		if (::fileList[a].getSize() != ::global_clusterSize && ::fileList[a].getInUse() == false)
		{
			for (int b = 0; b != ::fileList.size(); b++)
			{
				if (::fileList[b].getSize() != ::global_clusterSize && ::fileList[b].getInUse() == false)
				{
					if (::fileList[a].getSize() + ::fileList[b].getSize() <= ::global_clusterSize && b != a)
					{
						::fileList[a].setSize(::fileList[a].getSize() + ::fileList[b].getSize());
						::fileList.erase(::fileList.begin() + b);
						b--;

					}
					else if (::fileList[a].getSize() + ::fileList[b].getSize() > ::global_clusterSize && b != a)
					{
						int temp = ::fileList[a].getSize() + ::fileList[b].getSize();
						temp = temp - ::global_clusterSize;
						::fileList[a].setSize(::global_clusterSize);
						::fileList[b].setSize(temp);
					}
				}
			}
		}
	}
	order();
}

void order()
{
	for (int a = 0; a != ::fileList.size() - 1; a++)
	{
		if (::fileList[a].getInUse() == false)
		{
			if (::fileList[a].getSize() < ::fileList[a + 1].getSize())
			{
				file temp;
				temp = ::fileList[a];
				::fileList[a] = ::fileList[a + 1];
				::fileList[a + 1] = temp;
			}
		}
	}
}

int merge(string name, int size)
{
	int total = 0;
	deque<int> list;

	for (int a = 0; a != ::fileList.size(); a++)
	{
		if (::fileList[a].getInUse() == false)
		{
			total = total + ::fileList[a].getSize();
			list.push_back(a);
		}
		if (size <= total)
		{
			cout << "able to fit " << size << " in " << total << " using blocks ";
			for (int c = 0; c != list.size(); c++)
			{
				cout << list[c] << " ";
			}
			cout << endl;

			file temp(name, size);
			::fileList.push_back(temp);

			if (total - size != 0)
			{
				file newBlock(total - size);
				::fileList.push_back(newBlock);
			}

			while (list.size() != 0)
			{
				if (list[0] != 0)
				{
					::fileList.erase(::fileList.begin() + list[0] - 1);
				}
				else
				{
					::fileList.erase(::fileList.begin() + list[0]);
				}
				list.pop_front();
			}
			total = 0;

			return 0;
		}
	}
	return 1;
}

int findFile(string name)
{
	for (int a = 0; a != ::fileList.size() - 1; a++)
	{
		if (::fileList[a].getName() == name)
		{
			return a;
		}
	}
	return -1;
}

int deleteFile(string in)
{
	int result = 0;
	int size = 0;

	result = findFile(in);

	if (result == -1)
	{
		return -1;
	}
	else
	{
		size = ::fileList[result].getSize();
		::fileList.erase(::fileList.begin() + result);
		file temp(size);
		::fileList.push_back(temp);
		defrag();
		order();

		return 0;
	}
}

int rename(string name, string newName)
{
	string result;
	int pos;
	pos = findFile(name);
	if (pos != -1)
	{
		result = ::fileList[pos].getName();
		::fileList[pos].rename(newName);
		return pos;
	}
	else
		return pos;
}

int modify(string name, int size)
{
	int unused;
	int pos;

	pos = findFile(name);
	if (pos != -1)
	{
		unused = totalUnused();
		if (unused + ::fileList[pos].getSize() >= size)
		{
			deleteFile(name);
			newFile(name, size);

			return 0;
		}
		else
		{
			return -2;
		}
	}
	else
		return -1;
}

int totalUnused()
{
	int total = 0;
	for (int a = 0; a != ::fileList.size(); a++)
	{
		if (::fileList[a].getInUse() == false)
		{
			total = total + ::fileList[a].getSize();
		}
	}
	return total;
}
