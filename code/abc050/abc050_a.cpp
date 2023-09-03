#include <stdio.h>
#include <string.h>

int main() {
	int a, b;
	char op[3];
	scanf("%d %s %d", &a, &op, &b);
	if (strcmp(op, "-") == 0) {
		int c = a - b;
		printf("%d", c);
		return 0;
	}
	else {
		int c = a + b;
		printf("%d", c);
		return 0;
	}
	return 0;
}