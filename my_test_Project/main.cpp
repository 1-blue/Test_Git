#include "_Vector.h"
#include "_Vector.cpp"

int main(void)
{
	_Vector<string> vector(3);

	vector.Push("apple");
	vector.Push("blue");
	vector.Push("color");

	for (int i = 0; i < 3; i++)
		cout << vector[i] << endl;

	return 0;
}