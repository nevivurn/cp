#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007

int main(void) {
	int n;
	scanf("%d", &n);

	long long int arr[300000];
	for (int i = 0; i < n; i++)
		scanf("%lld", &arr[i]);

	long long int sum = 0;
	for (int i = 0; i < 60; i++) {
		long long int a = 0, b = 0;
		for (int j = 0; j < n; j++)
			if (arr[j] & 1ll<<i) a++;
			else b++;

		a = (a*b) % MOD;
		b = (1ll << i) % MOD;
		sum += (a*b) % MOD;
		sum %= MOD;
	}

	printf("%lld\n", sum);
}
