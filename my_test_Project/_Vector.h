#pragma once
#include <iostream>
#include <string>
#include "Point.h"
#include "Point.cpp"

using namespace std;

template <class T>
class _Vector
{
	T* vector;
	int len;
	int topIndex;

public:
	_Vector();
	_Vector(int len);
	~_Vector();
	T& operator[](int idx);
	int length();
	bool isFull();
	bool isEmpty();
	bool Push(T vec);
	T& Pop();
	//T& operator*();
	//T* operator->();
	//friend ostream& operator<<(ostream& os, T t);

};

