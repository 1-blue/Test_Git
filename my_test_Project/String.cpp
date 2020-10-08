#include "String.h"

String::String():len(0), str(NULL){}

String::String(const char* str) : len(strlen(str))
{
	cout << "String(char* str)" << endl;
	this->str = new char[len + 1];
	strcpy_s(this->str, len + 1, str);
}

String::~String()
{
	cout << "~String()" << endl;
	delete[] str;
}

String::String(const String& ss):len(ss.len)		//복사생성자
{
	cout << "String(const String& ss)" << endl;
	str = new char[len + 1];
	strcpy_s(str, len + 1, ss.str);
}

String String::operator=(const String& ss)
{
	delete str;
	len = strlen(ss.str);
	str = new char[len + 1];
	strcpy_s(str, len + 1, ss.str);

	return *this;
}

String String::operator+(const String& ss)
{
	char* tempStr = new char[len + 1];
	strcpy_s(tempStr, len + 1, str);
	strcat_s(tempStr, len + ss.len + 1, ss.str);

	return String(tempStr);
}

void String::operator+=(const String& ss)
{
	char* tempStr = new char[len + 1];
	int tempLen = len;
	len = len + ss.len;
	strcpy_s(tempStr, len + 1, str);
	delete str;
	str = new char[len + 1];
	strcpy_s(str, tempLen + 1, tempStr);
	strcat_s(str, len + 1, ss.str);
}

bool String::operator==(const String& ss)
{
	if (0 == strcmp(str, ss.str))
		return true;
	return false;
}

ostream& operator<<(ostream& os, const String& ss)
{
	os << ss.str;
	return os;
}

istream& operator>>(istream& is, String& ss)
{
	//여기서 조건검사해서 입력문자열이 원래문자열과같으면 아무작업안하게 만드는것이 더효율적인지?
	delete ss.str;
	char* tempStr = new char[1024];
	is >> tempStr;
	ss.len = strlen(tempStr);
	ss.str = new char[ss.len + 1];
	strcpy_s(ss.str, ss.len + 1, tempStr);
	
	return is;
}