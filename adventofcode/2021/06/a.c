#include <stdio.h>
#include <string.h>

#define N 400000

int lista[N], listb[N];
int lena, lenb;

int main(void) {
	int cur;
	while (scanf("%d,", &cur) != EOF)
		lista[lena++] = cur;

	for (int i = 0; i < 80; i++) {
		lenb = 0;
		for (int j = 0; j < lena; j++) {
			switch (lista[j]) {
			case 0:
				listb[lenb++] = 6;
				listb[lenb++] = 8;
				break;
			default:
				listb[lenb++] = lista[j]-1;
				break;
			}
		}
		memcpy(lista, listb, sizeof listb[0] * lenb);
		lena = lenb;
	}

	printf("%d\n", lenb);
}
