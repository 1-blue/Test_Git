#include <iostream>
#include <map>
#include <fstream>
#include <string>

using namespace std;

int main(void)
{
	ifstream fcin;
	map<string, string*> dic;
	string s[20];
	string key;
	int idx = 0;
	char ch;

	while (true)
	{
		system("cls");
		cout << "숫자입력해줘" << endl;
		ch = cin.get();
		cout << ch << endl;
		switch (ch)
		{
		case 'a':
			fcin.open("test\\txt1.txt");
			getline(fcin, key);

			while (!fcin.eof())
				getline(fcin, s[idx++]);

			fcin.close();

			dic[key] = s;
			cout << idx << endl;
			for (int i = 0; i < idx; i++) {
				cout << (dic[key])[i] << endl;
			}

			cin.get();
			cin.get();

			idx = 0;
			break;

		case 's':
			fcin.open("test\\txt2.txt");
			getline(fcin, key);

			while (!fcin.eof())
				getline(fcin, s[idx++]);

			fcin.close();

			dic[key] = s;
			for (int i = 0; i < idx; i++) {
				cout << (dic[key])[i] << endl;
			}

			cin.get();
			cin.get();

			idx = 0;
			break;

		case 'd':
			fcin.open("test\\txt3.txt");
			getline(fcin, key);

			while (!fcin.eof())
				getline(fcin, s[idx++]);


			fcin.close();

			dic[key] = s;
			for (int i = 0; i < idx; i++) {
				cout << (dic[key])[i] << endl;
			}

			cin.get();
			cin.get();

			idx = 0;
			break;

		case 'f':
			cout << "종료" << endl;
			exit(0);
		}
	}




	return 0;
}