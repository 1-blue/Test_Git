#pragma once
#include <iostream>

using namespace std;

template <class T>
class PointClass
{
	T x, y;

public:
	PointClass();
	PointClass(T x, T y);
	void SetData(T x, T y);
	//friend ostream& operator<< <>(ostream& os, const PointClass<T>& p);
	friend ostream& operator<<(ostream& os, const PointClass<int>& p);
};

ostream& operator<<(ostream& os, const PointClass<int>& p)
{
	os << "TTTTTT" << endl;
	os << "[" << p.x << ", " << p.y << "]";
	return os;
}