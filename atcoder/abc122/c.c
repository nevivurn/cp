#include <stdio.h>

int main(void) {
	int n, q;
	char s[100001];
	scanf("%d%d%s", &n, &q, s);

	int c[100001] = {0};
	for (int i = 1; i < n; i++) {
		c[i] = c[i-1];
		if (s[i-1] == 'A' && s[i] == 'C') c[i]++;
	}

	while (q--) {
		int l, r;
		scanf("%d%d", &l, &r);
		l--; r--;
		printf("%d\n", c[r]-c[l]);
	}
}
