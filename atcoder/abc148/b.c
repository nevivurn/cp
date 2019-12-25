#include <stdio.h>

int main(void) {
	int n;
	scanf("%d", &n);

	char str[2][101];
	scanf("%s%s", str[0], str[1]);

	for (int i = 0; i < n; i++)
		printf("%c%c", str[0][i], str[1][i]);
	putchar('\n');
}
