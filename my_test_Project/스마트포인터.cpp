#include <iostream>

using namespace std;

class Point
{
	int xPos, yPos;
public:
	Point(int x = 0, int y = 0) :xPos(x), yPos(y)
	{	
		cout << "Ponit()" << endl;
	}
	~Point()
	{
		cout << "~Point()" << endl;
	}
	void SetPos(int x, int y)
	{
		xPos = x;
		yPos = y;
	}
	friend ostream& operator<<(ostream& os, const Point& p);
};

ostream& operator<<(ostream& os, const Point& p)
{
	os << "[" << p.xPos << ", " << p.yPos << "]" << endl;
	return os;
}

class sPtr
{
	Point* ptr;
public:
	sPtr(Point* p)
	{
		cout << "sPtr(Point*& p)" << endl;
		ptr = p;
	}
	Point& operator*() const
	{
		cout << "Point& operator*()" << endl;
		return *ptr;
	}
	Point* operator->() const
	{
		cout << "Point* operator->()" << endl;
		return ptr;
	}
	~sPtr() {
		cout << "~sPtr()" << endl;
		delete ptr;
	}
};


int main(void)
{
	sPtr ptr(new Point(3, 3));

	cout << *ptr;

	ptr->SetPos(5, 5);

	cout << *ptr;

	//delete하지않아도 자동으로 delete해줌... 스마트포인터


	return 0;
}