#include <stdio.h>

#define SUM(a, steps) ((2*(a) - (steps) + 1) * (steps) / 2)

int main(void) {
	int xmin, xmax, ymin, ymax;
	scanf("target area: x=%d..%d, y=%d..%d", &xmin, &xmax, &ymin, &ymax);

	int xstart, xend = xmax;
	for (xstart = 1; SUM(xstart, xstart) < xmin; xstart++);
	int ystart = 0, yend = -ymin;

	int best = 0;
	for (int x = xstart; x <= xend; x++) {
		for (int y = ystart; y <= yend; y++) {
			for (int i = 1; i < 3*y; i++) {
				int xd = SUM(x, i > x ? x : i);
				int yd = SUM(y, i);
				int ytop = SUM(y, y);

				if (xd < xmin || xd > xmax || yd < ymin || yd > ymax)
					continue;
				best = ytop > best ? ytop : best;
			}
		}
	}

	printf("%d\n", best);
}
