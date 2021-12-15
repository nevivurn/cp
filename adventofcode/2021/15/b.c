#include <stdlib.h>
#include <stdio.h>

//#define N 10
#define N 100

struct state {
	int x, y;
	int risk;
};

struct heap {
	struct state *arr;
	size_t size, len;
};

void h_put(struct heap *h, struct state s) {
	if (h->len == h->size) {
		h->size = h->size ? h->size*2 : 1;
		h->arr = realloc(h->arr, sizeof h->arr[0] * h->size);
	}

	h->arr[h->len++] = s;

	size_t cur = h->len-1;
	while (cur && h->arr[cur].risk < h->arr[(cur-1)/2].risk) {
		struct state t = h->arr[cur];
		h->arr[cur] = h->arr[(cur-1)/2];
		h->arr[(cur-1)/2] = t;
		cur = (cur-1)/2;
	}
}

struct state h_pop(struct heap *h) {
	if (!h->len)
		return (struct state){0};

	struct state out = h->arr[0];
	h->arr[0] = h->arr[--h->len];

	size_t cur = 0;
	while (cur*2+1 < h->len) {
		size_t swap = cur*2 + 1;
		if (swap+1 < h->len && h->arr[swap+1].risk < h->arr[swap].risk)
			swap++;

		if (h->arr[swap].risk < h->arr[cur].risk) {
			struct state t = h->arr[cur];
			h->arr[cur] = h->arr[swap];
			h->arr[swap] = t;
			cur = swap;
		} else break;
	}

	return out;
}

int main(void) {
	struct heap h = {0};
	static int seen[5*N][5*N], grid[N][N], cost[5*N][5*N];
	static const int dirx[] = {-1, 1, 0, 0};
	static const int diry[] = {0, 0, -1, 1};

	for (int y = 0; y < N; y++)
		for (int x = 0; x < N; x++)
			scanf("%1d", &grid[x][y]);

	h_put(&h, (struct state){.x = 0, .y = 0, .risk = 0});

	while (h.len && !seen[5*N-1][5*N-1]) {
		struct state cur = h_pop(&h);

		if (seen[cur.x][cur.y])
			continue;
		seen[cur.x][cur.y] = 1;
		cost[cur.x][cur.y] = cur.risk;

		for (int i = 0; i < 4; i++) {
			struct state next = cur;
			next.x += dirx[i];
			next.y += diry[i];
			if (next.x < 0 || next.x >= 5*N || next.y < 0 || next.y >= 5*N || seen[next.x][next.y])
				continue;
			int c = grid[next.x % N][next.y % N]+8;
			c += next.x/N + next.y/N;
			c %= 9;
			c++;
			next.risk += c;
			h_put(&h, next);
		}
	}

	printf("%d\n", cost[5*N-1][5*N-1]);
	free(h.arr);
}
