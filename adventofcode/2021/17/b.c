#include <stdio.h>

#define SUM(a, steps) ((2*(a) - (steps) + 1) * (steps) / 2)

int main(void) {
	int xmin, xmax, ymin, ymax;
	scanf("target area: x=%d..%d, y=%d..%d", &xmin, &xmax, &ymin, &ymax);

	int xstart, xend = xmax;
	for (xstart = 1; SUM(xstart, xstart) < xmin; xstart++);
	int ystart = ymin, yend = -ymin;

	int cnt = 0;
	for (int x = xstart; x <= xend; x++) {
		for (int y = ystart; y <= yend; y++) {
			for (int i = 1; 1; i++) {
				int xd = SUM(x, i > x ? x : i);
				int yd = SUM(y, i);

				if (yd < ymin)
					break;
				if (xd < xmin || xd > xmax || yd < ymin || yd > ymax)
					continue;

				cnt++;
				break;
			}
		}
	}

	printf("%d\n", cnt);
}
