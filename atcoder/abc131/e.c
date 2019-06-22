#include <stdio.h>

int main(void) {
	int n, k;
	scanf("%d%d", &n, &k);

	int max = (n-1)*(n-2)/2;
	if (k > max) {
		puts("-1");
		return 0;
	}

	int rem = max-k;
	printf("%d\n", n-1 + rem);
	for (int i = 1; i < n; i++) {
		printf("%d %d\n", i, n);
	}

	int curn = 1, curt = 2;
	for (int i = 0; i < rem; i++) {
		printf("%d %d\n", curn, curt);
		curt++;
		if (curt == n) {
			curn++;
			curt = curn+1;
		}
	}
}
