#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAX_N 50
#define MAX_CHK 13
 
int N, M;
int map[MAX_N][MAX_N];
int houIdx = -1, chkIdx = -1;
int min = 50 * 2 * 50;

typedef struct spot {
	int row;
	int col;
}spot;

spot choosedChk[13], chk[13], hou[13];

int gap(spot a, spot b) {
	int gap = 0;
	gap = a.row > b.row ? a.row - b.row : b.row - a.row;
	gap += a.col > b.col ? a.col - b.col : b.col - a.col;
	return gap;
}

void findMinDis() {
	int distance = 0, sum = 0;
	for (int i = 0;i <= houIdx;i++) {
		int chkDis = 50 * 2;
		for (int j = 0;j < M; j++) {
			distance = gap(hou[i], choosedChk[j]);
			if (distance < chkDis)
				chkDis = distance;
		}
		sum += chkDis;
	}
	if (sum < min)
		min = sum;
}
// 각 치킨집에서 각 집에 걸리는 거리를 구하고, 가장 작은 값을 찾는다

void choose(int depth, int cnt, int isChoose) {

	if (isChoose == 1)
		choosedChk[cnt - 1] = chk[depth];

	if (M == cnt) {
		findMinDis();
		return;
	}
	if (depth == chkIdx)
		return;

	choose(depth + 1, cnt + 1, 1);
	choose(depth + 1, cnt, 0);
}

int main(void) {
	int input;
	scanf("%d%d", &N, &M);

	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			scanf("%d", &input);
			if (input == 1) {
				houIdx++;
				hou[houIdx].row = i;
				hou[houIdx].col = j;
			}
			else if (input == 2) {
				chkIdx++;
				chk[chkIdx].row = i;
				chk[chkIdx].col = j;
			}
		}
	}

	choose(-1, 0, -1);

	printf("%d\n", min);
}