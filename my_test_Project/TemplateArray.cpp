#include "TemplateArray.h"

template <class T>
TemplateArray<T>::TemplateArray(int length) : length(length)
{
	cout << "TemplateArray(int length)" << endl;
	array = new T[length + 1];
}

template<class T>
T& TemplateArray<T>::operator[](int idx)
{
	if (idx < 0 || idx >= length)
	{
		cout << "인덱스범위초과" << endl;
		exit(1);
	}

	return array[idx];
}

template<class T>
int TemplateArray<T>::Langth()
{
	return length;
}

template <class T>
void TemplateArray<T>::Show()
{
	for (int i = 0; i < length; i++)
	{
		cout << "array[" << i << "] : " << array[i] << endl;
	}
}

template <class T>
TemplateArray<T>::~TemplateArray()
{
	cout << "~TemplateArray()" << endl;
	delete[] array;
}