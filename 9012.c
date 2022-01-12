#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 50
typedef struct {
	char word[MAX_STACK_SIZE];
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
void push(Stack* s, char word) {
	if (isFull(s)) {
		fprintf(stderr, "스택 포화 에러\n");
		return;
	}
	
	s->word[++(s->top)] = word;
}
char pop(Stack* s) {
	if (isEmpty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	return s->word[(s->top)--];
}

int checkMatching(const char* word) {
	int len = strlen(word);
	char ch;
	Stack stack;
	initStack(&stack);
	
	for (int i = 0;i < len;i++) { // isEmpty를 이용
		ch = word[i];
		if (ch == '(') push(&stack, ch);
		else if (ch == ')' && stack.top >= 0)
			pop(&stack);
		else if (ch == ')' && stack.top < 0)
			push(&stack,ch);
			break;
	}

	if (isEmpty(&stack))
		return 1;
	else
		return 0;

}
int main(void) {
	
	int size; // 반복할 횟수
	char *word[50];
	
	scanf("%d", &size);
	
	for (int i = 0;i < size;i++) {
		scanf("%s", &word);
		int len = strlen(word);

		if (checkMatching(word) == 1) {
			printf("YES");
		}
		else if (len < 2) {
			i--;
			continue;
		}
		else
			printf("No");
		printf("\n");
		fgetc(stdin);
	}
	
}