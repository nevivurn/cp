#include <stdio.h>
#include <stdbool.h>

int main(void) {
	char set[] = "ACGT";

	char s[11];
	scanf("%s", s);

	int cur = 0, max = 0;

	int i = 0;
	while (s[i] != '\0') {
		bool found = false;
		for (int j = 0; j < sizeof(set); j++) {
			if (s[i] == set[j]) {
				found = true;
				break;
			}
		}

		if (found) {
			if (++cur > max) max = cur;
		} else cur = 0;
		i++;
	}

	printf("%d\n", max);
}
