#include <stdio.h>

int main(void) {
	int cnt = 0;

	int prev, cur;
	scanf("%d", &prev);
	while (scanf("%d", &cur) == 1) {
		cnt += prev < cur;
		prev = cur;
	}

	printf("%d\n", cnt);
}
