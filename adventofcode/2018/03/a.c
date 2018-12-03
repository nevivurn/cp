#include <stdio.h>

int main(void) {
	int grid[1000][1000] = {0};

	int cnt = 0;
	int ind, x, y, w, h;
	while (scanf("%d%d%d%d%d", &ind, &x, &y, &w, &h) != EOF) {
		for (int i = x; i < x+w; i++) {
			for (int j = y; j < y+h; j++) {
				if (grid[i][j] == 0)
					grid[i][j] = 1;
				else if (grid[i][j] == 1) {
					grid[i][j] = 2;
					cnt++;
				}
			}
		}
	}

	printf("%d\n", cnt);
}
