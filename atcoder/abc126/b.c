#include <stdio.h>

int main(void) {
	int a, b;
	scanf("%2d%2d", &a, &b);
	a = a>0 && a < 13;
	b = b>0 && b < 13;

	if (a && b) puts("AMBIGUOUS");
	else if (a) puts("MMYY");
	else if (b) puts("YYMM");
	else puts("NA");
}
