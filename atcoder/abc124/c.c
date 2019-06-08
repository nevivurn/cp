#include <stdio.h>

int dp[100001][2];

int main(void) {
	dp[0][0] = dp[0][1] = 0;

	int i, c;
	for (i = 0; (c = getchar()) != EOF; i++) {
		if (c != '0' && c != '1') break;
		int x = c == '1';
		dp[i+1][x] = dp[i][!x];
		dp[i+1][!x] = dp[i][x]+1;
	}
	printf("%d\n", dp[i][0] < dp[i][1] ? dp[i][0] : dp[i][1]);
}
