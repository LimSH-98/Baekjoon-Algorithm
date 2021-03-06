#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 25
typedef struct {
	char *word[MAX_STACK_SIZE];
	int top;
}Stack;

void initStack(Stack* s) {
	s->top = -1;
}
int isEmpty(Stack* s) {
	if (s->top == -1) {
		printf("스택 공백 에러\n");
		return 1;
	}
	else
		return 0;
}
int isFull(Stack* s) {
	if (s->top == MAX_STACK_SIZE - 1) {
		printf("스택 포화 에러\n");
		return 1;
	}
	else
		return 0;
}
void push(Stack* s, char* word) {
	if (isFull(s)) {
		return;
	}
	else s->word[++(s->top)] = word;
}
char* pop(Stack* s) {
	if (isEmpty(s))
		return;
	else return s->word[(s->top)--];
}
void printReverse(const char* sentence) {
	int count = 0; // 공백으로 구분된 문자열이 몇 개인지 센다.
	Stack stack;
	initStack(&stack); // stack 초기화
	char* ptr = strtok(sentence, " ");

	while (ptr != NULL) {
		push(&stack, ptr);
		ptr = strtok(NULL, " ");
		push(&stack, " ");
	}
	count = stack.top;

	for(int i=0;i<=count;i++){
		printf("%s", pop(&stack));
	}
	printf("\n");
}
int main(void) {
	int size,num = 1;
	char sentence[25];
	scanf("%d", &size);
	fgetc(stdin);
	for (int i = 0;i < size;i++) {
		scanf("%[^\n]s", sentence); // enter키가 입력되기 전까지 입력받는다.
		fgetc(stdin);
		printf("Case #%d:", num++);
		printReverse(sentence);
	}
}