#include <stdlib.h>
#include <stdio.h>

#define MAXN 100000

struct list {
	int n, c;
	int *edges;
} verts[MAXN];

void add_list(struct list *l, int v) {
	if (l->n+1 > l->c) {
		if (!l->c)
			l->c = 1;
		l->c *= 2;
		l->edges = realloc(l->edges, (size_t)l->c * sizeof *l->edges);
	}
	l->edges[l->n++] = v;
}
void del_list(struct list *l, int v) {
	int tail = 0;
	for (int head = 0; head < l->n; head++) {
		if (l->edges[head] == v)
			continue;
		l->edges[tail++] = l->edges[head];
	}
	l->n--;
}

void add_edge(int a, int b) {
	add_list(&verts[a], b);
	add_list(&verts[b], a);
}

int calc_dists_rec(int c, int dists[MAXN], int dist) {
	if (dists[c] != -1)
		return -1;
	dists[c] = dist;

	int best = dist;
	for (int i = 0; i < verts[c].n; i++) {
		int d = calc_dists_rec(verts[c].edges[i], dists, dist+1);
		if (d > best)
			best = d;
	}
	return best;
}

int calc_dists(int s, int dists[MAXN]) {
	for (int i = 0; i < MAXN; i++)
		dists[i] = -1;
	return calc_dists_rec(s, dists, 0);
}

int udist[MAXN], vdist[MAXN], cdist[MAXN];

int crit_point(int s) {
	if (udist[s] >= vdist[s])
		return s;

	int bestv = -1, bestd = MAXN;
	for (int i = 0; i < verts[s].n; i++) {
		int n = verts[s].edges[i];
		if (vdist[n] < bestd) {
			bestv = n;
			bestd = vdist[n];
		}
	}

	return crit_point(bestv);
}

int main(void) {
	int n, u, v;
	scanf("%d%d%d", &n, &u, &v);
	u--; v--;

	for (int i = 0; i < n-1; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		add_edge(a-1, b-1);
	}

	calc_dists(u, udist);
	calc_dists(v, vdist);
	int crit = crit_point(u);

	int before;
	for (before = 0; before < verts[crit].n-1; before++) {
		int da = udist[verts[crit].edges[before]];
		int db = udist[verts[crit].edges[before+1]];
		if (da < db)
			break;
	}
	int befv = verts[crit].edges[before];
	del_list(&verts[befv], crit);
	int max = calc_dists(befv, cdist);

	printf("%d\n", udist[befv] + max + (udist[crit] == vdist[crit]));

	for (int i = 0; i < n; i++)
		free(verts[i].edges);
}
