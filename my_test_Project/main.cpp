#include <string>
#include <Windows.h>
#include <map>

using namespace std;

void ReadFileString(const char* section, const char* key, map<string, string>& test, const char* path)
{
	TCHAR loadData[1024];
	GetPrivateProfileString(section, key, "", loadData, 1024, path);
	test[key] = loadData;
	setlocale(LC_ALL, "ko_KR.UTF8");
	cout << loadData << endl;
	setlocale(LC_ALL, "");
}

int main(void)
{
	map <string, string> title;
	map <string, string> select;

	ReadFileString("title", "0", title, "GameInfo\\GameStartUI.ini");
	ReadFileString("title", "1", title, "GameInfo\\GameStartUI.ini");
	ReadFileString("title", "2", title, "GameInfo\\GameStartUI.ini");
	ReadFileString("title", "3", title, "GameInfo\\GameStartUI.ini");
	ReadFileString("title", "4", title, "GameInfo\\GameStartUI.ini");

	ReadFileString("select", "0", select, "GameInfo\\GameStartUI.ini");
	ReadFileString("select", "1", select, "GameInfo\\GameStartUI.ini");
	ReadFileString("select", "2", select, "GameInfo\\GameStartUI.ini");

	//string s;
	//for (int i = 0; i < title.size(); i++)
	//{
	//	string s = to_string(i);
	//	cout << title[s] << endl;
	//}

	//for (int i = 0; i < select.size(); i++)
	//{
	//	string s = to_string(i);
	//	cout << select[s] << endl;
	//}
	string str;
	cin.get(str, 10, 'i');

	cout << "ÇÑ±Û" << endl;


	return 0;
}