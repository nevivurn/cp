#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MOD 998244353

int main(void) {
	long long int n;
	scanf("%lld", &n);

	char s[n+1];
	scanf("%s", s);

	long long int lind, rind;
	for (lind = 0; lind < n-1; lind++)
		if (s[lind] != s[lind+1]) break;
	for (rind = n-1; rind > 0; rind--)
		if (s[rind] != s[rind-1]) break;

	long long int cnt;
	if (s[0] == s[n-1]) {
		cnt = (lind+2)*(n-rind+1);
	} else {
		cnt = (lind+1) + (n-rind) + 1;
	}

	printf("%lld\n", cnt%MOD);
}
