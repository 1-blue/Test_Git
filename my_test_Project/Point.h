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

//바운드템플릿프렌드.. 클래스템플릿이 지정되면 그에맞게 프랜드템플릿함수도 결정
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

//언바운드템플릿프렌드.. 모든클래스템플릿에대한 각각의 프렌드템플릿함수 지정됨
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