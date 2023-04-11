#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX_SIZE 100001
int heap[MAX_SIZE];
int heapSize = 0;

void heapInit(void) {
	heapSize = 0;
}

int heapPush(int value) {
	if (heapSize + 1 > MAX_SIZE) {
		printf("queue is Full!");
		return 0;
	}

	heap[heapSize] = value;
	
	int current = heapSize;
	
	while (current > 0 && heap[current] < heap[(current - 1) / 2]) {
		int tmp = heap[(current - 1) / 2];
		heap[(current - 1) / 2] = heap[current];
		heap[current] = tmp;
		current = (current - 1) / 2;
	}

	heapSize++;

	return 1;
}

int heapPop(int* value) {
	if (heapSize <= 0) {
		return -1;
	}

	*value = heap[0];
	heapSize--;

	heap[0] = heap[heapSize];  // 가장 마지막 노드를 루트로 가져온다.

	int current = 0;
	while (current * 2 + 1 < heapSize) {
		int child;
		if (current * 2 + 2 == heapSize) {
			child = current * 2 + 1;
		}
		else {
			child = heap[current * 2 + 1] < heap[current * 2 + 2] ? current * 2 + 1 : current * 2 + 2;
		} 	
		if (heap[current] < heap[child]) {
			break;
		}
		int temp = heap[current];
		heap[current] = heap[child];
		heap[child] = temp;
		current = child;
	}
	return 1;
}

int main(int argc, char* argv[]) {
	
	heapInit();

	int n; 

	scanf("%d", &n);
	for (int i = 0;i < n;i++) {
		int value;
		scanf(" %d", &value);
		heapPush(value);
	}

	long long int sum = 0;
	n--;
	while (n--) {
		int value1;
		if (heapPop(&value1) == -1) {
			break;
		}
		sum += (long long int)value1;

		int value2;
		heapPop(&value2);
		sum += (long long int)value2;
		
		heapPush(value1 + value2);
	}
	printf("%lld\n", sum);

	return 0;
}

