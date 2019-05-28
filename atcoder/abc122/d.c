#include <stdio.h>

#define MOD 1000000007

int dp[98][64];

int main(void) {
	for (int i = 0; i < 64; i++) dp[0][i] = 1;
	dp[0][6] = dp[0][9] = dp[0][18] = 0;

	int n;
	scanf("%d", &n);

	for (int i = 1; i < n-2; i++) {
		for (int j = 0; j < 64; j++) {
			dp[i][j] = 0;
			if (j == 6 || j == 9 || j == 18) continue;

			for (int k = 0; k < 64; k++) {
				if (j%4 == 2 && k%16 == 1) continue; // *AB + C
				if (j%4 == 1 && k%16 == 2) continue; // *AC + B
				if (j%4 == 2 && k%16 == 4) continue; // *BA + C
				if (j%4 == 2 && k>>2 == 1) continue; // AB* + C
				if (j%4 == 2 && k>>4 == 0 && k%4 == 1) continue; // A*B + C
				if ((j>>2) == (k%16))
					dp[i][j] = (dp[i][j] + dp[i-1][k]) % MOD;
			}
		}
	}

	int sum = 0;
	for (int i = 0; i < 64; i++) sum = (sum + dp[n-3][i]) % MOD;
	printf("%d\n", sum);
}
