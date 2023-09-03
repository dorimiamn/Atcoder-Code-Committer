#include <stdio.h>

int main() {
	int N,sum=0,dig;
	scanf("%d", &N);
	int N2 = N;
	while (N) {
		dig = N % 10;
		sum = sum + dig;
		N = N / 10;
	}
	if (N2%sum == 0) {
		printf("Yes");
	}
	else {
		printf("No");
	}
	return 0;
}