#include <stdio.h>

#define MOD 1000000007
#define ISIX 166666668

int modinvp(int a, int p) {
	long long int ret = 1, b = a;
	int e = p-2;
	while (e) {
		if (e&1) {
			ret = (ret * b) % p;
		}
		e >>= 1;
		b = (b * b) % p;
	}
	return (int) ret;
}

int choose(int n, int k) {
	long long int num = 1, den = 1;
	for (int i = n-k+1; i <= n; i++) {
		num = (num * i) % MOD;
	}
	for (int i = 2; i <= k; i++) {
		den = (den * i) % MOD;
	}
	num = (num * modinvp((int) den, MOD)) % MOD;
	return (int) num;
}

int main(void) {
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);

	long long int sumx = n;
	sumx = (sumx * (n-1)) % MOD;
	sumx = (sumx * (n+1)) % MOD;
	sumx = (sumx * m) % MOD;
	sumx = (sumx * m) % MOD;
	sumx = (sumx * ISIX) % MOD;

	long long int sumy = m;
	sumy = (sumy * (m-1)) % MOD;
	sumy = (sumy * (m+1)) % MOD;
	sumy = (sumy * n) % MOD;
	sumy = (sumy * n) % MOD;
	sumy = (sumy * ISIX) % MOD;

	long long int sum = (sumx + sumy) % MOD;
	sum = (sum * choose(n*m -2, k-2)) % MOD;
	printf("%d\n", (int) sum);
}
