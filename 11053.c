#define _CRT_SECURE_NO_WARNINGS
#define MAX_SIZE 1000
#include <stdio.h>

int arr[MAX_SIZE];
int length[MAX_SIZE];
int max(int a, int b);

int max(int a, int b) {
	if (a > b) {
		return a;
	}
	else return b;
}

int main() {
	int size, len, tmp = 0;
	scanf("%d ", &size);

	for (int i = 0;i < size;i++) {
		scanf("%d", &arr[i]);
	}
	
	length[0] = 1;

	for (int i = 1;i < size;i++) {
		length[i] = 1;
		for (int j = 0;j < i;j++) {
			if (arr[i] > arr[j]) {
				length[i] = max(length[i], length[j] + 1);
			}
		}
	}

	int max = 0;

	for (int i = 0;i < size;i++) {
		if (length[i] > max) {
			max = length[i];
		}
	}
	printf("%d\n", max);
}