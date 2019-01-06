#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a%b);
}

int main(void) {
	int t;
	scanf("%d", &t);

	while (t--) {
		int ang;
		scanf("%d", &ang);

		int g = gcd(ang, 180);

		int k = ang/g;
		int n = 180/g;
		if (k > n - 2) n *= 2;
		printf("%d\n", n);
	}
}
