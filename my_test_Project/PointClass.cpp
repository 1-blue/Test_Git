#include "PointClass.h"

template <class T>
PointClass<T>::PointClass() : x(0), y(0)
{
	cout << "PointClass" << endl;
}

template <class T>
PointClass<T>::PointClass(T x, T y) : x(x), y(y)
{
	cout << "PointClass(T x, T y)" << endl;
}

template <class T>
void PointClass<T>::SetData(T x, T y)
{
	this->x = x;
	this->y = y;
}

//이부분좀더 알아보기... <>이거
//template <class T>
//ostream& operator<< <>(ostream& os, const PointClass<T>& p)
//{
//	os << "TTTTTT" << endl;
//	os << "[" << p.x << ", " << p.y << "]";
//	return os;
//}

