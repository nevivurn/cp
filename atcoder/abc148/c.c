#include <stdio.h>

int gcd(int a, int b) {
	while (a) {
		int t = b%a;
		b = a;
		a = t;
	}
	return b;
}

int main(void) {
	int a, b;
	scanf("%d%d", &a, &b);
	int g = gcd(a, b);
	long long int lcm = (long long int)a*b;
	lcm /= g;

	printf("%lld\n", lcm);
}
