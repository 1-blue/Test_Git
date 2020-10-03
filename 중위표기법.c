#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100
typedef int Element;

Element data[MAX_STACK_SIZE];
int top = 0;

void init_stack() {
	top = -1;
}

int is_empty() {
	return -1 == top;
}

int is_full() {
	return (MAX_STACK_SIZE - 1) == top;
}

void push(Element e) {
	if (is_full()) {
		printf("스택포화에러로인한 강제종료");
		exit(0);
	}
	data[++top] = e;
}

Element pop() {
	if (!is_empty())
		return data[top--];
	else {
		printf("스택이 비었는데 지우려고해서 강제종료");
		exit(0);
	}
}

int Calc_postfix(char* str) {
	int first;
	int second;
	int temp = -1;

	init_stack();
	for (int i = 0; i < strlen(str); i++) {
		//숫자인지 연산자인지 구분하는 switch~case문
		switch (str[i]) {
		case '+':
		case '-':
		case '*':
		case '/':
			second = pop();
			first = pop();

			//계산하는 switch~case문
			switch (str[i]) {
			case '*':
				temp = first * second;
				break;

			case '-':
				temp = first - second;
				break;

			case '/':
				temp = first / second;
				break;

			case '+':
				temp = first + second;
				break;
			}

			push(temp);
			break;

		default:	//연산자를 제외한 모두 숫자라고 가정하고 사용
			push(str[i] - 48);	//아스키코드 '0' = 48
			
		}
	}
	return pop();
}

//82/3-32*+ == 7

int main(void) {

	int x = Calc_postfix("82/3-32*+");

	printf("%d", x);


	return 0;
}