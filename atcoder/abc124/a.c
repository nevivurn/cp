#include <stdio.h>

int main(void) {
	int a, b;
	scanf("%d%d", &a, &b);
	int sum = 0;
	for (int i = 0; i < 2; i++) {
		if (a > b) sum += a--;
		else sum += b--;
	}
	printf("%d\n", sum);
}
