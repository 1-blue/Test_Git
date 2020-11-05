#include <iostream>
#include <Windows.h>

using namespace std;

class Parents
{
public:
	void show()
	{
		cout << "Parents" << endl;
	}

};

class Test : public Parents
{
public:
	void show2()
	{
		Parents::show();
		cout << "Test()" << endl;
	}


};

int main(void)
{
	Test t;

	t.show2();



	return 0;
}