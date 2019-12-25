#include <stdio.h>
#include <stdlib.h>

#define MAXDIFF (80*160)

int dp[80][80][MAXDIFF] = {0};
int grida[80][80], gridb[80][80];

int main(void) {
	int h, w;
	scanf("%d%d", &h, &w);

	for (int i = 0; i < h; i++)
		for (int j = 0; j < w; j++)
			scanf("%d", &grida[i][j]);
	for (int i = 0; i < h; i++)
		for (int j = 0; j < w; j++)
			scanf("%d", &gridb[i][j]);

	dp[0][0][abs(grida[0][0] - gridb[0][0])] = 1;
	for (int i = 1; i < h; i++) {
		int cur = abs(grida[i][0] - gridb[i][0]);
		for (int k = 0; k < MAXDIFF; k++) {
			if (dp[i-1][0][k]) {
				dp[i][0][abs(k+cur)] = 1;
				dp[i][0][abs(k-cur)] = 1;
			}
		}
	}
	for (int j = 1; j < w; j++) {
		int cur = abs(grida[0][j]-gridb[0][j]);
		for (int k = 0; k < MAXDIFF; k++) {
			if (dp[0][j-1][k]) {
				dp[0][j][abs(k+cur)] = 1;
				dp[0][j][abs(k-cur)] = 1;
			}
		}
	}

	for (int i = 1; i < h; i++) {
		for (int j = 1; j < w; j++) {
			int cur = abs(grida[i][j]-gridb[i][j]);
			for (int k = 0; k < MAXDIFF; k++) {
				if (dp[i-1][j][k] || dp[i][j-1][k]) {
					dp[i][j][abs(k+cur)] = 1;
					dp[i][j][abs(k-cur)] = 1;
				}
			}
		}
	}

	for (int k = 0; k < MAXDIFF; k++) {
		if (!dp[h-1][w-1][k])
			continue;
		printf("%d\n", k);
		break;
	}
}
