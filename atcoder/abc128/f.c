#include <stdio.h>

int lot[100000];

int main(void) {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &lot[i]);

	long long max = 0;
	for (long long c = 1; c < n-1; c++) {
		long long sum = 0;
		for (long long k = 1; (k+1)*c < n-1; k++) {
			if ((n-1)%c == 0 && n-1 <= 2*k*c) break;
			sum += lot[n-1 - k*c] + lot[k*c];
			if (max < sum) max = sum;
		}
	}
	printf("%lld\n", max);
}
