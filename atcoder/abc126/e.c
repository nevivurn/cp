#include <stdio.h>
#include <stdlib.h>

#define LIST_ISIZE 1

typedef struct {
	int n, c, *v;
} list;

void init(list *l) {
	l->n = 0;
	l->c = LIST_ISIZE;
	l->v = malloc(l->c * sizeof *l->v);
}

void add(list *l, int v) {
	if (l->n+1 > l->c) {
		l->c *= 2;
		l->v = realloc(l->v, l->c * sizeof *l->v);
	}
	l->v[l->n++] = v;
}

typedef struct {
	list same, diff;
} node;

node graph[100000];
int paint[100000];

void dfs(int v) {
	node gc = graph[v];
	for (int i = 0; i < gc.same.n; i++) {
		if (paint[gc.same.v[i]] != -1) continue;
		paint[gc.same.v[i]] = paint[v];
		dfs(gc.same.v[i]);
	}
	for (int i = 0; i < gc.diff.n; i++) {
		if (paint[gc.diff.v[i]] != -1) continue;
		paint[gc.diff.v[i]] = !paint[v];
		dfs(gc.diff.v[i]);
	}
}

int main(void) {
	int n, m;
	scanf("%d%d", &n, &m);

	for (int i = 0; i < n; i++) {
		init(&graph[i].same);
		init(&graph[i].diff);
	}

	for (int i = 0; i < m; i++) {
		int a, b, s;
		scanf("%d%d%d", &a, &b, &s);
		a--; b--; s %= 2;
		if (s) {
			add(&graph[a].diff, b);
			add(&graph[b].diff, a);
		} else {
			add(&graph[a].same, b);
			add(&graph[b].same, a);
		}
	}

	for (int i = 0; i < n; i++) paint[i] = -1;

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (paint[i] != -1) continue;
		paint[i] = 0;
		cnt++;
		dfs(i);
	}

	for (int i = 0; i < n; i++) {
		free(graph[i].same.v);
		free(graph[i].diff.v);
	}

	printf("%d\n", cnt);
}
