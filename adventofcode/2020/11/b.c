#include <stdio.h>
#include <stdbool.h>

#define N 100

int dim;
#define check_bounds(i, j) (i >= 0 && i < dim && j >= 0 && j < dim)

bool grid[N][N];
bool occupied[N][N];
bool next_occupied[N][N];
bool *vision[N][N][8];

void parse(void) {
	char line[N];
	while (fgets(line, sizeof line, stdin) != NULL) {
		int i;
		for (i = 0; line[i] != '\0' && line[i] != '\n'; i++)
			grid[dim][i] = line[i] == 'L';
		dim++;
	}
}

void build_vision(int ii, int ij, int di, int dj, int vind) {
	bool *ptr = NULL;
	for (int i = ii, j = ij; check_bounds(i, j); i += di, j += dj) {
		if (grid[i][j]) {
			vision[i][j][vind] = ptr;
			ptr = &occupied[i][j];
		}
	}
}

int main(void) {
	parse();

	for (int i = 0; i < dim; i++) {
		build_vision(i, 0, 0, 1, 0);
		build_vision(i, dim-1, 0, -1, 1);

		build_vision(i, 0, 1, 1, 4);
		build_vision(dim-1, dim-1-i, -1, -1, 5);

		build_vision(i, 0, -1, 1, 6);
		build_vision(0, i, 1, -1, 7);
	}
	for (int i = 0; i < dim; i++) {
		build_vision(0, i, 1, 0, 2);
		build_vision(dim-1, i, -1, 0, 3);

		build_vision(0, i, 1, 1, 4);
		build_vision(dim-1-i, dim-1, -1, -1, 5);

		build_vision(dim-1, i, -1, 1, 6);
		build_vision(i, dim-1, 1, -1, 7);
	}

	bool change = true;
	while (change) {
		change = false;
		for (int i = 0; i < dim; i++) {
			for (int j = 0; j < dim; j++) {
				if (!grid[i][j])
					continue;

				int cnt = 0;
				for (int k = 0; k < 8; k++)
					cnt += vision[i][j][k] != NULL ? *vision[i][j][k] : 0;

				if (!occupied[i][j] && cnt == 0) {
					next_occupied[i][j] = true;
					change = true;
				} else if (occupied[i][j] && cnt >= 5) {
					next_occupied[i][j] = false;
					change = true;
				} else
					next_occupied[i][j] = occupied[i][j];
			}
		}

		for (int i = 0; i < dim; i++)
			for (int j = 0; j < dim; j++)
				occupied[i][j] = next_occupied[i][j];
	}

	int cnt = 0;
	for (int i = 0; i < dim; i++)
		for (int j = 0; j < dim; j++)
			cnt += occupied[i][j];
	printf("%d\n", cnt);
}
