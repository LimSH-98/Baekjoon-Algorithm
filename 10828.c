#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define MAX_STACK_SIZE 10000

typedef struct {
	int num[MAX_STACK_SIZE];
	int top;
}Stack;

void initStack(Stack* s) {
	s->top = -1;
}
int isEmpty(Stack* s) {
	return (s->top == -1);
}
int isFull(Stack* s) {
	return (s->top == MAX_STACK_SIZE - 1);
}
void push(Stack* s,int n) {
	if (isFull(s)) {
		return;
	}
	else s->num[++(s->top)] = n; 
}
int pop(Stack* s) {
	if (isEmpty(s)) {
		return -1;
	}
	else  return s->num[(s->top)--];
}
int Size(Stack* s) {
	return s->top + 1;
}

int peek(Stack* s) {
	if (isEmpty(s)) return - 1;
	return s->num[s->top];
}
int main(void) {
	Stack s;
	int size,data;
	char command[6];
	scanf("%d", &size);
	initStack(&s);

	for (int i = 0;i < size;i++) {
		scanf("%s", command);
		fgetc(stdin);
		if (!strcmp(command, "push")) {
			scanf("%d", &data);
			fgetc(stdin);
			push(&s, data);
		}
		else if (!strcmp(command, "pop")) {
			printf("%d\n", pop(&s));		
		}
		else if (!strcmp(command, "size")) {
			printf("%d\n", Size(&s));
		}
		else if (!strcmp(command, "empty")) {
			printf("%d\n", isEmpty(&s));
		}
		else if (!strcmp(command, "top")) {
			printf("%d\n", peek(&s));
		}
	}
}
