#include <stdio.h>

#define MOD 1000000007

int main(void) {
	int n, m;
	scanf("%d%d", &n, &m);

	int last[3] = {1, 0, 0};
	int bad = 0;
	for (int i = 1; i <= n; i++) {
		last[2] = last[1];
		last[1] = last[0];

		if (i > bad && m) {
			m--;
			scanf("%d", &bad);
		}
		if (i == bad) last[0] = 0;
		else last[0] = (last[1]+last[2]) % MOD;
	}

	printf("%d\n", last[0]);
}
