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
	pivot = card[left]; 	/* 피벗 설정 */
	do {
		do
			low++;
		/* 왼쪽 리스트에서 피벗보다 큰 레코드 선택 */
		while (low <= right && card[low] < pivot);
		do
			high--;
		/* 오른쪽 리스트에서 피벗보다 작은 레코드 선택 */
		while (high >= left && card[high] > pivot);
		if (low < high) SWAP(card[low], card[high], temp); /* 선택된 두 레코드 교환 */
	} while (low < high);	  /* 인덱스 i,j가 엇갈리지 않는 한 반복 */

	SWAP(card[left], card[high], temp); /* 인텍스 j가 가리키는 레코드와 피벗 교환 */
	return high;
}

//
void quickSort(int left, int right)
{
	if (left < right) {     /* 리스트에 2개 이상의 레코드가 있을 경우 */
		int q = partition(left, right);
		//print(list, 9);
		quickSort(left, q - 1);         /* 왼쪽 부분리스트를 퀵정렬 */
		quickSort(q + 1, right);       /* 오른쪽 부분리스트를 퀵정렬 */
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