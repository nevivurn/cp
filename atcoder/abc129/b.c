#include <stdio.h>
#include <stdlib.h>

int arr[100];

int cmp(const void *a, const void *b) {
	return *(const int *) a - *(const int *) b;
}

int main(void) {
	int n;
	scanf("%d", &n);

	int sum = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		sum += arr[i];
	}

	int min = sum;
	int part = 0;
	for (int i = 0; i < n-1; i++) {
		part += 2*arr[i];
		if (min > abs(sum-part)) min = abs(sum-part);
	}

	printf("%d\n", min);
}
