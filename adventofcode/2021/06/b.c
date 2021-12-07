#include <stdio.h>

long long int ans[257][9];

int main(void) {
	for (int i = 0; i < 10; i++)
		ans[256][i] = 1;

	for (int step = 255; step >= 0; step--) {
		ans[step][0] = ans[step+1][6] + ans[step+1][8];
		for (int i = 1; i <= 8; i++)
			ans[step][i] = ans[step+1][i-1];
	}

	long long int sum = 0;
	int cur;
	while (scanf("%d,", &cur) != EOF)
		sum += ans[0][cur];
	printf("%lld\n", sum);
}
