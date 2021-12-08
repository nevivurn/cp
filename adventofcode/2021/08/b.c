#define _POSIX_C_SOURCE 200809L
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

unsigned int to_bits(char *str) {
	unsigned int cur = 0u;
	while (*str != '\0')
		cur |= 1<<(*str++ - 'a');
	return cur;
}

int to_digit(unsigned int *out, unsigned int v) {
	for (int i = 0; i < 10; i++)
		if (out[i] == v)
			return i;
	return -1;
}

void solve(unsigned int *out, unsigned int *sigs) {
	unsigned int fives[3], sixes[3];
	size_t five_len = 0, six_len = 0;
	for (size_t i = 0; i < 10; i++)
		switch (__builtin_popcount(sigs[i])) {
		case 2:
			out[1] = sigs[i];
			break;
		case 3:
			out[7] = sigs[i];
			break;
		case 4:
			out[4] = sigs[i];
			break;
		case 7:
			out[8] = sigs[i];
			break;
		case 5:
			fives[five_len++] = sigs[i];
			break;
		case 6:
			sixes[six_len++] = sigs[i];
			break;
		}

	for (size_t i = 0; i < 3; i++)
		if ((sixes[i] & out[4]) == out[4])
			out[9] = sixes[i];
		else if ((sixes[i] & out[1]) == out[1])
			out[0] = sixes[i];
		else
			out[6] = sixes[i];

	for (size_t i = 0; i < 3; i++)
		if ((fives[i] & out[1]) == out[1])
			out[3] = fives[i];
		else if ((fives[i] & out[6]) == fives[i])
			out[5] = fives[i];
		else
			out[2] = fives[i];
}

int main(void) {
	char *line = NULL;
	size_t sz = 0;

	int sum = 0;
	while (getline(&line, &sz, stdin) != -1 && line[0] != '\n') {
		unsigned int sigs[10], solved[10];
		size_t len = 0;

		char *cur = line, *tok;
		while ((tok = strtok(cur, " ")) != NULL && tok[0] != '|') {
			cur = NULL;
			sigs[len++] = to_bits(tok);
		}

		solve(solved, sigs);

		int acc = 0;
		while ((tok = strtok(NULL, " \n")) != NULL && tok[0] != '\n')
			acc = acc * 10 + to_digit(solved, to_bits(tok));
		sum += acc;
	}

	printf("%d\n", sum);

	free(line);
}
