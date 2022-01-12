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
		printf("���� ���� ����\n");
		return 1;
	}
	else
		return 0;
}
int isFull(Stack* s) {
	if (s->top == MAX_STACK_SIZE - 1) {
		printf("���� ��ȭ ����\n");
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
	int count = 0; // �������� ���е� ���ڿ��� �� ������ ����.
	Stack stack;
	initStack(&stack); // stack �ʱ�ȭ
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
		scanf("%[^\n]s", sentence); // enterŰ�� �ԷµǱ� ������ �Է¹޴´�.
		fgetc(stdin);
		printf("Case #%d:", num++);
		printReverse(sentence);
	}
}