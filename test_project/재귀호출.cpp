//재귀호출, 순환(recursion)
#include <iostream>
#include <stdio.h>

using namespace std;

//팩토리얼 계산 프로그램(순환)
int Factorial(int n)
{
	int num = 1;
	if (n <= 1)
		num = 1;
	else
		num = n * Factorial(n - 1);
	return num;
}

//팩토리얼 계산 프로그램(반복)
int Factorial_(int n)
{
	int result = 1;
	for (int i = 1; i <= n; i++)
		result *= i;
	return result;
}

//순환은 문제를 나누어 해결하는 분할정복방법을 사용
//분할정복이란 어떤문제를 작은 동일한 문제로 분해하여 해결하는것

int main(void)
{
	//Factorial계산프로그램
	int n = 5;
	cout << n << "! = " << Factorial(n) << endl;



	system("pause");
	return 0;
}