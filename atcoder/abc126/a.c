#include <stdio.h>

int main(void) {
	int n, k;
	scanf("%d%d ", &n, &k);

	for (int i = 0; i < n; i++) {
		int c = getchar();
		if (i+1 == k) c += 32;
		putchar(c);
	}
	printf("\n");
}
