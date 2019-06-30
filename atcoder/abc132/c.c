#include <stdio.h>
#include <stdlib.h>

int arr[100000];

int cmp(const void *ap, const void *bp) {
	const int *a = ap, *b = bp;
	return *a - *b;
}

int main(void) {
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
	qsort(arr, n, sizeof arr[0], cmp);
	printf("%d\n", arr[n/2] - arr[n/2-1]);
}
