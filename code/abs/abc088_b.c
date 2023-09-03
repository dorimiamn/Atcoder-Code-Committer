#include <stdio.h>
#include <stdlib.h>

int asc(const void *a, const void *b) {
	return *(int *)b - *(int *)a;
}

int main()
{
	int B=0, A=0;
	int n = 0, i[100];
	scanf("%d", &n);
	int x = n - 1;
	for (int a = 0; a < n; a++) {
		scanf("%d", &i[a]);
	}
	qsort(i,n, sizeof(int), asc);
	for (int a = 0; a < n; a++) {
		if (a%2==0) {
			A = A + i[a];
		}
		else if (a % 2 ==1 ) {
			B = B + i[a];
		}
	}
	int result = A - B;
	printf("%d", result);
    return 0;
}