#include <stdio.h>

int main()
{
	int N = 0;
	scanf("%d", &N);
	if (N <= 999) {
		printf("ABC");
		return 0;
	}
	else if (N >= 1000) {
		printf("ABD");
		return 0;
	}
    return 0;
}

