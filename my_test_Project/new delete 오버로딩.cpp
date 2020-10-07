#include <iostream>

using namespace std;

class Test {
	int x, y;
public:
	Test() {
		cout << "Test()" << endl;
	}
	Test(int x, int y):x(x), y(y) {
		cout << "Test(int x, int y)" << endl;
	}
	static void* operator new(size_t size) {
		cout << "void* operator new(size_t size)" << endl;
		void* ptr = new char[size];
		return ptr;
	}
	static void* operator new[](size_t size) {
		cout << "void* operator new[](size_t size)" << endl;
		void* ptr = new char[size];
		return ptr;
	}
	static void operator delete(void* ptr) {
		cout << "static void operator delete(void* ptr)" << endl;
		delete[]((char*)ptr);
	}
	static void operator delete[](void* ptr) {
		cout << "static void operator delete[](void* ptr)" << endl;
		delete[]((char*)ptr);
	}
	~Test() {
		cout << "~Test()" << endl;
	}
};

int main(void)
{
	Test* t = new Test[3];

	delete[] t;

	return 0;
}