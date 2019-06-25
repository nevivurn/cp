#include <stdio.h>
#include <stdlib.h>

int arr[100000];
int ops[100000][2];

int cmp(const void *ap, const void *bp) {
	const int *a = ap, *b = bp;
	return *a - *b;
}

int main(void) {
	int n, m;
	scanf("%d%d", &n, &m);

	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &ops[i][1], &ops[i][0]);
	}

	qsort(arr, n, sizeof arr[0], cmp);
	qsort(ops, m, sizeof ops[0], cmp);

	int i = 0;
	while (m--) {
		int b = ops[m][1], c = ops[m][0];
		int j; 
		for (j = 0; j < b && i+j < n && arr[i+j] < c; j++) {
			arr[i+j] = c;
		}
		i += j;
	}

	long long int sum = 0;
	while (n--) {
		sum += arr[n];
	}
	printf("%lld\n", sum);
}
