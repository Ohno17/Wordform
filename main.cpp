#include "extenders.h"

using namespace std;

int menu(string options[], int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << "[" << i << "]: "+options[i] << endl;
	}
	cout << endl << "Chose an option. Enter the number of the option: ";
	string x;
	cin >> x;
	int pick = stoi(x);
	if (pick < len && !(pick < 0)) return pick; else
	{
		cout << "Invalid option! Option 0 picked instead." << endl << endl;
		return 0;
	}
}

int main() 
{
	string x; 
	cout << "Enter a Number: "; 
	cin >> x;
	cout << endl << "Choose method to extend number." << endl;
	string options[2] = {"Stub", "JJexe"};
	int picked = menu(options, 2);
	switch (picked)
	{
		case 0:
			stub_ExtendedNumber(x);
			break;
		case 1:
			jjexe_ExtendedNumber(x);
			break;
	}
	cout << endl;
	return 0;
}