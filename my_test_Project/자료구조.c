#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 101
typedef int Element;

Element stack[MAX_STACK_SIZE];
int top;

void error(const char* str)
{
	printf("%s", str);
	exit(1);
}

void init()
{
	top = -1;
}

int size()
{
	return top + 1;
}

int is_pull()
{
	return (top == MAX_STACK_SIZE) ? 1 : 0;
}

int is_empty()
{
	return (top == -1) ? 1 : 0;
}

void push(int value)
{
	if (is_pull())
		error("������ ����á���ϴ�.");

	stack[++top] = value;
}

Element pop()
{
	if (is_empty())
		error("������ ����ֽ��ϴ�.");

	return stack[top--];
}

Element peek()
{
	if (is_empty())
		error("������ ����ֽ��ϴ�.");

	return stack[top];
}

void Print(const char* str)
{
	printf("%s : ", str);
	for (int i = 0; i < size(); i++) {
		printf(" %d ", stack[i]);
	}
	printf("\n");
}

//��ȣ�˻�
int check_matching(char expr[])
{
	init();
	int i = 0;
	char ch;
	char temp;

	while (expr[i] != '\0')
	{
		ch = expr[i++];

		if (ch == '(' || ch == '[' || ch == '{')
			push(ch);
		else if (ch == ')' || ch == ']' || ch == '}')
		{
			if (is_empty())
				return 2;

			temp = pop();
			if ((ch == ')' && temp != '(') || (ch == ']' && temp != '[') || (ch == '}' && temp != '{'))
				return 3;
		}
	}

	if (!is_empty())
		return 1;
	return 0;
}
void Print_check_matching()
{
	char c[] = "([{�ƴ�}])";
	int errCode;
	errCode = check_matching(c);

	if (errCode == 0)
		printf("����");
	else
		printf("%d�� ����", errCode);
}

//����ǥ��� ���
double calc_postfix(char expr[])
{
	init();
	int i = 0;
	char ch;
	int var1, var2;

	while (expr[i] != '\0')
	{
		ch = expr[i++];

		if (ch >= '0' && ch <= '9')
		{
			ch -= '0';
			push(ch);
		}
		else if (ch == '+' || ch == '-' || ch == '/' || ch == '*')
		{
			var2 = pop();
			var1 = pop();
			switch (ch)
			{
			case '-':
				push(var1 - var2);
				break;

			case '+':
				push(var1 + var2);
				break;

			case '/':
				push(var1 / var2);
				break;

			case '*':
				push(var1 * var2);
				break;

			}
		}
	}

	return pop();
}
void Print_calc_postfix()
{
	char expr[] = "82/3-32*+";
	double var = calc_postfix(expr);
	printf("���� : %s = ", expr);
	printf("%.1lf\n", var);
}

//����ǥ��� -> ����ǥ���
int precedence(char op)
{
	switch (op)
	{
	case '(':
	case ')':
		return 0;
	case '+':
	case '-':
		return 1;
	case '*':
	case '/':
		return 2;
	default:
		return -1;
	}
}
void infix_to_postfix(char expr[])
{
	int i = 0;
	char ch;
	char temp;

	while (expr[i] != '\0')
	{
		ch = expr[i++];

		if (ch >= '0' && ch <= '9')
		{
			printf("%d", ch - '0');
		}
		//��ȣ�����߰�
		else if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
		{
			while (is_empty() == 0)
			{
				temp = peek();
				if (precedence(ch) <= precedence(temp))
				{
					printf("%c", pop());
				}
				else
					break;
			}
			push(ch);
		}
	}

	while (is_empty() == 0)
		printf("%c", pop());
}
void Print_infix_to_postfix()
{
	char expr[] = "8/2-3+3*2";
	infix_to_postfix(expr);
}

int main(void)
{



	return 0;
}