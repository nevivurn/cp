#include <stdio.h>

int main(void) {
	int sum = 0, cur;
	while (scanf("%d", &cur) != EOF) {
		while (cur/3-2 > 0) {
			cur = cur/3-2;
			sum += cur;
		}
	}
	printf("%d\n", sum);
}
