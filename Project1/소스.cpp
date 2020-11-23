#include <Windows.h>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(void)
{
	ifstream fcin("login\\login.txt");

	string str;
	getline(fcin, str, ',');
	cout << str << endl;

	getline(fcin, str, ',');
	cout << str << endl;

	system("pause");
	return 0;
}
