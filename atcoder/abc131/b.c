#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int n, l;
	scanf("%d%d", &n, &l);

	int flavor = l*n + (n-1)*n/2;

	if (l >= 0) printf("%d\n", flavor-l);
	else {
		if (n > -l) printf("%d\n", flavor);
		else printf("%d\n", flavor-l-n+1);
	}
}
