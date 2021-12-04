#include <string.h>
#include <stdio.h>

//#define N 5
#define N 12

int common(size_t n, unsigned int arr[n], int bit) {
	size_t cnt = 0;
	for (size_t i = 0; i < n; i++)
		cnt += (arr[i] & 1u<<bit) == (1u<<bit);
	return cnt*2 >= n;
}

size_t filter(size_t n, unsigned int arr[n], unsigned int mask, unsigned int match) {
	size_t cnt = 0;
	for (size_t i = 0; i < n; i++)
		if ((arr[i] & mask) == match)
			arr[cnt++] = arr[i];
	return cnt;
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

	unsigned int buf[1000];
	memcpy(buf, nums, sizeof nums);

	unsigned int mask = 0, match = 0;
	size_t curcnt = cnt;
	for (int i = N-1; i >= 0 && curcnt > 1; i--) {
		int bit = common(curcnt, buf, i);
		mask |= 1u<<i;
		match |= bit<<i;
		curcnt = filter(curcnt, buf, mask, match);
	}
	unsigned int a = buf[0];

	memcpy(buf, nums, sizeof nums);
	curcnt = cnt;
	mask = match = 0;
	for (int i = N-1; i >= 0 && curcnt > 1; i--) {
		int bit = !common(curcnt, buf, i);
		mask |= 1u<<i;
		match |= bit<<i;
		curcnt = filter(curcnt, buf, mask, match);
	}
	unsigned int b = buf[0];

	printf("%u\n", a * b);
}
