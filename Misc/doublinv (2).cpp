#include <iostream>

using namespace std;

int main()
{  
	
	double rate;
	double principal;
	double balance;
	int years = 0;

	cout << "How many years can I double my money by investment?\n";
	cout << "Input your principal ==> ";
	cin >> principal;
	cout << "Input the yearly interest rate (e.g., 0.04) ==> "; 
	cin >> rate;

	balance = principal;

	do 
	{
		balance = balance * (1 + rate);
		years++; 

	} while (balance < 2 * principal);

	cout << "The investment doubled after "
	  << years << " years.\n";

	return 0;
}

/*
rate: 0.05
principal: 1000
year: n
balance: 

year	balance
1		1000 + 1000 * 0.05 = 1000 * (1 + 0.05) = 1000 * 1.05
2		1000 * 1.05 + (1000 * 1.05) * 0.05 = 1000 * 1.05 * (1 + 0.05) = 1000 * 1.05^2
3		1000 * 1.05^3
..
n		1000 * 1.05^n

*/