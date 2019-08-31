#include <stdio.h>

#define SIZE 50

int adj(int arr[SIZE][SIZE], int i, int j, int c) {
	int cnt = 0;
	for (int x = i-1; x <= i+1; x++) {
		if (x < 0 || x >= SIZE) continue;
		for (int y = j-1; y <= j+1; y++) {
			if (y < 0 || y >= SIZE || (x == i && y == j)) continue;
			if (arr[x][y] == c) cnt++;
		}
	}
	return cnt;
}

void step(int out[SIZE][SIZE], int cur[SIZE][SIZE]) {
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			switch(cur[i][j]) {
			case 0:
				if (adj(cur, i, j, 1) >= 3) out[i][j] = 1;
				else out[i][j] = 0;
				break;
			case 1:
				if (adj(cur, i, j, 2) >= 3) out[i][j] = 2;
				else out[i][j] = 1;
				break;
			case 2:
				if (adj(cur, i, j, 1) && adj(cur, i, j, 2)) out[i][j] = 2;
				else out[i][j] = 0;
				break;
			}
		}
	}
}

int main(void) {
	int state[2][SIZE][SIZE];
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			switch (getchar()) {
			case '.':
				state[0][i][j] = 0;
				break;
			case '|':
				state[0][i][j] = 1;
				break;
			case '#':
				state[0][i][j] = 2;
				break;
			}
		}
		getchar();
	}

	int cur = 0;
	for (int i = 0; i < 10; i++) {
		step(state[!cur], state[cur]);
		cur = !cur;
	}

	int wood = 0, lumber = 0;
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			if (state[cur][i][j] == 1) wood++;
			else if (state[cur][i][j] == 2) lumber++;
		}
	}
	printf("%d\n", wood * lumber);
}
