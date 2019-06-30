#include <stdio.h>

int main(void) {
	int n;
	scanf("%d", &n);

	int a[3], cnt = 0;
	for (int i = 0; i < n; i++) {
		a[0] = a[1];
		a[1] = a[2];
		scanf("%d", &a[2]);

		if (i > 1) {
			if ((a[0] < a[1] && a[1] < a[2]) ||
				(a[0] > a[1] && a[1] > a[2])) cnt++;
		}
	}

	printf("%d\n", cnt);
}
