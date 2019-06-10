#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int n, c, *v, *w;
} list;

list g[100000];

int paint[100000];

void add(int i, int j, int w) {
	if (g[i].n+1 > g[i].c) {
		g[i].c *= 2;
		g[i].v = realloc(g[i].v, g[i].c * sizeof *g[i].v);
		g[i].w = realloc(g[i].w, g[i].c * sizeof *g[i].w);
	}

	g[i].v[g[i].n] = j;
	g[i].w[g[i].n] = w;
	g[i].n++;
}

void dfs(int v) {
	list gc = g[v];
	for (int i = 0; i < gc.n; i++) {
		if (paint[gc.v[i]] != -1) continue;
		paint[gc.v[i]] = gc.w[i] ^ paint[v];
		dfs(gc.v[i]);
	}
}

int main(void) {
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		g[i].n = 0;
		g[i].c = 8;
		g[i].v = malloc(8 * sizeof *g[i].v);
		g[i].w = malloc(8 * sizeof *g[i].w);
		paint[i] = -1;
	}

	for (int i = 0; i < n-1; i++) {
		int a, b, w;
		scanf("%d%d%d", &a, &b, &w);
		a--; b--; w %= 2;
		add(a, b, w);
		add(b, a, w);
	}

	paint[0] = 0;
	dfs(0);

	for (int i = 0; i < n; i++) {
		printf("%d\n", paint[i]);
		free(g[i].v);
		free(g[i].w);
	}
}
