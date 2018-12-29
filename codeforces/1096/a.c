#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	int t;
	scanf("%d", &t);

	while (t--) {
		int l, r;
		scanf("%d%d", &l, &r);

		if (l == 1) printf("1 %d\n", r);
		else printf("%d %d\n", l, l*2);
	}
}
