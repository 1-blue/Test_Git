#pragma once
#include <iostream>
#include "Point.h"
#include "Point.cpp"

using namespace std;

template <class T>
class Template
{
	T* arr;
	int len;

public:
	Template(int len);
	~Template();
	int length();
	T& operator[](int idx);
};

