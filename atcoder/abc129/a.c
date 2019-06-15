#include <stdio.h>

int main(void) {
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);

	int sum;
	if (a >= b && a >= c) sum = b+c;
	else if (b >= a && b >= c) sum = a+c;
	else sum = a+b;
	printf("%d\n", sum);
}
