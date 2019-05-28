#include <stdio.h>

int main(void) {
	char bases[] = "ACGT";
	int c = getchar();

	int i = 0;
	while (bases[i] != c) i++;
	putchar(bases[3-i]);
	putchar('\n');
}
