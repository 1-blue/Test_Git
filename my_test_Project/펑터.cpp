#include <iostream>

using namespace std;

class Sort
{
public:
	virtual bool operator()(int x, int y) const = 0;
};

//펑터사용 오름차순
class Ascending : public Sort
{
public:
	bool operator()(int x, int y) const
	{
		if (x > y)
		{
			return true;
		}
		return false;
	}
};

//펑터사용 내림차순
class Descending : public Sort
{
public:
	bool operator()(int x, int y) const
	{
		if (x > y)
		{
			return false;
		}
		return true;
	}
};

class Array
{
	int* arr;
	int len;
	int idx;
public:
	Array(int len) :len(len), idx(0)
	{
		arr = new int[len];
	}
	void AddData(int var)
	{
		if (idx >= len)
		{
			cout << "인데스범위초과" << endl;
			exit(1);
		}
		arr[idx++] = var;
	}
	void Show() const
	{
		for (int i = 0; i < idx; i++) {
			cout << "arr[" << i << "] : " << arr[i] << endl;
		}
	}
	void Sort(const Sort& s) {
		int temp;
		for (int i = 0; i < len - 1; i++)
		{
			for (int j = 0; j < len - 1 - i; j++)
			{
				if (s(arr[j], arr[j + 1]))
				{
					temp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = temp;
				}
			}
		}
	}
	~Array()
	{
		delete[] arr;
	}
};



int main(void) {
	Array arr(10);

	for (int i = 0; i < 10; i++)
		arr.AddData(i);

	arr.Sort(Descending());

	arr.Show();

	return 0;
}