#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int x = 0, y = 0, dx = 10, dy = 1;

	char op;
	int arg;
	while (scanf(" %c%d", &op, &arg) != EOF) {
		switch (op) {
		case 'N':
			dy += arg;
			break;
		case 'S':
			dy -= arg;
			break;
		case 'E':
			dx += arg;
			break;
		case 'W':
			dx -= arg;
			break;
		case 'R':
			arg = 360 - arg;
			// fall through
		case 'L':
			arg /= 90;
			while (arg--) {
				int t = dx;
				dx = -dy;
				dy = t;
			}
			break;
		case 'F':
			while (arg--) {
				x += dx;
				y += dy;
			}
			break;
		}
	}

	printf("%d\n", abs(x) + abs(y));
}
