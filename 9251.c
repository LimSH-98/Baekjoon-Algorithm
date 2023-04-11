#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LEN 1000

char str1[MAX_LEN];
char str2[MAX_LEN];
int lcs[MAX_LEN + 1][MAX_LEN + 1];

int main() {
	int len1, len2;
	scanf(" %s", &str1);
	scanf(" %s", &str2);

	len1 = strlen(str1);
	len2 = strlen(str2);

	for (int i = 1;i <= len1;i++) {
		for (int j = 1;j <= len2;j++) {
			if (str1[i - 1] == str2[j - 1]) {
				lcs[i][j] = lcs[i - 1][j - 1] + 1;
			}
			else {
				if (lcs[i - 1][j] > lcs[i][j - 1]) {
					lcs[i][j] = lcs[i - 1][j];
				}
				else
					lcs[i][j] = lcs[i][j - 1];
			}
		}
	}

	printf("%d\n", lcs[len1][len2]);
}