#include <stdio.h>

void step(int out[4], int in[4], int op[4]) {
	for (int i = 0; i < 4; i++) out[i] = in[i];

	switch (op[0]) {
		case 0: // addr
			out[op[3]] = in[op[1]] + in[op[2]];
			break;
		case 1: // addi
			out[op[3]] = in[op[1]] + op[2];
			break;
		case 2: // mulr
			out[op[3]] = in[op[1]] * in[op[2]];
			break;
		case 3: // muli
			out[op[3]] = in[op[1]] * op[2];
			break;
		case 4: // banr
			out[op[3]] = in[op[1]] & in[op[2]];
			break;
		case 5: // bani
			out[op[3]] = in[op[1]] & op[2];
			break;
		case 6: // borr
			out[op[3]] = in[op[1]] | in[op[2]];
			break;
		case 7: // bori
			out[op[3]] = in[op[1]] | op[2];
			break;
		case 8: // setr
			out[op[3]] = in[op[1]];
			break;
		case 9: // seti
			out[op[3]] = op[1];
			break;
		case 10: // gtir
			out[op[3]] = op[1] > in[op[2]];
			break;
		case 11: // gtri
			out[op[3]] = in[op[1]] > op[2];
			break;
		case 12: // gtrr
			out[op[3]] = in[op[1]] > in[op[2]];
			break;
		case 13: // eqir
			out[op[3]] = op[1] == in[op[2]];
			break;
		case 14: // eqri
			out[op[3]] = in[op[1]] == op[2];
			break;
		case 15: // eqrr
			out[op[3]] = in[op[1]] == in[op[2]];
			break;
	}
}

int score(int row, int cur[16][16], int grid[16][16]) {
	int cnt = 0;
	for (int i = 0; i < 16; i++) {
		if (cur[row][i]) return 17;
		if (grid[row][i]) cnt++;
	}
	return cnt;
}

int resolve(int cur[16][16], int grid[16][16], int n) {
	if (n == 16) return 1;

	int minrow = 0, minscore = 17;
	for (int row = 0; row < 16; row++) {
		int s = score(row, cur, grid);
		if (s < minscore) {
			minrow = row;
			minscore = s;
		}
	}

	for (int i = 0; i < 16; i++) {
		if (!grid[minrow][i]) continue;

		int open = 1;
		for (int j = 0; j < 16; j++) {
			if (cur[j][i]) {
				open = 0;
				break;
			}
		}
		if (!open) continue;

		cur[minrow][i] = 1;
		if (resolve(cur, grid, n+1)) return 1;
		cur[minrow][i] = 0;
	}
	return 0;
}

int main(void) {
	int grid[16][16];
	for (int i = 0; i < 16; i++)
		for (int j = 0; j < 16; j++)
			grid[i][j] = 1;

	// generate grid
	while (1) {
		int a[4], b[4], c[4], op[4];
		if(scanf(" Before: [%d,%d,%d,%d]", &a[0], &a[1], &a[2], &a[3]) != 4) break;
		scanf("%d%d%d%d", &op[0], &op[1], &op[2], &op[3]);
		scanf(" After: [%d,%d,%d,%d]", &b[0], &b[1], &b[2], &b[3]);

		int orig = op[0];
		for (int i = 0; i < 16; i++) {
			op[0] = i;
			step(c, a, op);

			for (int j = 0; j < 4; j++) {
				if (b[j] != c[j]) {
					grid[orig][i] = 0;
					break;
				}
			}
		}
	}

	// resolve grid
	int ans[16][16] = {0};
	resolve(ans, grid, 0);
	int map[16];
	for (int i = 0; i < 16; i++) {
		for (int j = 0; j < 16; j++) {
			if (ans[i][j]) {
				map[i] = j;
				break;
			}
		}
	}

	int op[4], regs[4] = {0};
	while (scanf("%d%d%d%d", &op[0], &op[1], &op[2], &op[3]) != EOF) {
		op[0] = map[op[0]];
		step(regs, regs, op);
	}
	printf("%d\n", regs[0]);
}
