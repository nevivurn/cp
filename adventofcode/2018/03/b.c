#include <stdio.h>

int main(void) {
	int grid[1000][1000] = {0};
	int claims[5000];

	int ind, x, y, w, h;
	while (scanf("%d%d%d%d%d", &ind, &x, &y, &w, &h) != EOF) {
		claims[ind] = ind;
		for (int i = x; i < x+w; i++) {
			for (int j = y; j < y+h; j++) {
				if (grid[i][j]) {
					claims[grid[i][j]] = 0;
					claims[ind] = 0;
				}
				grid[i][j] = ind;
			}
		}
	}

	for (int i = 0; i < 5000; i++) {
		if (claims[i]) {
			printf("%d\n", i);
			return 0;
		}
	}
}
