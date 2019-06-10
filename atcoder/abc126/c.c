#include <stdio.h>

int main(void) {
	int n, k;
	scanf("%d%d", &n, &k);

	double pr = 0;
	if (k <= n) pr = n-k+1;

	for (int i = 1; i <= n && i < k; i++) {
		int s = i, cnt = 0;
		while (s < k) {
			cnt++;
			s *= 2;
		}
		pr += 1.0/(1<<cnt);
	}
	printf("%.9f\n", pr/n);
}
