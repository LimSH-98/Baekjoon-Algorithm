#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX_GRAPH_SIZE 101

int visited[MAX_GRAPH_SIZE];
int data[MAX_GRAPH_SIZE][MAX_GRAPH_SIZE];
int count = 0;

void insertData(int start,int end) {
	data[start][end] = 1;
	data[end][start] = 1;
}
void dfs(int start,int size) {
	if (visited[start]) return;

	visited[start] = 1;
	for (int i = 1; i<= size;i++) {
		if (data[start][i] == 1 && visited[i] == 0) {
			count++;
			dfs(i,size);
		}
	}
}

int main(void) {
	int size, pair,com1,com2;
	scanf("%d", &size);
	fgetc(stdin);
	scanf("%d", &pair);
	fgetc(stdin);
	

	for (int i = 1;i <= pair;i++) {
		scanf("%d %d", &com1, &com2);
		insertData(com1, com2);
		fgetc(stdin);
	}	

	dfs(1,size);

	printf("%d\n", count);
	return 0;
}
