#include <stdio.h>

char grid[2000][2001];
int score[2000][2001];

int main(void) {
	int h, w;
	scanf("%d%d ", &h, &w);

	for (int i = 0; i < h; i++) {
		gets(grid[i]);
		for (int j = 0; j < w; j++) grid[i][j] = grid[i][j] == '.';
	}

	for (int i = 0; i < h; i++) {
		int sum = 0;
		for (int j = 0; j < w; j++) {
			if (grid[i][j]) sum++;
			else sum = 0;
			score[i][j] += sum;
		}
		sum = 0;
		for (int j = w-1; j >= 0; j--) {
			if (grid[i][j]) sum++;
			else sum = 0;
			score[i][j] += sum;
		}
	}

	for (int j = 0; j < w; j++) {
		int sum = 0;
		for (int i = 0; i < h; i++) {
			if (grid[i][j]) sum++;
			else sum = 0;
			score[i][j] += sum;
		}
		sum = 0;
		for (int i = h-1; i >= 0; i--) {
			if (grid[i][j]) sum++;
			else sum = 0;
			score[i][j] += sum;
		}
	}

	int max = 0;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (max < score[i][j]) max = score[i][j];
		}
	}
	printf("%d\n", max-3);
}
