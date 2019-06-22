#include <stdio.h>

long long int between(long long int a, long long int b, long long int c) {
	long long int lo = a/c, hi = b/c;
	if (a%c != 0) lo++;
	if (lo > hi) return 0;
	return hi-lo + 1;
}

long long int gcd(long long int a, long long int b) {
	while (b) {
		long long int t = b;
		b = a%b;
		a = t;
	}
	return a;
}

long long int lcm(long long int a, long long int b) {
	long long int g = gcd(a, b);
	return a*b / g;
}

int main(void) {
	long long int a, b, c, d;
	scanf("%lld%lld%lld%lld", &a, &b, &c, &d);

	long long int cnt = b-a + 1;
	cnt -= between(a, b, c);
	cnt -= between(a, b, d);
	cnt += between(a, b, lcm(c, d));
	printf("%lld\n", cnt);
}
