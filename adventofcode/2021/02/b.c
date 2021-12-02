#include <string.h>
#include <stdio.h>

int main(void) {
	char cmd[10];
	int n;

	int x = 0, y = 0, a = 0;
	while (scanf("%s%d", cmd, &n) == 2) {
		if (!strncmp("forward", cmd, sizeof cmd)) {
			x += n;
			y += a*n;
		} else if (!strncmp("down", cmd, sizeof cmd))
			a += n;
		else if (!strncmp("up", cmd, sizeof cmd))
			a -= n;
	}

	printf("%d\n", x * y);
}
