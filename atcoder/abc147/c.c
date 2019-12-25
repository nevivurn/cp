#include <stdio.h>

int main(void) {
	unsigned int n;
	scanf("%u", &n);

	int grid[15][15];
	for (unsigned int i = 0; i < n; i++) {
		for (unsigned int j = 0; j < n; j++)
			grid[i][j] = -1;

		unsigned int cnt;
		scanf("%u", &cnt);

		for (unsigned int j = 0; j < cnt; j++) {
			int x, y;
			scanf("%d%d", &x, &y);
			grid[i][x-1] = y;
		}
	}

	int max = 0;
	for (unsigned int try = 1; try < (1u<<n); try++) {
		int sat = 1;

		for (unsigned int i = 0; i < n; i++) {
			if ((try & (1u<<i)) != (1u<<i))
				continue;

			for (unsigned int j = 0; j < n; j++) {
				if (grid[i][j] != -1 &&
						(try&(1u<<j)) != (grid[i][j]<<j))
					sat = 0;
			}
		}

		if (sat && __builtin_popcount(try) > max)
			max = __builtin_popcount(try);
	}

	printf("%d\n", max);
}
