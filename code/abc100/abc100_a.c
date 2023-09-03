#include <stdio.h>

int main() {
	int a, b;
	scanf("%d%d",&a, &b);
	if (a >= 9 || b >= 9) {
		printf(":(");
		return 0;
	}
	else {
		printf("Yay!");
		return 0;
	}
	return 0;
}