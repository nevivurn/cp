#include <stdio.h>

int main(void) {
	int n;
	scanf("%d", &n);

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		int c;
		scanf("%d", &c);
		if (c == cnt+1)
			cnt++;
	}

	if (!cnt)
		puts("-1");
	else
		printf("%d\n", n-cnt);
}
