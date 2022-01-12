#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX_SIZE 1001
#define SWAP(x,y,t) ((t)=(x), (x)=(y), (y)=(t))
int minute[MAX_SIZE];
void insertionSort(int n)
{
	int i, j, key;
	for (i = 2;i <= n;i++) {
		key = minute[i];
		for (j = i - 1;j >= 0 && minute[j] > key;j--)
			minute[j + 1] = minute[j];
		minute[j + 1] = key;
	}
}

int minSum(int size) {
	int sum = 0;
	insertionSort(size);
	for (int i = 1;i <= size;i++) {
		sum = sum + minute[i];
		minute[i] = sum;
	}
	sum = 0;
	for (int i = 1;i <= size;i++) {
		sum = sum + minute[i];
	}
	return sum;
}
int main(void) {
	int size;
	scanf("%d", &size);
	for (int i = 1;i <= size;i++) {
		scanf("%d", &minute[i]);
	}
	printf("%d",minSum(size));
}
