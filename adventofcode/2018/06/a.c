#include <stdio.h>
#include <stdlib.h>

#define BOUND 400

typedef struct {
	int x, y;
} coord;

size_t coord_cnt;
coord coords[1000];
int area_sizes[1000];

int coord_dist(coord a, coord b) {
	return abs(a.x - b.x) + abs(a.y - b.y);
}

int coord_nearest(coord pt) {
	int min_dist = -1, nearest = -1;
	for (size_t i = 0; i < coord_cnt; i++) {
		int dist = coord_dist(pt, coords[i]);
		if (dist < min_dist || min_dist == -1) {
			min_dist = dist;
			nearest = (int) i;
		} else if (dist == min_dist) {
			nearest = -1;
		}
	}
	return nearest;
}

int main(void) {
	coord_cnt = 0;
	int x, y;
	while (scanf("%d, %d", &x, &y) != EOF) {
		coords[coord_cnt] = (coord) {x, y};
		coord_cnt++;
	}

	for (int i = -BOUND; i <= BOUND; i++) {
		for (int j = -BOUND; j <= BOUND; j++) {
			coord pt = {i, j};
			int nearest = coord_nearest(pt);

			if (nearest == -1) continue;

			if (abs(i) == BOUND || abs(j) == BOUND)
				area_sizes[nearest] = -1;
			else if (area_sizes[nearest] != -1)
				area_sizes[nearest]++;
		}
	}

	int largest_area = 0;
	for (size_t i = 0; i < coord_cnt; i++) {
		if (area_sizes[i] > largest_area) {
			largest_area = area_sizes[i];
		}
	}

	printf("%d\n", largest_area);
}
