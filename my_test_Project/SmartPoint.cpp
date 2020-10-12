#include "SmartPoint.h"

template <class T>
SmartPoint<T>::SmartPoint(T* p)
{
	cout << "SmartPoint(PointClass* p)" << endl;
	this->p = p;
}

template <class T>
SmartPoint<T>::~SmartPoint()
{
	cout << "~SmartPoint()" << endl;
	delete p;
}

template <class T>
T& SmartPoint<T>::operator*()
{
	cout << "operator*()" << endl;
	return *p;
}

template <class T>
T* SmartPoint<T>::operator->()
{
	cout << "operator->()" << endl;
	return p;
}