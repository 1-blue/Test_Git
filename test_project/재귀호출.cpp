//���ȣ��, ��ȯ(recursion)
#include <iostream>
#include <stdio.h>

using namespace std;

//���丮�� ��� ���α׷�(��ȯ)
int Factorial(int n)
{
	int num = 1;
	if (n <= 1)
		num = 1;
	else
		num = n * Factorial(n - 1);
	return num;
}

//���丮�� ��� ���α׷�(�ݺ�)
int Factorial_(int n)
{
	int result = 1;
	for (int i = 1; i <= n; i++)
		result *= i;
	return result;
}

//��ȯ�� ������ ������ �ذ��ϴ� ������������� ���
//���������̶� ������� ���� ������ ������ �����Ͽ� �ذ��ϴ°�

int main(void)
{
	//Factorial������α׷�
	int n = 5;
	cout << n << "! = " << Factorial(n) << endl;



	system("pause");
	return 0;
}