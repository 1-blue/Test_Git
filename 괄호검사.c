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
		printf("스택포화");
		exit(0);
	}
	data[++top] = e;
}

Element pop() {
	if (!is_empty())
		return data[top--];
}

int check_matching(char* str) {
	int i = 0;
	int temp;
	char ch;
	init_stack();
	while (str[i] != '\0') {
		ch = str[i++];
		switch (ch) {
		case '[':
		case '{':
		case '(':
			push(ch);
			break;
		case ']':
		case '}':
		case ')':
			if (is_empty())		//2번위반
				return 2;
			temp = pop();

			//3번위반
			if ((ch == ']' && temp != '[') || (ch == '}' && temp != '{') || (ch == ')' && temp != '('))
				return 3;
		}
	}
	//1번위반
	if (is_empty() == 0)
		return 1;

	//정상
	return 0;
}


int main(void) {

	int errCode;

	errCode = check_matching("{([1321])}");

	printf("%d", errCode);





	return 0;
}