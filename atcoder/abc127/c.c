#include <stdio.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

int main(void) {
	int n, m;
	scanf("%d%d", &n, &m);

	int l = 1, r = n;
	while (m--) {
		int a, b;
		scanf("%d%d", &a, &b);
		l = MAX(a, l);
		r = MIN(b, r);
	}

	if (l > r) puts("0");
	else printf("%d\n", r-l+1);
}
