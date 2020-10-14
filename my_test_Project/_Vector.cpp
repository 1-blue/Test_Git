#include "_Vector.h"

template <class T>
_Vector<T>::_Vector() : len(0), topIndex(0)
{
	cout << "_Vector()" << endl;
}

template <class T>
_Vector<T>::_Vector(int len) : len(len), topIndex(0)
{
	cout << "_Vector(int len)" << endl;
	vector = new T[len];
}

template <class T>
_Vector<T>::~_Vector()
{
	cout << "~_Vector()" << endl;
	delete[] vector;
}

template <class T>
int _Vector<T>::length()
{
	return len;
}

template <class T>
T& _Vector<T>::operator[](int idx)
{
	if (idx < 0 || idx > len)
	{
		cout << "인덱스범위초과" << endl;
		exit(1);
	}

	return vector[idx];
}

template <class T>
bool _Vector<T>::isFull()
{
	if (topIndex >= len)
		return true;
	return false;
}

template <class T>
bool _Vector<T>::isEmpty()
{
	if (topIndex <= 0)
		return true;
	return false;
}

template <class T>
bool _Vector<T>::Push(T vec)
{
	if (isFull())
	{
		cout << "vector가 가득찼습니다." << endl;
		return false;
	}
	vector[topIndex++] = vec;
	return true;
}

template <class T>
T& _Vector<T>::Pop()
{
	if (isEmpty())
	{
		cout << "vector가 비어있습니다." << endl;
		exit(1);
	}
	return vector[topIndex--];
}

