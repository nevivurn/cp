#include <stdlib.h>
#include <stdio.h>

#define X 100
#define Y 100

const int dirx[] = {-1, 1, 0, 0}, diry[] = {0, 0, -1, 1};

int grid[Y][X];
int sizes[Y*X];
size_t size_len;

int int_cmp(const void *a, const void *b) {
	return *(const int * )b - *(const int *) a;
}

int dfs(int x, int y) {
	if (x < 0 || x >= X || y < 0 || y >= Y || !grid[y][x])
		return 0;
	grid[y][x] = 0;

	int cnt = 1;
	for (int i = 0; i < 4; i++)
		cnt += dfs(x + dirx[i], y + diry[i]);
	return cnt;
}

int main(void) {
	int c;

	int curx = 0, cury = 0;
	while ((c = getchar()) != EOF) {
		if (c == '\n') {
			curx = 0;
			cury++;
		}
		if (c < '0' || c > '9')
			continue;
		grid[cury][curx++] = c != '9';
	}

	for (int y = 0; y < Y; y++) {
		for (int x = 0; x < X; x++) {
			int cur = dfs(x, y);
			if (cur)
				sizes[size_len++] = cur;
		}
	}

	qsort(sizes, size_len, sizeof sizes[0], int_cmp);
	printf("%d\n", sizes[0] * sizes[1] * sizes[2]);
}
