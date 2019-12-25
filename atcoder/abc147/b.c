#include <stdio.h>
#include <string.h>

int main(void) {
	char s[101];
	scanf("%s", s);
	size_t len = strlen(s);

	int cnt = 0;
	for (size_t i = 0; i < len/2; i++)
		cnt += s[i] != s[len-1-i];
	printf("%d\n", cnt);
}
