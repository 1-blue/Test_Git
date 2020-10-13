#include "Point.h"

template <class T>
Point<T>::Point() : x(0), y(0)
{
	cout << "Point()" << endl;
}

template <class T>
Point<T>::Point(int x, int y) : x(x), y(y)
{
	cout << "Ponit(int x, int y)" << endl;
}

template <class T>
Point<T>::~Point()
{
	cout << "~Point()" << endl;
}

template <class T>
ostream& operator<< <>(ostream& os, Point<T>& p)
{
	os << "[" << p.x << ", " << p.y << "]";
	return os;
}