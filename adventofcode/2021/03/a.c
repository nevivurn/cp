#include <stdio.h>

#define N 12

unsigned int solve(size_t n, unsigned int arr[n]) {
	size_t count[N] = {0};
	for (size_t i = 0; i < n; i++)
		for (int j = 0; j < N; j++)
			count[j] += (arr[i] & 1u<<j) == 1u<<j;

	unsigned int out = 0u;
	for (int i = 0; i < N; i++)
		out |= (count[i]*2 >= n) << i;
	return out;
}

int main(void) {
	char cur[N+1];
	unsigned int nums[1000] = {0};
	size_t cnt = 0;
	while (scanf("%s", cur) == 1) {
		for (int i = 0; i < N; i++)
			nums[cnt] |= (cur[i] == '1') << (N-1-i);
		cnt++;
	}

	unsigned int s = solve(cnt, nums);
	printf("%u\n", s * (~s & ((1u<<N)-1)));
}
