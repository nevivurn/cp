#include <stdio.h>

int main(void) {
	char s[5];
	scanf("%s", s);

	int same = 0, diff = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (s[i] == s[j]) same++;
			else diff++;
		}
	}

	if (same == 8 && diff == 8) puts("Yes");
	else puts("No");
}
