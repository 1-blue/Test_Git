#include <iostream>
#include <list>
#include <array>

using namespace std;

int main(void)
{
	array<int, 2> arr;

	arr[0] = 1;
	arr[1] = 2;
	

	for (const auto& a : arr)
		cout << a << endl;


	cout << (45+47) % 47;

	return 0;
}