#include <stdio.h>
#include <conio.h>
#include<string.h>

#define MAX 10

int stack[MAX], top = -1;

void push(char );
char pop();

void push(char value) {
	if(top == (MAX-1)) {
		printf("\nStack is full");
	} else {
		top++;
		stack[top] = value;
	}
	return;
}

char pop() {
	if(top == -1) {
		printf("\nStack is empty");
	} else {
		return stack[top--];
	}
}

void main() {
	char equation[MAX],temp;
	int index,flag = 1;
	
	printf("\nEnter the expression : ");
	gets(equation);
	
	for(index = 0; index < strlen(equation); index++) {
		if(equation[index] == '(' || equation[index] == '{' || equation[index] == '[') {
			push(equation[index]);
		}
		if(equation[index] == ')' || equation[index] == '}'|| equation[index] == ']') {
			if(top == -1) {
				flag = 0;
			} else {
				temp = pop();
				if(equation[index] == '}' && (temp == '[' || temp == '('))
					flag = 0;
				if(equation[index] == ']' && (temp == '{' || temp == '('))
					flag = 0;
				if(equation[index] == ')' && (temp == '[' || temp == '{'))
					flag = 0;
			}
		}
	}
	if(top >= 0) {
		flag = 0;
	}
	if(flag == 1) {
		printf("\nExpression is valid");
	} else {
		printf("\nExpression is invalid");	
	}
}
