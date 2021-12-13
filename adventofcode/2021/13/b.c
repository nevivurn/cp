#define _POSIX_C_SOURCE 200809L
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int grid[1500][1000];
int maxx, maxy;

#define MAX(a, b) ((a) > (b) ? (a) : (b))

void foldx(int n) {
	for (int x = 0; x < n; x++) {
		int d = 2 * (n-x);
		for (int y = 0; y < maxy; y++) {
			grid[x][y] |= grid[x+d][y];
			grid[x+d][y] = 0;
		}
	}
	maxx = n+1;
}

void foldy(int n) {
	for (int y = 0; y < n; y++) {
		int d = 2 * (n-y);
		for (int x = 0; x < maxx; x++) {
			grid[x][y] |= grid[x][y+d];
			grid[x][y+d] = 0;
		}
	}
	maxy = n+1;
}

int main(void) {
	char *str = NULL;
	size_t sz = 0;

	ssize_t len = 0;
	while ((len = getline(&str, &sz, stdin)) != -1) {
		if (len <= 0 || *str == '\0' || *str == '\n' || *str == '\r')
			continue;

		if (strstr(str, "fold") != NULL) {
			char c;
			int n;
			sscanf(str, "fold along %c=%d", &c, &n);
			if (c == 'x')
				foldx(n);
			else
				foldy(n);
		} else {
			int a, b;
			sscanf(str, "%d,%d", &a, &b);
			grid[a][b] = 1;
			maxx = MAX(maxx, a+1);
			maxy = MAX(maxy, b+1);
		}
	}

	for (int y = 0; y < maxy; y++) {
		for (int x = 0; x < maxx; x++)
			putchar(grid[x][y] ? '#' : ' ');
		putchar('\n');
	}

	free(str);
}
