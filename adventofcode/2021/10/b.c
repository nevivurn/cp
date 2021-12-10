#define _POSIX_C_SOURCE 200809L
#include <stdlib.h>
#include <stdio.h>

int long_cmp(const void *a, const void *b) {
	long long int d = *(const long long int * ) a - *(const long long int *) b;
	return d ? d / llabs(d) : 0;
}

int main(void) {
	char *str = NULL;
	size_t sz = 0;

	char stack[1000];

	long long int scores[1000];
	size_t score_len = 0;

	while (getline(&str, &sz, stdin) != -1) {
		char *cur = str;
		if (*cur == '\n' || *cur == '\r' || *cur == '\0')
			continue;

		int head = 0;
		while (*cur != '\0') {
			char c = *cur++;
			switch (c) {
			case '(':
			case '[':
			case '{':
			case '<':
				stack[head++] = c;
				break;

			case ')':
				c++; // lmao
			case ']':
			case '}':
			case '>':
				if (head && stack[head-1] == c-2)
					head--;
				else
					goto bad;
				break;
			}
		}

		if (!head)
			continue;

		long long int score = 0;
		while (head) {
			score *= 5;
			switch (stack[--head]) {
			case '<':
				score++;
			case '{':
				score++;
			case '[':
				score++;
			case '(':
				score++;
			}
		}
		scores[score_len++] = score;

bad:
		continue;
	}

	qsort(scores, score_len, sizeof scores[0], long_cmp);
	printf("%lld\n", scores[score_len/2]);
	free(str);
}
