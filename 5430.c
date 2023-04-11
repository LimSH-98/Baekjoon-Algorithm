#define _CRT_SECURE_NO_WARNINGS
#define	MAX_SIZE 100 // �׽�Ʈ ���̽� �ִ� ����
#define MAX_LEN 100000 // ������ �Լ� �ִ� ����
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
	�˰��� ���: ����ڿ��� �Է¹޴� [1,2,3,4] �� ���ڿ����� ó���ϴ� ���� ���� �߿��ѵ�, 
	scanf("%c", ~)�� [ �� ������ ���� c�� �Է¹��� ��, ������ 
	for���� ������ ������ŭ �����µ�, �߰��� ,�� ] �� ���� �����Ƿ� scanf�� ������ temp��� int �� ������ �Է¹��� ����,
	���� �ٿ� getchar()�� �����ν� ,�� ]�� ���� �� �ֵ��� �Ѵ�.

	�׸��� R�� ������ �Լ��� �� �� ����ִ����� ���� ��, �ڿ� �ִ� �������� D�� ���� ������ �� �ֱ� ������ R�� ������ �� �� �ֵ����ϴ�
	���� ���� int swap = 0; ���� ������ ���´�.

	�׸��� D�� ���, R % 2 == 0�̸� deque�� ���ʿ� �����ϰ� 1�̸� ���ʿ� �����ϵ��� �ۼ�.

	�׷� ��, �迭�� ������� �ϹǷ� �̰͵� ���������� swap % 2 == 0 �̸� dequq�� ���ʺ���, 1 �̸� deque�� ���ʺ��� printf �ϵ��� �ۼ��Ѵ�.
*/

int T, N;
int swap = 0; // R count, R % 2 == 1�̸� �迭 �ڹٲ� ����, R % 2 == 0�̸� �迭 �״���� ����.
int r = 0;
int temp;
char cmd[MAX_LEN];
char c; // ���ڵ��� �ܼ��� ������ ����


typedef struct {
	int max;
	int size;
	int front;
	int rear;
	int* que;
}Deck;

void deckInit(Deck* deck) {
	deck->front = deck->rear = deck->size = 0;
	
	if ((deck->que = calloc(MAX_LEN, sizeof(int))) == NULL) { // calloc�� �Ҵ�� ������ ���� ��� 0���� �ٲ۴�.
		deck->max = 0;
		return -1;
	}
	deck->max = MAX_LEN;
	return 0;
}

int dequeFront(Deck* deck, int* num) {
	if (deck->size <= 0) {
		return -1;
	}
	deck->size--;
	*num = deck->que[deck->front++];
	deck->front = deck->front % deck->max;
	return 0;
}

int dequeRear(Deck* deck, int* num) {
	if (deck->size <= 0)
		return -1;

	deck->size--;
	if (--deck->rear < 0) {
		deck->rear = deck->max - 1;
	}

	*num = deck->que[deck->rear];
	return 0;
}

int enqueRear(Deck* deck, int num) {
	if (deck->size >= deck->max) {
		return -1;
	}
	deck->size++;
	deck->que[deck->rear++] = num;
	deck->rear = deck->rear % deck->max;
	return 0;
}

void printFront(Deck* deck) {
	printf("[");
	for (int i = 0; i < deck->size; i++) {
		printf("%d", deck->que[(i + deck->front) % deck->max]);
		if (i != deck->size - 1) {
			printf(",");
		}
	}
	printf("]\n");
}

void printRear(Deck* deck) {
	
	int temp;

	printf("[");
	for (int i = 0;i < deck->size;i++) {
		if ((temp = deck->rear - 1 - i) < 0)
			temp = deck->max - 1;

		printf("%d", deck->que[temp]);
		if (i != deck->size - 1) {
			printf(",");
		}
	}
	printf("]\n");
}

int main() {
	Deck deck;

	scanf(" %d", &T);

	while (T--) {

		deckInit(&deck);

		swap = 0;
		r = 0;

		scanf(" %s", cmd);
		scanf(" %d", &N);
		getchar();
		
		if (N != 0) {
			scanf("%c", &c); // [ ����
			for (int i = 0;i < N;i++) {
				scanf("%d", &temp); // ���� temp�� �Է�
				getchar(); // ,�� ] �� ����.
				enqueRear(&deck, temp); // temp�� deck�� ����.
			}
		}
		else { // �Է��� ���� ��
			scanf("%c %c", &c, &c);
		}

		for (int i = 0;;i++) {
			if (cmd[i] == 'R') {
				swap++;
			}
			else if (cmd[i] == 'D') {
				r = ((swap % 2 == 0) ? dequeFront(&deck, &temp) : dequeRear(&deck, &temp));
			}
			else if (cmd[i] == '\0')
				break;
		}
		
		if (r == -1) {
			printf("error\n");
		}
		else
			(swap % 2 == 0) ? printFront(&deck) : printRear(&deck);
	}
}