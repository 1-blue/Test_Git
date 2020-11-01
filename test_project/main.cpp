#include <iostream>

using namespace std;

int main(void)
{
	char arr[5];
	int i = 0;
	bool a = false;

	while (i != 5)
	{
		cin.get(arr[i++]);
	}

	for (auto k : arr)
	{
		cout << k << endl;
	}

	while (!cin.eof())
	{
		cout << cin.get() << endl;
	}




	return 0;
}