#include <stdio.h>

int main(void) {
	int n, x;
	scanf("%d%d", &n, &x);

	int i, cur = 0;
	for (i = 0; i <= n && cur <= x; i++) {
		int l;
		scanf("%d", &l);
		cur += l;
	}
	printf("%d\n", i);
}
