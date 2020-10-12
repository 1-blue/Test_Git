#pragma once
#include <iostream>

using namespace std;

template <class T>
class TemplateArray
{
	T* array;
	int length;

public:
	TemplateArray(int length);
	T& operator[](int idx);
	int Langth();
	void Show();
	~TemplateArray();
};