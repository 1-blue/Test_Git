#pragma once

#include <iostream>

using namespace std;

class String
{
	char* str;
	int len;

public:
	String();
	String(const char* str);
	String(const String& ss);
	~String();
	String operator=(const String& ss);
	String operator+(const String& ss);
	void operator+=(const String& ss);
	bool operator==(const String& ss);
	friend ostream& operator<<(ostream& os, const String& ss);
	friend istream& operator>>(istream& is, String& ss);

};

