#pragma once
#include <iostream>
#include "PointClass.h"

using namespace std;

template <class T>
class TemplateClass
{
	T* array;
	int length;

public:
	TemplateClass(int length);
	~TemplateClass();
	T& operator[](int idx);
	int Length();

};