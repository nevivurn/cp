#include <stdio.h>

int main(void) {
	int n;
	scanf("%d", &n);

	int max = 0, sum = 0;
	while (n--) {
		int x;
		scanf("%d", &x);
		if (x >= max) sum++;
		if (x > max) max = x;
	}
	printf("%d\n", sum);
}
