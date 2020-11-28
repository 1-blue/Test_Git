#include <Windows.h>
#include <iostream>
#include <fstream>
#include <string>
#include <list>

using namespace std;

class A {

};

int main(void)
{
	list<A*> t;

	t.emplace_back(new A());
	t.emplace_back(new A());
	t.emplace_back(new A());
	t.emplace_back(new A());

	for (auto i : t)
	{
		delete i;
	}

	t.clear();


	system("pause");
	return 0;
}
