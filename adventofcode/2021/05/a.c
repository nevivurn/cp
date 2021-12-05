#include <stdio.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

int grid[1000][1000];

int main(void) {

	int x1, y1, x2, y2;
	while (scanf("%d,%d -> %d,%d", &x1, &y1, &x2, &y2) != EOF) {
		if (x1 != x2 && y1 != y2)
			continue;

		int xmin = MIN(x1, x2);
		int xmax = MAX(x1, x2);
		int ymin = MIN(y1, y2);
		int ymax = MAX(y1, y2);

		for (int x = xmin; x <= xmax; x++)
			for (int y = ymin; y <= ymax; y++)
				grid[x][y]++;
	}

	int cnt = 0;
	for (int x = 0; x < 1000; x++)
		for (int y = 0; y < 1000; y++)
			cnt += grid[x][y] >= 2;
	printf("%d\n", cnt);
}
