#include <iostream>

using namespace std;

int main(void)
{
	string str = "abcdefg";

	for (int x = 0, y = str.size() - 1; x < y; x++, y--)
	{
		char temp = str[y];
		str[y] = str[x];
		str[x] = temp;
	}

	cout << str << endl;


	return 0;
}
