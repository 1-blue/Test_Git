#include <iostream>

using namespace std;

class A {
	char c[3] = { 'a', 'b', 'c' };

	static A* a;
	A() {};

public:
	static A* GetA() {
		if (a == nullptr) {
			cout << "123" << endl;
			a = new A();
		}
			
		return a;
	}

	void show() {
		cout << c[0] << endl;
		cout << c[1] << endl;
		cout << c[2] << endl;
	}
};

A* A::a = nullptr;



int main(void)
{
	A* a = A::GetA();

	a->show();


	return 0;
}