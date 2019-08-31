#include <stdio.h>

#define SIZE 50
#define TARGET 1000000000

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

void step(int state[2][SIZE][SIZE], int *cur) {
	int (*in)[SIZE] = state[*cur];
	int (*out)[SIZE] = state[!*cur];

	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			switch(in[i][j]) {
			case 0:
				if (adj(in, i, j, 1) >= 3) out[i][j] = 1;
				else out[i][j] = 0;
				break;
			case 1:
				if (adj(in, i, j, 2) >= 3) out[i][j] = 2;
				else out[i][j] = 1;
				break;
			case 2:
				if (adj(in, i, j, 1) && adj(in, i, j, 2)) out[i][j] = 2;
				else out[i][j] = 0;
				break;
			}
		}
	}

	*cur = !*cur;
}

int cmp(int a[SIZE][SIZE], int b[SIZE][SIZE]) {
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			if (a[i][j] != b[i][j]) return 0;
		}
	}
	return 1;
}

int main(void) {
	int front[2][SIZE][SIZE], fcur = 0;
	int back[2][SIZE][SIZE], bcur = 0;;
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			switch (getchar()) {
			case '.':
				front[fcur][i][j] = 0;
				break;
			case '|':
				front[fcur][i][j] = 1;
				break;
			case '#':
				front[fcur][i][j] = 2;
				break;
			}
		}
		getchar();
	}

	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			back[bcur][i][j] = front[fcur][i][j];
		}
	}

	int ind = 0;
	do {
		step(front, &fcur);
		step(front, &fcur);
		step(back, &bcur);
		ind++;
	} while (!cmp(front[fcur], back[bcur]));

	for (int i = 0; i < (TARGET-ind) % ind; i++) {
		step(back, &bcur);
	}

	int a = 0, b = 0;
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			if (back[bcur][i][j] == 1) a++;
			else if (back[bcur][i][j] == 2) b++;
		}
	}
	printf("%d\n", a*b);
}
