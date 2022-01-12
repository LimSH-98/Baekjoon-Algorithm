#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX_SIZE 1001
#define INF 10000000 // 최대 걸리는 시간
int weight[MAX_SIZE][MAX_SIZE];

void init(int size) {
	for (int i = 0;i <= size;i++) {
		for (int j = 0;j <= size;j++) {
			if (i == j) {
				weight[i][j] = 0;
			}
			else {
				weight[i][j] = INF;
			}
		}
	}
}
void floyd(int size) {

	for (int k = 1;k <= size;k++) {
		for (int i = 1;i <= size;i++) {
			for (int j = 1;j <= size;j++) {
				if (weight[i][k] + weight[k][j] < weight[i][j]) {
					weight[i][j] = weight[i][k] + weight[k][j];
				}
			}
		}
	}

}
int main() {
	int size, road, center,max = 0;
	scanf("%d %d %d", &size, &road, &center);
	init(size);
	for (int i = 1;i <= road;i++) {
		int start, end, wei;
		scanf("%d %d %d", &start, &end, &wei);
		weight[start][end] = wei;
	}

	floyd(size);

	for (int i = 1;i <= size;i++) {
		if (max < weight[i][center] + weight[center][i])
			max = weight[i][center] + weight[center][i];
	}
	
	printf("%d\n", max);

	return 0;
}