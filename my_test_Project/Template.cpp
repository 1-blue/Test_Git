#include "Template.h"

template <class T>
Template<T>::Template(int len) : len(len)
{
	cout << "Template(int len)" << endl;
	arr = new T[len];
}

template <class T>
Template<T>::~Template()
{
	cout << "~Template()" << endl;
	delete[] arr;
}

template <class T>
int Template<T>::length()
{
	return len;
}

template <class T>
T& Template<T>::operator[](int idx)
{
	if (idx < 0 || idx >= len)
	{
		cout << "인덱스 범위초과" << endl;
		exit(1);
	}

	return arr[idx];
}