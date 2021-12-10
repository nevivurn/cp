#include <stdio.h>

#define X 100
#define Y 100

const int dirx[] = {-1, 1, 0, 0}, diry[] = {0, 0, -1, 1};

int grid[Y][X];

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
		grid[cury][curx++] = c - '0';
	}

	int sum = 0;
	for (int y = 0; y < Y; y++) {
		for (int x = 0; x < X; x++) {
			int min = 1;
			for (int i = 0; i < 4; i++) {
				int xx = x + dirx[i];
				int yy = y + diry[i];

				if (xx < 0 || xx >= X || yy < 0 || yy >= Y)
					continue;
				if (grid[y][x] >= grid[yy][xx])
					min = 0;
			}
			if (min)
				sum += grid[y][x]+1;
		}
	}

	printf("%d\n", sum);
}
