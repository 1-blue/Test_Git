#include <iostream>

using namespace std;

class ATest
{
	int* arr;
	int len;
public:
	ATest(int len) : len(len)
	{
		cout << "ATest()" << endl;
		arr = new int[len];
	}
	int& operator[](int widx)
	{
		if (widx < 0 && widx >= len)
		{
			cout << "w : 인덱스범위초과" << endl;
			exit(0);
		}
		return arr[widx];
	}
	~ATest()
	{
		cout << "~ATest()" << endl;
		delete[] arr;
	}
};

typedef ATest* atestPtr;

class BTest {
	atestPtr* arr;
	int h;
public:
	BTest(int h, int w) : h(h)
	{
		cout << "BTest()" << endl;
		arr = new atestPtr[h];
		for (int i = 0; i < h; i++)
			arr[i] = new ATest(w);

	}
	ATest& operator[](int hidx)
	{
		if (hidx < 0 && hidx >= h)
		{
			cout << "h : 인덱스범위초과" << endl;
			exit(0);
		}

		return *(arr[hidx]);
	}

	~BTest() {
		cout << "~BTest()" << endl;
		for (int i = 0; i < h; i++)
			delete arr[i];
		delete[] arr;
	}
};


int main(void) {
	BTest arr(3, 4);

	for (int h = 0; h < 3; h++) {
		for (int w = 0; w < 4; w++) {
			arr[h][w] = h + w;
		}
	}

	for (int h = 0; h < 3; h++) {
		for (int w = 0; w < 4; w++) {
			cout << "arr[" << h << "][" << w << "] : " << arr[h][w] << endl;
		}
	}



	return 0;
}