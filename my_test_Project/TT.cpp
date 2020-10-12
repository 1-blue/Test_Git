#include "TT.h"

template <class T>
TT<T>::TT(int len) : len(len)
{
	arr = new T[len];
}

template <class T>
TT<T>::~TT()
{
	delete[] arr;
}

template <class T>
T& TT<T>::operator[](int idx)
{
	if(idx < 0 || idx >= len)
	{
		cout << "인덱스범위초과" << endl;
		exit(1);
	}
	
	return arr[idx];
}

template <class T>
int TT<T>::length()
{
	return len;
}