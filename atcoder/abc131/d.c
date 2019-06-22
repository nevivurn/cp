#include <stdio.h>
#include <stdlib.h>

int jobs[200000][2];

int cmp(const void *a, const void *b) {
	const int *ap = a, *bp = b;
	return ap[1] - bp[1];
}

int main(void) {
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d%d", &jobs[i][0], &jobs[i][1]);
	}
	qsort(jobs, n, sizeof jobs[0], cmp);

	long long int time = 0;
	for (int i = 0; i < n; i++) {
		time += jobs[i][0];
		if (time > jobs[i][1]) {
			puts("No");
			return 0;
		}
	}
	puts("Yes");
}
