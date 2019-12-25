#include <stdio.h>

int main(void) {
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	puts(a+b+c >= 22 ? "bust" : "win");
}
