#include <stdio.h>

const int
	dirx[] = {-1, -1, -1, 0, 0, 1, 1, 1},
	diry[] = {-1, 0, 1, -1, 1, -1, 0, 1};

int grid[10][10];

struct pair {
	int x, y;
};

int step(void) {
	int flashed[10][10] = {0};

	struct pair queue[100];
	int head = 0, tail = 0;

	for (int x = 0; x < 10; x++) {
		for (int y = 0; y < 10; y++) {
			if (++grid[x][y] > 9) {
				queue[tail++] = (struct pair){.x = x, .y = y};
				flashed[x][y] = 1;
			}
		}
	}

	while (head < tail) {
		struct pair cur = queue[head++];

		for (int i = 0; i < 8; i++) {
			int xx = cur.x + dirx[i], yy = cur.y + diry[i];
			if (xx < 0 || xx >= 10 || yy < 0 || yy >= 10 || flashed[xx][yy])
				continue;
			if (++grid[xx][yy] > 9) {
				queue[tail++] = (struct pair){.x = xx, .y = yy};
				flashed[xx][yy] = 1;
			}
		}
	}

	for (int i = 0; i < tail; i++)
		grid[queue[i].x][queue[i].y] = 0;

	return tail;
}

int main(void) {
	for (int x = 0; x < 10; x++) {
		char str[11];
		scanf("%s", str);
		for (int y = 0; y < 10; y++)
			grid[x][y] = str[y]-'0';
	}

	int i = 0;
	while (step() != 100)
		i++;
	printf("%d\n", i+1);
}
