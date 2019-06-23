#include <stdio.h>
#include <stdlib.h>

typedef struct {
	size_t n, c;
	int *arr;
} list;

void add(list *l, int x) {
	if (l->n+1 > l->c) {
		l->c = l->c*2 + !l->c;
		l->arr = realloc(l->arr, l->c * sizeof *l->arr);
	}
	l->arr[l->n++] = x;
}

int seenx[100000], seeny[100000];
list lstx[100000], lsty[100000];
long long int cntx, cnty;

void dfs(int i, long long int* cnt, long long int* cntb, int* seen, int* seenb, list *lst, list *lstb) {
	seen[i] = 1;
	(*cnt)++;
	for (size_t j = 0; j < lst[i].n; j++) {
		int k = lst[i].arr[j];
		if (seenb[k]) continue;
		dfs(k, cntb, cnt, seenb, seen, lstb, lst);
	}
}

int main(void) {
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		add(&lstx[x-1], y-1);
		add(&lsty[y-1], x-1);
	}

	long long int cnt = -n;
	for (int i = 0; i < 100000; i++) {
		if (seenx[i] || lstx[i].n == 0) continue;
		cntx = cnty = 0;
		dfs(i, &cntx, &cnty, seenx, seeny, lstx, lsty);
		cnt += cntx * cnty;
	}

	for (int i = 0; i < 100000; i++) {
		free(lstx[i].arr);
		free(lsty[i].arr);
	}

	printf("%lld\n", cnt);
}
