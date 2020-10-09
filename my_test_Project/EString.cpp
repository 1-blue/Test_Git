#include "EString.h"

//기본생성자
EString::EString() :length(0)
{
	str = NULL;
}

EString::EString(const char* str) : length(strlen(str) + 1)
{
	cout << "EString(const char* str)" << endl;
	this->str = new char[length];
	strcpy_s(this->str, length, str);
}

EString::~EString()
{
	cout << "~EString()" << endl;
	if (!str)
		delete str;
}

EString& EString::operator=(EString& estr)
{
	cout << "operator=()" << endl;
	delete str;
	length = strlen(estr.str) + 1;
	str = new char[length];
	strcpy_s(str, length, estr.str);
	return *this;
}

EString EString::operator+(const EString& estr) {
	EString tempStr;
	tempStr.length = this->length + estr.length - 1;	//이미 +1씩한거라서
	tempStr.str = new char[tempStr.length];
	strcpy_s(tempStr.str, tempStr.length, this->str);
	strcat_s(tempStr.str, tempStr.length, estr.str);
	return tempStr;
}


ostream& operator<<(ostream& os, const EString& estr)
{
	os << estr.str;
	return os;
}

istream& operator>>(istream& is, EString& estr) {
	char buf[1024];
	is >> buf;
	estr.length = strlen(buf) + 1;
	estr.str = new char[estr.length];
	strcpy_s(estr.str, estr.length, buf);
	return is;
}
