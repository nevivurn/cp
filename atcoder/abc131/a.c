#include <stdio.h>

int main(void) {
	int last = -1;
	for (int i = 0; i < 4; i++) {
		int cur;
		scanf("%1d", &cur);
		if (last == cur) {
			puts("Bad");
			return 0;
		}
		last = cur;
	}
	puts("Good");
}
