#include <stdio.h>

int v[50];
int hand[50];

int pfor[51], pback[51];

int heap[50], hz = 0;
int temp[50], tz = 0;

void hpush(int n) {
	//printf("push:%d (%d)\n", n, hz);
	int i = hz++;
	heap[i] = n;
	while (i) {
		int p = (i-1)/2;
		if (heap[i] < heap[p]) {
			int t = heap[i];
			heap[i] = heap[p];
			heap[p] = t;
		} else break;
	}
}

int hpop(void) {
	if (!hz) return 0;
	int ret = heap[0];
	heap[0] = heap[--hz];
	int i = 0;
	while (i*2+1 < hz) {
		int c = i*2+1;
		if (c+1 < hz && heap[c] > heap[c+1]) c++;
		if (heap[i] > heap[c]) {
			int t = heap[i];
			heap[i] = heap[c];
			heap[c] = t;
		} else break;
	}
	return ret;
}

int main(void) {
	int n, k;
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++) scanf("%d", &v[i]);

	pfor[0] = pback[0] = 0;
	for (int i = 1; i <= n; i++) {
		pfor[i] = pfor[i-1] + v[i-1];
		pback[i] = pback[i-1] + v[n-i];
	}

	int max = 0;
	for (int l = 0; l <= k && l <= n; l++) {
		if (l && v[l-1] < 0) hpush(v[l-1]);
		for (int r = 0; l+r <= k && l+r <= n; r++) {
			if (r && v[n-r] < 0) hpush(v[n-r]);
			int sum = pfor[l] + pback[r];
			int c;
			for (int rem = k-l-r; rem && (c = hpop()); rem--) {
				sum -= c;
				temp[tz++] = c;
			}
			if (sum > max) max = sum;
			while (tz) hpush(temp[--tz]);
		}
		hz = 0;
		for (int i = 0; i < l; i++)
			if (v[i] < 0) hpush(v[i]);
	}
	printf("%d\n", max);
}
