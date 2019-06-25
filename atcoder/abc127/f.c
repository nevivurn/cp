#include <stdio.h>
#include <stdlib.h>

#define MAPSIZE 1048576

int cmpmin(int a, int b) {
	return a-b;
}

int cmpmax(int a, int b) {
	return b-a;
}

typedef struct {
	int n, arr[200000];
	int (*cmp)(int, int);
} heap;

void hpush(heap *h, int x) {
	int i = h->n++;
	h->arr[i] = x;

	while (i > 0) {
		int p = (i-1)/2;
		if (h->cmp(h->arr[p], h->arr[i]) > 0) {
			int t = h->arr[p];
			h->arr[p] = h->arr[i];
			h->arr[i] = t;
			i = p;
		} else break;
	}
}

int hpop(heap *h) {
	int ret = h->arr[0];
	h->arr[0] = h->arr[--h->n];

	int i = 0, c;
	while ((c = i*2 + 1) < h->n) {
		if (c+1 < h->n && h->cmp(h->arr[c], h->arr[c+1]) > 0) {
			c++;
		}

		if (h->cmp(h->arr[i], h->arr[c]) > 0) {
			int t = h->arr[c];
			h->arr[c] = h->arr[i];
			h->arr[i] = t;
			i = c;
		} else break;
	}

	return ret;
}

int hpeek(const heap *h) {
	return h->arr[0];
}

heap left = {.cmp = cmpmax}, right = {.cmp = cmpmin};

int main(void) {
	int q;
	scanf("%d", &q);

	long long int y = 0, d = 0;

	while (q--) {
		int t;
		scanf("%d", &t);
		if (t == 1) {
			int a, b;
			scanf("%d%d", &a, &b);
			int px = hpeek(&left);
			y += abs(px-a);
			d += b;

			if (a < px) hpush(&left, a);
			else hpush(&right, a);

			int diff = left.n - right.n;
			if (diff == 2) {
				hpush(&right, hpop(&left));
				diff = 0;
			} else if (diff == -1) {
				hpush(&left, hpop(&right));
				diff = 1;
			}

			int x = hpeek(&left);
			if (x != px) {
				if (x > px) diff -= 2;
				y += (x-px) * diff;
			}
		} else {
			printf("%d %lld\n", hpeek(&left), y+d);
		}
	}
}
