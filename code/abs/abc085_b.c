#include <stdio.h>
#include <stdlib.h>

int compara(const void *a, const void *b) {
	return *(int *)b - *(int *)a;
}

int main()
{
	int x = 0, d[100], b[100], t = 1, result = 0, A = 1;
	scanf("%d", &x);
	for (int o = 0; o < x; o++) {
		scanf("%d", &d[o]);
	}
	qsort(d, x, sizeof(*d), compara);
	for (int o = 0; t < x; o++) {
		if (d[o] > d[t]) {
			result++;
		}
		t++;
	}
	if (x>1) {
		result++;
	}
	else if (x == 1) {
		result = 1;
	}
	printf("%d", result);
    return 0;
}
