#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int x = 0, y = 0, d = 0;

	char op;
	int arg;
	while (scanf(" %c%d", &op, &arg) != EOF) {
		if (op == 'F') {
			switch (d) {
			case 0:
				op = 'E';
				break;
			case 1:
				op = 'S';
				break;
			case 2:
				op = 'W';
				break;
			case 3:
				op = 'N';
				break;
			}
		}

		switch (op) {
		case 'N':
			x += arg;
			break;
		case 'S':
			x -= arg;
			break;
		case 'E':
			y += arg;
			break;
		case 'W':
			y -= arg;
			break;
		case 'R':
			d = (d + arg/90) % 4;
			break;
		case 'L':
			d = (4 + d - arg/90) % 4;
			break;
		}
	}

	printf("%d\n", abs(x) + abs(y));
}
