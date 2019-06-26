#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int n;
	scanf("%d", &n);

	int *arr = malloc((n+11) * sizeof *arr);
	arr[0] = 3;
	arr[1] = 7;

	int c = 2;
	int i = 0, j = 1;
	while (c < n+10) {
		int r = arr[i]+arr[j];
		if (r >= 10) arr[c++] = r/10;
		arr[c++] = r%10;
		i = (i + arr[i]+1) % c;
		j = (j + arr[j]+1) % c;
	}

	for (int k = 0; k < 10; k++) {
		printf("%d", arr[k+n]);
	}
	puts("");

	free(arr);
}
