#pragma once
#include <iostream>

using namespace std;

class EString
{
	char* str;
	int length;
public:
	EString();		//기본생성자
	EString(const char* str);		//바로초기화할때 사용할 생성자
	~EString();		//소멸자... str반환
	EString& operator=(EString& estr);
	EString operator+(const EString& estr);

	friend istream& operator>>(istream& is, EString& estr);
	friend ostream& operator<<(ostream& os, const EString& estr);

};

