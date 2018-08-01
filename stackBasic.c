#include <stdio.h>
#include <conio.h>

#define MAX 10

int stack[MAX], top = -1;

void push(int [],int value);
void pop(int []);
void peek(int []);
void display(int []);

void push(int stack[],int value) {
	if(top == (MAX-1)) {
		printf("\nStack is full");
	} else {
		top++;
		stack[top] = value;
	}
	return;
}

void pop(int stack[]) {
	int temp ;
	if(top == -1) {
		printf("\nStack is empty");
	} else {
		temp = stack[top];
		top--;
		printf("\nvalue deleted from stack is %d" , temp);
	}
	return;
}

void peek(int stack[]) {
	if(top == -1 ) {
		printf("\nStack is empty");
	} else {
		printf("\n Stack top is %d" , stack[top]);
	}
}

void display(int stack[]) {
	int index;
	if(top == -1) {
		printf("\nStack in empty");
	}
	printf("\n");
	for(index = top; index >= 0; index--) {
		printf("%d\t" , stack[index]);
	}
}
void main() {
	int value,option;
	
	do {
		printf("\n**********MENU**********");
		printf("\n1.Push");
		printf("\n2.Pop");
		printf("\n3.Peek");
		printf("\n4.display");
		printf("\n5.exit");
		printf("\nEnter your option ");
		scanf("%d" , &option);
		switch(option) {
			case 1: 
				printf("\nEnter the number to push ");
				scanf("%d" , &value);
				push(stack,value);
			break;
			case 2:
				pop(stack);
			break;
			case 3:
				peek(stack);
			break;
			case 4:
				display(stack);
			break;
		}
	} while(option != 5);
	return;
}
