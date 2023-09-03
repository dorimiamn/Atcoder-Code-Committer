#include <stdio.h>

int main()
{
	int N = 0, X = 0,key=0,h=0,i=0,j=0;
	scanf("%d %d", &N, &X);
	for (h = 0; h <= N; h++) {
		for (i = 0; i <= N; i++) {
			j = N - h - i;
			if (i >= 0 && h >= 0 && j >= 0) {
				if (1000 * i + 5000 * h + j * 10000 == X) {
					printf("%d %d %d", j, h, i);
					return 0;
				}
			}
		}
	}
	printf("%d %d %d", -1, -1, -1);
    return 0;
}