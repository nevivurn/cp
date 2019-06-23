#include <stdio.h>

#define MOD 1000000007

int dp[2001][2001], a[2000], b[2000];

int main(void) {
	int n, m;
	scanf("%d%d", &n, &m);

	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	for (int i = 0; i < m; i++) scanf("%d", &b[i]);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % MOD;
			dp[i][j] = (dp[i][j] + MOD - dp[i-1][j-1]) % MOD;
			if (a[i-1] == b[j-1]) {
				dp[i][j] = (dp[i][j] + dp[i-1][j-1] + 1) % MOD;
			}
		}
	}
	printf("%d\n", dp[n][m]+1);
}
