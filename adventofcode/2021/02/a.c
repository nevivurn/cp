#include <string.h>
#include <stdio.h>

int main(void) {
	char cmd[10];
	int n;

	int x = 0, y = 0;
	while (scanf("%s%d", cmd, &n) == 2) {
		if (!strncmp("forward", cmd, sizeof cmd))
			x += n;
		else if (!strncmp("down", cmd, sizeof cmd))
			y += n;
		else if (!strncmp("up", cmd, sizeof cmd))
			y -= n;
	}

	printf("%d\n", x * y);
}
