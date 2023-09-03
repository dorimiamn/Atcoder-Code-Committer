#include <stdio.h>

int main() {
	int l;
	int N;
	scanf("%d", &N);
	if (N % 2 == 0) {
		printf("%d", N);
	}
	else if (N % 2 == 1) {
		l = N * 2;
		printf("%d", l);
	}
	return 0;
}