#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct r {
	int p;
	char s[11];
};

struct r rs[100];
int ind[100];

int cmp(const void *a, const void *b) {
	struct r ai = rs[*(int*)a], bi = rs[*(int*)b];
	int c = strcmp(ai.s, bi.s);
	if (c) return c;
	return bi.p - ai.p;
}

int main(void) {
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%s%d", rs[i].s, &rs[i].p);
		ind[i] = i;
	}

	qsort(ind, n, sizeof ind[0], cmp);
	for (int i = 0; i < n; i++) printf("%d\n", ind[i]+1);
}
