#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX_SIZE 500000 
int card[MAX_SIZE];
int num[MAX_SIZE];
#define SWAP(x, y, t) ( (t)=(x), (x)=(y), (y)=(t) )
int partition(int left, int right)
{
	int pivot, temp;
	int low, high;

	low = left;
	high = right + 1;
	pivot = card[left]; 	/* �ǹ� ���� */
	do {
		do
			low++;
		/* ���� ����Ʈ���� �ǹ����� ū ���ڵ� ���� */
		while (low <= right && card[low] < pivot);
		do
			high--;
		/* ������ ����Ʈ���� �ǹ����� ���� ���ڵ� ���� */
		while (high >= left && card[high] > pivot);
		if (low < high) SWAP(card[low], card[high], temp); /* ���õ� �� ���ڵ� ��ȯ */
	} while (low < high);	  /* �ε��� i,j�� �������� �ʴ� �� �ݺ� */

	SWAP(card[left], card[high], temp); /* ���ؽ� j�� ����Ű�� ���ڵ�� �ǹ� ��ȯ */
	return high;
}

//
void quickSort(int left, int right)
{
	if (left < right) {     /* ����Ʈ�� 2�� �̻��� ���ڵ尡 ���� ��� */
		int q = partition(left, right);
		//print(list, 9);
		quickSort(left, q - 1);         /* ���� �κи���Ʈ�� ������ */
		quickSort(q + 1, right);       /* ������ �κи���Ʈ�� ������ */
	}
}
int binSearch(int low, int high, int key) {
	int middle;
	if (low <= high) {
		middle = (low + high) / 2;
		if (key == card[middle]) return 1;
		else if (key < card[middle]) {
			return binSearch(low, middle - 1, key);
		}
		else {
			return binSearch(middle + 1, high, key);
		}
	}
	return 0;
}
int main(void) {
	int size, n;
	scanf("%d", &size);
	fgetc(stdin);
	for (int i = 0;i < size;i++) {
		scanf("%d", &card[i]);
	}
	fgetc(stdin);
	scanf("%d", &n);
	for (int i = 0;i < n;i++) {
		scanf("%d", &num[i]);
	}
	quickSort(0, size - 1);

	for (int i = 0;i < n;i++) { 
		printf("%d ",binSearch(0, size-1,num[i])); 
	}
}