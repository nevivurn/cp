#include <stdio.h>
#include <stdlib.h>

#define BOUND 400

typedef struct {
	int x, y;
} coord;

size_t coord_cnt;
coord coords[1000];

int coord_dist(coord a, coord b) {
	return abs(a.x - b.x) + abs(a.y - b.y);
}

int coord_distsum(coord pt) {
	int sum = 0;
	for (size_t i = 0; i < coord_cnt; i++)
		sum += coord_dist(pt, coords[i]);
	return sum;
}

int main(void) {
	coord_cnt = 0;
	int x, y;
	while (scanf("%d, %d", &x, &y) != EOF) {
		coords[coord_cnt] = (coord) {x, y};
		coord_cnt++;
	}

	int area_size = 0;
	for (int i = -BOUND; i <= BOUND; i++) {
		for (int j = -BOUND; j <= BOUND; j++) {
			coord pt = {i, j};
			int dist = coord_distsum(pt);
			
			area_size += dist < 10000;
		}
	}

	printf("%d\n", area_size);
}
