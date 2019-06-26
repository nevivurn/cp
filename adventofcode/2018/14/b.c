#include <stdio.h>
#include <stdlib.h>

int count_digits(int x) {
	int cnt = 0;
	do cnt++;
	while ((x /= 10) > 0);
	return cnt;
}

int check(int *a, int *r, int c, int n) {
	for (int i = 0; i < n; i++) {
		if (a[c-1-i] != r[i]) return 0;
	}
	return 1;
}

int main(void) {
	int n;
	scanf("%d", &n);

	int digcnt = count_digits(n);
	int *digits = malloc(digcnt * sizeof *digits);
	for (int i = 0, d = n; i < digcnt; i++) {
		digits[i] = d%10;
		d /= 10;
	}

	int cap = 1024*1024;
	int *arr = malloc(1024*1024 * sizeof *arr);
	arr[0] = 3;
	arr[1] = 7;

	int c = 2;
	int i = 0, j = 1;
	while (1) {
		if (c+2 > cap) arr = realloc(arr, (cap *= 2) * sizeof *arr);

		int r = arr[i]+arr[j];
		if (r >= 10) {
			arr[c++] = r/10;
			if (c >= digcnt && check(arr, digits, c, digcnt)) break;
		}
		arr[c++] = r%10;

		i = (i + arr[i]+1) % c;
		j = (j + arr[j]+1) % c;

		if (c >= digcnt && check(arr, digits, c, digcnt)) break;
	}

	printf("%d\n", c-digcnt);

	free(digits);
	free(arr);
}
