#define _CRT_SECURE_NO_WARNINGS
#define	MAX_SIZE 100 // 테스트 케이스 최대 개수
#define MAX_LEN 100000 // 수행할 함수 최대 길이
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
	알고리즘 요약: 사용자에게 입력받는 [1,2,3,4] 이 문자열들을 처리하는 것이 가장 중요한데, 
	scanf("%c", ~)로 [ 를 임의의 문자 c로 입력받은 후, 버리고 
	for문을 정수의 개수만큼 돌리는데, 중간에 ,나 ] 가 같이 있으므로 scanf로 정수를 temp라는 int 형 변수에 입력받은 다음,
	다음 줄에 getchar()를 둠으로써 ,과 ]를 버릴 수 있도록 한다.

	그리고 R이 수행할 함수에 몇 개 들어있는지에 따라 앞, 뒤에 있는 정수들이 D에 의해 삭제될 수 있기 때문에 R의 개수를 알 수 있도록하는
	전역 변수 int swap = 0; 으로 선언해 놓는다.

	그리고 D의 경우, R % 2 == 0이면 deque의 앞쪽에 삽입하고 1이면 뒤쪽에 삽입하도록 작성.

	그런 후, 배열을 보여줘야 하므로 이것도 마찬가지로 swap % 2 == 0 이면 dequq의 앞쪽부터, 1 이면 deque의 뒤쪽부터 printf 하도록 작성한다.
*/

int T, N;
int swap = 0; // R count, R % 2 == 1이면 배열 뒤바뀐 상태, R % 2 == 0이면 배열 그대로인 상태.
int r = 0;
int temp;
char cmd[MAX_LEN];
char c; // 문자들을 단순히 버리기 위함


typedef struct {
	int max;
	int size;
	int front;
	int rear;
	int* que;
}Deck;

void deckInit(Deck* deck) {
	deck->front = deck->rear = deck->size = 0;
	
	if ((deck->que = calloc(MAX_LEN, sizeof(int))) == NULL) { // calloc은 할당된 공간의 값을 모두 0으로 바꾼다.
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
			scanf("%c", &c); // [ 버림
			for (int i = 0;i < N;i++) {
				scanf("%d", &temp); // 숫자 temp에 입력
				getchar(); // ,나 ] 을 버림.
				enqueRear(&deck, temp); // temp를 deck에 삽입.
			}
		}
		else { // 입력이 없을 때
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