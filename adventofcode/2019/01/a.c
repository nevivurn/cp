#include <stdio.h>

int main(void) {
	int sum = 0, cur;
	while (scanf("%d", &cur) != EOF)
		sum += cur/3 - 2;
	printf("%d\n", sum);
}
