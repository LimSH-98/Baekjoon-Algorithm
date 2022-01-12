#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define MAX_STACK_SIZE 100000
typedef struct {
	char word[MAX_STACK_SIZE];
	int top;
}Stack;
void initStack(Stack* s) {
	s->top = -1;
}
int isEmpty(Stack* s) {
	if (s->top == -1)
		return 1;
	else
		return 0;
}
int isFull(Stack* s){
	if (s->top == MAX_STACK_SIZE)
		return 1;
	else
		return 0;
}
void push(Stack* s, char word) {
	if (isFull(s))
		return;
	else
		s->word[++(s->top)] = word;
}
char pop(Stack* s) {
	if (isEmpty(s))
		return;
	else return s->word[(s->top)--];
}
char peek(Stack* s) {
	if (isEmpty(s)) return;
	else return s->word[s->top];
}
int goodWord(const char* w) {
	Stack stack;
	int len = strlen(w);
	initStack(&stack);
	for (int i = 0;i < len;i++) {
		if (!isEmpty(&stack)) {
			if (peek(&stack) == w[i]) {
				pop(&stack);
			}
			else
				push(&stack, w[i]);
		}
		else
			push(&stack, w[i]);
	}
	if (isEmpty(&stack))
		return 1;
	else
		return 0;
}
int main(void) {
	int num,count = 0;
	char word[MAX_STACK_SIZE];
	scanf("%d", &num);
	fgetc(stdin);
	for (int i = 0;i < num;i++) {
		scanf("%s", word);
		fgetc(stdin);
		if(goodWord(word) == 1) count++;
	}
	printf("%d",count);
	return 0;
}