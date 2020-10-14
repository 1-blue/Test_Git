#pragma once
#include <iostream>

using namespace std;

template <class T>
class Point
{
	T x, y;

public:
	Point();
	Point(int x, int y);
	~Point();
	friend ostream& operator<< <>(ostream& os, const Point<T>& p);
};

//�ٿ�����ø�������.. Ŭ�������ø��� �����Ǹ� �׿��°� ���������ø��Լ��� ����
/*
template <class T> void Show(T&);

template <class TT>
class Test
{
	TT x;

public:
	Test(TT x) : x(x) {};
	friend void Show <>(Test<TT>& t);
};

template <class TT>
void Show(Test<TT>& t)
{
	cout << t.x << endl;
}
*/

//��ٿ�����ø�������.. ���Ŭ�������ø������� ������ ���������ø��Լ� ������
/*
template <class TT>
class Test
{
	TT x;

public:
	Test(TT x) : x(x) {};
	template <class T>
	friend ostream& operator<<(ostream& os, const T& p);
};

template <class T>
ostream& operator<<(ostream& os, const T& p)
{
	os << p.x;
	return os;
}
*/