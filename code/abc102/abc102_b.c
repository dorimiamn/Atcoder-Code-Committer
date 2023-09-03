#include <stdio.h>
#include <stdlib.h>

int compara(const void *a, const void *b) {
	return *(int *)a - *(int *)b;
}

int main() {
	int N,d=1000000000,e=0;
	int a[100];
	scanf("%d", &N);
	for (int n = 0; n < N; n++) {
		scanf("%d", &a[n]);
		if (e < a[n]) {
			e = a[n];
		}
		if (d > a[n]) {
			d = a[n];
		}
	}
	int add = e - d;
	printf("%d", add);
}