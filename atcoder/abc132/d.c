#include <stdio.h>

#define MOD 1000000007

int c[2001][2001];

int main(void) {
	int n, k;
	scanf("%d%d", &n, &k);

	for (int i = 0; i <= 2000; i++) {
		for (int j = 0; j <= i; j++) {
			if (i == 0 || j == 0) c[i][j] = 1;
			else c[i][j] = (c[i-1][j-1] + c[i-1][j]) % MOD;
		}
	}

	int r = n-k;
	for (int i = 1; i <= k; i++) {
		int rc = c[r+1][i];
		int bc = c[k-1][i-1];
		printf("%lld\n", ((long long int) rc * bc) % MOD);
	}
}
