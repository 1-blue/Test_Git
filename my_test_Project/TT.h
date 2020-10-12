#pragma once
#include "PointClass.h"
#include "PointClass.cpp"

template <class T>
class TT
{
	T* arr;
	int len;

public:
	TT(int len);
	~TT();
	T& operator[](int idx);
	int length();
};