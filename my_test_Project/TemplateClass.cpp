#include "TemplateClass.h"

template <class T>
TemplateClass<T>::TemplateClass(int length) : length(length)
{
	cout << "TemplateClass(int length)" << endl;
	array = new T[length];
}

template <class T>
TemplateClass<T>::~TemplateClass()
{
	delete[] array;
}

template <class T>
T& TemplateClass<T>::operator[](int idx)
{
	if(idx < 0 || idx >= length)
	{
		cout << "인덱스범위초과" << endl;
		exit(1);
	}

	return array[idx];
}

template <class T>
int TemplateClass<T>::Length()
{
	return length;
}

