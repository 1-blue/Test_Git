#pragma once
#include <iostream>

using namespace std;

class EString
{
	char* str;
	int length;
public:
	EString();		//�⺻������
	EString(const char* str);		//�ٷ��ʱ�ȭ�Ҷ� ����� ������
	~EString();		//�Ҹ���... str��ȯ
	EString& operator=(EString& estr);
	EString operator+(const EString& estr);

	friend istream& operator>>(istream& is, EString& estr);
	friend ostream& operator<<(ostream& os, const EString& estr);

};

