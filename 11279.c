#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_HEAP_SIZE 100000
typedef struct {
	int heap[MAX_HEAP_SIZE];
	int heapSize;
}HeapType;

HeapType* create() {
	return (HeapType*)malloc(sizeof(HeapType));
}

void init(HeapType* h) {
	h->heapSize = 0;
}
int isEmpty(HeapType* h) {
	if (h->heapSize == 0)
		return 1;
	else return 0;
}
void insertMaxHeap(HeapType* h, int num) {
	int i = ++(h->heapSize);
	while ((i != 1) && num > (h->heap[i / 2])) {
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = num;
}

int deleteMaxHeap(HeapType* h) {

	int parent = 1, child = 2;
	int data = h->heap[1], temp = h->heap[(h->heapSize)--];

	while (child <= h->heapSize) {
		if ((child < h->heapSize) && (h->heap[child] < h->heap[child + 1])) {
			child++;
		}
		if (temp >= h->heap[child]) break;

		h->heap[parent] = h->heap[child];
		parent = child;
		child = child * 2;
	}
	h->heap[parent] = temp;
	return data;
}

int main() {
	int num, size;

	HeapType* h;
	h = create();
	init(h);

	scanf("%d", &size);
	fgetc(stdin);
	if (size >= 1 && size <= 100000) {
		for (int i = 0;i < size;i++) {
			scanf("%d", &num);
			if (num == 0) {
				if (isEmpty(h))
					printf("0\n");
				else
					printf("%d\n", deleteMaxHeap(h));
			}
			else {
				insertMaxHeap(h, num);
			}
		}
	}

	return 0;
}
