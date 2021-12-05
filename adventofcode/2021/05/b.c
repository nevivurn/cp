#include <stdlib.h>
#include <stdio.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

int grid[1000][1000];

int main(void) {

	int x1, y1, x2, y2;
	while (scanf("%d,%d -> %d,%d", &x1, &y1, &x2, &y2) != EOF) {
		int dx = x2-x1, dy = y2-y1;
		int diff = MAX(abs(dx), abs(dy));
		for (int d = 0; d <= diff; d++)
			grid[x1+dx/diff*d][y1+dy/diff*d]++;
	}

	int cnt = 0;
	for (int x = 0; x < 1000; x++)
		for (int y = 0; y < 1000; y++)
			cnt += grid[x][y] >= 2;
	printf("%d\n", cnt);
}
