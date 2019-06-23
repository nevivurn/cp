#include <stdio.h>

int arr[100000];

int main(void) {
	int n;
	long long int k;
	scanf("%d%lld", &n, &k);

	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	long long int sum = 0, cnt = 0;
	int start = 0;
	for (int i = 0; i < n; i++) {
		sum += arr[i];
		while (sum-arr[start] >= k) {
			sum -= arr[start++];
		}
		if (sum >= k) cnt += start+1;
	}

	printf("%lld\n", cnt);
}
