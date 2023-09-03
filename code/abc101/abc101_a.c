#include <stdio.h>

int main() {
	char A[10];
	int result = 0;
	scanf("%s", &A);
	for (int a = 0; a < 4; a++) {
		if ('-' == A[a]) {
			result = result - 1;
		}
		else if ('+' == A[a]) {
			result = result+1;
		}
	}
	printf("%d", result);
	return 0;
}