#include <stdio.h>

int main(void) {
	int cnt = 0;

	int arr[4];
	scanf("%d%d%d", &arr[0], &arr[1], &arr[2]);
	while (scanf("%d", &arr[3]) == 1) {
		cnt += arr[0] < arr[3];
		arr[0] = arr[1];
		arr[1] = arr[2];
		arr[2] = arr[3];
	}

	printf("%d\n", cnt);
}
