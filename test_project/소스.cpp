#include <iostream>
#include <Windows.h>

using namespace std;

int main(void)
{
	ULONGLONG sTime = 0;

	sTime = GetTickCount64();
	int i = 0;

	while(true)
	{
		if (sTime + 1000 < GetTickCount64())
		{
			sTime = GetTickCount64();
			i++;
			cout << i << endl;
		}
	}



	return 0;
}