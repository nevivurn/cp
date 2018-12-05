#include <stdio.h>
#include <stdlib.h>

int main(void) {
	char *a, *b;
	a = malloc(60000);
	b = malloc(60000);

	fgets(a, 60000, stdin);

	int cnt = 1;
	while (cnt) {
		cnt = 0;
		
		int i = 0, j = 0;
		while (a[i+1] != '\0') {
			if (a[i]-a[i+1] == 32 || a[i+1]-a[i] == 32) {
				i++;
				cnt++;
			} else {
				b[j++] = a[i];
			}
			i++;
		}
		b[j++] = a[i] == '\n' ? '\0' : a[i];
		b[j] = '\0';

		char *tmp = a;
		a = b;
		b = tmp;
	}

	fputs(a, stdout);

	free(a);
	free(b);
}
