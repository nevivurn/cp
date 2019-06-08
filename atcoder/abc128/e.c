#include <stdio.h>
#include <stdlib.h>

int work[400000][3];

int cmp(const void *a, const void *b) {
	const int *ai = a, *bi = b;
	return ai[0] - bi[0];
}

struct node {
	int n;
	struct node *l, *r;
};

void twalk(const struct node *root) {
	if (root == NULL) return;
	printf("walk: %d\n", root->n);
	twalk(root->l);
	twalk(root->r);
}

void tpush(struct node **root, int n) {
	//printf("push %d\n", n);
	while (*root)
		if ((*root)->n >= n) root = &(*root)->l;
		else root = &(*root)->r;

	*root = malloc(sizeof **root);
	(*root)->n = n;
	(*root)->l = NULL;
	(*root)->r = NULL;
}

void tpop(struct node **root, int n) {
	//printf("pop %d\n", n);
	while ((*root)->n != n)
		if ((*root)->n > n) root = &(*root)->l;
		else if ((*root)->n < n) root = &(*root)->r;

	struct node *c = NULL;
	if ((*root)->l == NULL) c = (*root)->r;
	else if ((*root)->r == NULL) c = (*root)->l;
	else {
		struct node **cp = &(*root)->r;
		while ((*cp)->l) cp = &(*cp)->l;
		(*root)->n = (*cp)->n;
		struct node *rem = *cp;
		if ((*cp)->l) *cp = (*cp)->l;
		else *cp = (*cp)->r;
		free(rem);
		return;
	}

	free(*root);
	*root = c;
}

int tmin(const struct node *root) {
	if (root == NULL) return -1;
	while (root->l) root = root->l;
	return root->n;
}

int main(void) {
	int n, q;
	scanf("%d%d", &n, &q);

	for (int i = 0; i < n; i++) {
		int s, t, x;
		scanf("%d%d%d", &s, &t, &x);
		work[i*2][0] = s-x;
		work[i*2][1] = 1;
		work[i*2][2] = x;
		work[i*2+1][0] = t-x;
		work[i*2+1][1] = 0;
		work[i*2+1][2] = x;
	}
	qsort(work, 2*n, sizeof work[0], cmp);

	struct node *root = NULL;
	int ind = 0;
	for (int i = 0; i < q; i++) {
		int d;
		scanf("%d", &d);
		while (ind < 2*n && work[ind][0] <= d) {
			//printf("work[%d]: %d %d %d\n", ind, work[ind][0], work[ind][1], work[ind][2]);
			if (work[ind][1]) tpush(&root, work[ind][2]);
			else tpop(&root, work[ind][2]);
			//twalk(root);
			ind++;
		}
		printf("%d\n", tmin(root));
	}
}
