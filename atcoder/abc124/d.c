#include <stdio.h>

int groups[100002];

int main(void) {
	int n, k;
	scanf("%d%d ", &n, &k);

	int gind = groups[0] = 0;
	for (int i = 0; i < n; i++) {
		int c = getchar() == '1';
		if (c == gind%2) groups[gind]++;
		else groups[++gind] = 1;
	}
	if (gind%2) groups[++gind] = 0;

	int max = 0;
	for (int i = 0; i <= gind; i++) {
		if (max < groups[i]) max = groups[i];
	}

	int sum = 0;
	for (int i = 0; i <= gind; i++) {
		if (i > 2*k) sum -= groups[i-2*k-1];
		sum += groups[i];
		if (i%2 != gind%2 && max < sum) max = sum;
	}
	sum = 0;
	for (int i = 0; i <= gind; i++) {
		if (i > 2*k) sum -= groups[gind-(i-2*k-1)];
		sum += groups[gind-i];
		if (i%2 != gind%2 && max < sum) max = sum;
	}

	printf("%d\n", max);
}
