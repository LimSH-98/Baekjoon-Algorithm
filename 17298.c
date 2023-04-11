#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>\


#define MAX_LEN 1000000

typedef struct Stack {
	int top; 
	int num[MAX_LEN];
}Stack;

Stack nge;

int num[MAX_LEN];
int arr[MAX_LEN];	

int pop() {
	return nge.num[nge.top--];
}

void push(int num) {
	nge.num[++nge.top] = num;
}

int empty() {
	if (nge.top == -1) {
		return 1;
	}
	else return 0;
}

int main() {
	int size, a = 0, first = 0, max;
	scanf(" %d", &size);

	nge.top = -1;

	for (int i = 0;i < size;i++) {
		int j = i;
		scanf(" %d", &num[i]);
			// 3 5 2 7 -> 5 7 7 -1
			// 9 5 4 8 -> -1 8 8 -1
	}	

	for (int i = size - 1;i >= 0;i--) {
		if (empty()) {
			push(num[i]); // stack nge¿¡ num[i]¸¦ »ðÀÔ.
			arr[i] = -1;
		}
		else {// 8 6 7 -> -1 7 -1 
			if (nge.num[nge.top] > num[i]) {
				arr[i] = nge.num[nge.top];
				push(num[i]);
			}
			else {
				while (!empty()) {
					pop();
					if (empty()) {
						push(num[i]);
						arr[i] = -1;
						break;
					}
					else {
						if (nge.num[nge.top] > num[i]) {
							arr[i] = nge.num[nge.top];
							push(num[i]);
							break;
						}
					}
				}
			}
		}
	}

	for (int i = 0;i < size;i++) {
		printf("%d ", arr[i]);
	}
}
