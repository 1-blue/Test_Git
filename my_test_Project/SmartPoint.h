#pragma once
#include <iostream>
#include "PointClass.h"

using namespace std;

template <class T>
class SmartPoint
{
	T* p;

public:
	SmartPoint(T* p);
	~SmartPoint();
	T& operator*();
	T* operator->();
};

