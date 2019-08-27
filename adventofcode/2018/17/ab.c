#include <stdio.h>

#define XMAX 2000
#define YMAX 2000
int grid[XMAX+1][YMAX+1];
int ymin, ymax;

void flow(int x, int y) {
	// source down
	while (grid[x][y] == 0 && y <= ymax) {
		grid[x][y] = 2;
		y++;
	}
	if (y > ymax) return;
	y--;

	// check for existing water & runoff
	if (grid[x][y+1] == 2) return;
	if (grid[x][y+1] == 3) {
		for (int xp = x-1;; xp--) {
			if (grid[xp][y+1] == 2) return;
			if (grid[xp][y+1] == 3) continue;
			break;
		}
		for (int xp = x+1;; xp++) {
			if (grid[xp][y+1] == 2) return;
			if (grid[xp][y+1] == 3) continue;
			break;
		}
	}

	for (int yp = y; yp >= ymin; yp--) {
		grid[x][yp] = 3;

		int off = 0;
		for (int xp = x-1;; xp--) {
			if (grid[xp][yp] == 1) break;
			if (grid[xp][yp+1] == 0 || grid[xp][yp+1] == 2) {
				off = 1;
				flow(xp, yp);
				break;
			} else grid[xp][yp] = 3;
		}
		for (int xp = x+1;; xp++) {
			if (grid[xp][yp] == 1) break;
			if (grid[xp][yp+1] == 0 || grid[xp][yp+1] == 2) {
				off = 1;
				flow(xp, yp);
				break;
			} else grid[xp][yp] = 3;
		}

		if (off) break;
	}
}

int main(void) {
	ymin = 1000, ymax = 0;
	while (1) {
		char axis;
		int apos, bstart, bend;
		if (scanf(" %c=%d, %*c=%d..%d", &axis, &apos, &bstart, &bend) == EOF)
			break;

		int xa, xb, ya, yb;
		if (axis == 'x') {
			xa = xb = apos;
			ya = bstart;
			yb = bend;
		} else {
			ya = yb = apos;
			xa = bstart;
			xb = bend;
		}

		if (ya < ymin) ymin = ya;
		if (yb > ymax) ymax = yb;

		for (int x = xa; x <= xb; x++) {
			for (int y = ya; y <= yb; y++) {
				grid[x][y] = 1;
			}
		}
	}

	flow(500, 0);

	int a = 0, b = 0;
	int row[XMAX+1];
	for (int y = ymin; y <= ymax; y++) {
		for (int x = 0, bound = 0; x <= XMAX; x++) {
			switch (grid[x][y]) {
			case 0:
				row[x] = 0;
				bound = 0;
				break;
			case 1:
				row[x] = 0;
				bound = 1;
				break;
			case 2:
				a++;
				row[x] = 0;
				bound = 0;
				break;
			case 3:
				a++;
				row[x] = bound;
				break;
			}
		}

		for (int x = XMAX, bound = 0; x >= 0; x--) {
			switch (grid[x][y]) {
			case 0:
				bound = 0;
				break;
			case 1:
				bound = 1;
				break;
			case 2:
				bound = 0;
				break;
			case 3:
				if (bound && row[x]) b++;
				break;
			}
		}
	}
	printf("%d\n%d\n", a, b);
}
