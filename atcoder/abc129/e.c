#include <stdio.h>

#define MOD 1000000007

int main(void) {
	int c, ans = 0, cnt = 2;
	while ((c = getchar()) != EOF) {
		if (c != '1' && c != '0') continue;
		ans = ((ans*2)%MOD + ans + 2) % MOD;
		if (c == '1') cnt = (cnt*2) % MOD;
		else ans = (ans + MOD - cnt) % MOD;
	}
	printf("%d\n", (ans+1) % MOD);
}
