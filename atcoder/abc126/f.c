#include <stdio.h>

int main(void) {
	int m, k;
	scanf("%d%d", &m, &k);

	if (m == 1) {
		if (k == 0) puts("0 0 1 1");
		else puts("-1");
		return 0;
	}

	int max = (1<<m)-1;
	if (max < k) {
		puts("-1");
		return 0;
	}

	printf("%d ", k);
	for (int i = 0 ; i <= max; i++) {
		if (i == k) continue;
		printf("%d ", i);
	}
	printf("%d ", k);
	for (int i = max; i >= 0; i--) {
		if (i == k) continue;
		printf("%d ", i);
	}
	printf("\n");
}
