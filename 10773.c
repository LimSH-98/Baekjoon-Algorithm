#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX_SIZE 100000
int top;
int money[MAX_SIZE];
void init(int size) {
	for (int i = 0;i < size;i++) {
		money[i] = 0;
	}
	top = -1;
}
int pop() {
	if (top == -1) {
		printf("is Empty\n");
		return;
	}
	return money[top--];
}
void push(int m) {
	if (top == MAX_SIZE) {
		printf("is Full\n");
		return;
	}
	money[++top] = m;
}
int main(void) {

	int size;
	scanf("%d", &size);
	fgetc(stdin);

	init(size);

	for (int i = 0;i < size;i++) {
		int num;
		scanf("%d", &num);
		if (num == 0) {
			pop();
		}
		else {
			push(num);
		}
	}
	int sum = 0;
	while (top != -1) {
		sum += pop();
	}

	printf("%d\n", sum);
}