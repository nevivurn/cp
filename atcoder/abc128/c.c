#include <stdio.h>

int bulb[10], p[10];

int countbits(int i) {
	int c;
	for (c = 0; i; c++) i &= i-1;
	return c;
}

int main(void) {
	int n, m;
	scanf("%d%d", &n, &m);

	for (int i = 0; i < m; i++) {
		int k;
		scanf("%d", &k);
		bulb[i] = 0;
		for (int j = 0; j < k; j++) {
			int c;
			scanf("%d", &c);
			bulb[i] |= 1<<(c-1);
		}
	}
	for (int i = 0; i < m; i++) scanf("%d", &p[i]);

	int cnt = 0;
	for (int i = 0; i < 1<<n; i++) {
		int ok = 1;
		for (int j = 0; ok && j < m; j++)
			ok = countbits(bulb[j]&i)%2 == p[j];
		cnt += ok;
	}
	printf("%d\n", cnt);
}
