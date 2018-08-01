#include <stdio.h>
#include <conio.h>

#define MAX 10

int stack[MAX], topA = -1, topB = MAX;

void pushStackOne(int [],int value);
void pushStackTwo(int [],int value);
void popStackOne(int []);
void popStackTwo(int []);
void peekStackOne(int []);
void peekStackTwo(int []);
void displayStackOne(int []);
void displayStackTwo(int []);

void pushStackOne(int stack[],int value) {
	if(topA == (MAX-1) || topA == topB - 1 ) {
		printf("\nStack is full");
	} else {
		topA++;
		stack[topA] = value;
	}
	return;
}

void pushStackTwo(int stack[],int value) {
	if(topB == -1 || topB == topA + 1 ) {
		printf("\nStack is full");
	} else {
		topB--;
		stack[topB] = value;
	}
	return;
}

void popStackOne(int stack[]) {
	int temp ;
	if(topA == -1) {
		printf("\nStack is empty");
	} else {
		temp = stack[topA];
		topA--;
		printf("\nvalue deleted from stack is %d" , temp);
	}
	return;
}

void popStackTwo(int stack[]) {
	int temp ;
	if(topB == MAX) {
		printf("\nStack is empty");
	} else {
		temp = stack[topB];
		topB++;
		printf("\nvalue deleted from stack is %d" , temp);
	}
	return;
}

void peekStackOne(int stack[]) {
	if(topA == -1 ) {
		printf("\nStack is empty");
	} else {
		printf("\n Stack top is %d" , stack[topA]);
	}
}

void peekStackTwo(int stack[]) {
	if(topB == MAX ) {
		printf("\nStack is empty");
	} else {
		printf("\n Stack top is %d" , stack[topB]);
	}
}

void displayStackOne(int stack[]) {
	int index;
	if(topA == -1) {
		printf("\nStack in empty");
	}
	printf("\n");
	for(index = topA; index >= 0; index--) {
		printf("%d\t" , stack[index]);
	}
}

void displayStackTwo(int stack[]) {
	int index;
	if(topB == MAX) {
		printf("\nStack in empty");
	}
	printf("\n");
	for(index = topB; index < MAX; index++) {
		printf("%d\t" , stack[index]);
	}
}
void main() {
	int value,option;
	
	do {
		printf("\n**********MENU**********");
		printf("\n1.Push Stack A");
		printf("\n2.Pop Stack A");
		printf("\n3.Peek Stack A");
		printf("\n4.display Stack A");
		printf("\n5.Push Stack B");
		printf("\n6.Pop Stack B");
		printf("\n7.Peek Stack B");
		printf("\n8.display Stack B");
		printf("\n9.exit");
		printf("\nEnter your option ");
		scanf("%d" , &option);
		switch(option) {
			case 1: 
				printf("\nEnter the number to push ");
				scanf("%d" , &value);
				pushStackOne(stack,value);
			break;
			case 2:
				popStackOne(stack);
			break;
			case 3:
				peekStackOne(stack);
			break;
			case 4:
				displayStackOne(stack);
			break;
			case 5: 
				printf("\nEnter the number to push ");
				scanf("%d" , &value);
				pushStackTwo(stack,value);
			break;
			case 6:
				popStackTwo(stack);
			break;
			case 7:
				peekStackTwo(stack);
			break;
			case 8:
				displayStackTwo(stack);
			break;
		}
	} while(option != 9);
	return;
}
