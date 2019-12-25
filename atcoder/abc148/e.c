#include <stdio.h>

int main(void) {
	long long int n;
	scanf("%lld", &n);

	if (n%2 != 0) {
		puts("0");
		return 0;
	}

	long long int cnt = 0;
	long long int div = 2;
	while (n/(div *= 5)) {
		cnt += n/div;
	}

	printf("%lld\n", cnt);
}
