#include <stdio.h>

int main() {
	int a, b = 1200, c = 2800;
	scanf("%d", &a);
	if (a < b) {
		printf("ABC");
	}
	else if (a>=b && a<c) {
		printf("ARC");
	}
	else {
		printf("AGC");
	}
}