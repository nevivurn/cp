#include <stdio.h>

int main(void) {
	int w, h, x, y;
	scanf("%d%d%d%d", &w, &h, &x, &y);

	printf("%.9f %d\n", (double) w*h/2, x*2 == w && y*2 == h);
}
