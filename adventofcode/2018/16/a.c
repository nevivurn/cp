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

int main(void) {
	int a[4], b[4], c[4], op[4], ans = 0;
	while (1) {
		if(scanf(" Before: [%d,%d,%d,%d]", &a[0], &a[1], &a[2], &a[3]) != 4) break;
		scanf("%d%d%d%d", &op[0], &op[1], &op[2], &op[3]);
		scanf(" After: [%d,%d,%d,%d] ", &b[0], &b[1], &b[2], &b[3]);

		int cnt = 0;
		for (int i = 0; i < 16; i++) {
			op[0] = i;
			step(c, a, op);

			int same = 1;
			for (int j = 0; j < 4; j++) {
				if (b[j] != c[j]) {
					same = 0;
					break;
				}
			}
			if (same) cnt++;
		}
		if (cnt >= 3) ans++;
	}
	printf("%d\n", ans);
}
