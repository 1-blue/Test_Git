#include <iostream>
#include <Windows.h>

using namespace std;

void WriteData(string tempSection, string tempKey, string tempValue, string tempPath)
{
	auto section = tempSection.c_str();
	auto key = tempKey.c_str();
	auto value = tempValue.c_str();
	auto path = tempPath.c_str();
	WritePrivateProfileString(section, key, value, path);
}

int main(void)
{
	WriteData("player1", "hp", "5", "gameInfo\\player33.ini");
	WriteData("player1", "power", "3", "gameInfo\\player33.ini");




	return 0;
}