#include <stdio.h>
#include <stdlib.h>

#define SIZE 100000

typedef struct {
	int n, c;
	int *arr;
} list;

void ladd(list *l, int x) {
	if (l->n+1 > l->c) {
		l->c = l->c*2 + !l->c;
		l->arr = realloc(l->arr, l->c * sizeof *l->arr);
	}
	l->arr[l->n++] = x;
}

int seen[3][SIZE];
list vert[SIZE];
int q[2][SIZE], qi[2][2];

void qpush(int p, int x) {
	q[p%2][qi[p%2][1]++] = x;
}

int qpop(int p) {
	return q[p%2][qi[p%2][0]++];
}

void qreset(int p) {
	qi[p%2][0] = qi[p%2][1] = 0;
}

int qempty(int p) {
	return qi[p%2][0] == qi[p%2][1];
}

int main(void) {
	int n, m;
	scanf("%d%d", &n, &m);

	for (int i = 0; i < m; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		ladd(&vert[u-1], v-1);
	}

	int s, t;
	scanf("%d%d", &s, &t);
	s--; t--;

	int p = 0;
	qpush(0, s);
	while (!seen[0][t]) {
		if (qempty(p)) {
			qreset(p++);
			if (qempty(p)) {
				break;
			}
		}

		int cur = qpop(p);
		for (int i = 0; i < vert[cur].n; i++) {
			if (!seen[(p+1)%3][vert[cur].arr[i]]) {
				seen[(p+1)%3][vert[cur].arr[i]] = 1;
				qpush(p+1, vert[cur].arr[i]);
			}
		}
	}

	for (int i = 0; i < n; i++) {
		free(vert[i].arr);
	}

	if (seen[0][t]) printf("%d\n", (p+1)/3);
	else puts("-1");
}
