#include <stdio.h>
#include <assert.h>

#define MOD 1000000007

int dp[2][101][100001];

int isqrt(long long int x) {
	long long int a = x, b = (x+1)/2;
	while (a > b) {
		a = b;
		b = (a + x/a)/2;
	}
	return a;
}

int main(void) {
	long long int n;
	int k;
	scanf("%lld%d", &n, &k);

	int sqrt = isqrt(n)+1;

	dp[0][0][1] = 1;
	for (int i = 0; i < k; i++) {
		for (int j = 1; j < sqrt; j++) {
			dp[0][i][j] += dp[0][i][j-1];
			dp[0][i][j] %= MOD;
		}
		for (int j = 1; j < sqrt-1; j++) {
			dp[1][i][sqrt-j-1] += dp[1][i][sqrt-j];
			dp[1][i][sqrt-j-1] %= MOD;
		}

		for (int j = 1; j < sqrt; j++) {
			dp[0][i+1][j] = dp[0][i][sqrt-1] + dp[1][i][j];
			dp[0][i+1][j] %= MOD;

			if (n/j != j) {
				dp[1][i+1][j] = ((long long int) dp[0][i][j] * (n/j - n/(j+1))) % MOD;
			}
		}

	}

	int ans = 0;
	for (int i = 0; i < sqrt; i++) {
		ans = (ans + dp[0][k][i]) % MOD;
		ans = (ans + dp[1][k][i]) % MOD;
	}

	printf("%d\n", ans);
}
