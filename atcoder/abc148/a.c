#include <stdio.h>

int main(void) {
	int a, b;
	scanf("%d%d", &a, &b);
	a--; b--;
	int c = (a^b^3) + 1;
	printf("%d\n", c);
}
