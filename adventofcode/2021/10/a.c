#define _POSIX_C_SOURCE 200809L
#include <stdlib.h>
#include <stdio.h>

int main(void) {
	char *str = NULL;
	size_t sz = 0;

	char stack[1000];

	int sum = 0;
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

		continue;
bad:
		switch (*--cur) {
			case '>':
				sum += 23940;
			case '}':
				sum += 1140;
			case ']':
				sum += 54;
			case ')':
				sum += 3;
		}
	}

	printf("%d\n", sum);
	free(str);
}
