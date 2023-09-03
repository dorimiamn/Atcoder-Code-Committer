#include<stdio.h>
#include<stdlib.h>
int main() {
	int s=0;
	char b[]= "エラー";
	int a = 0;
	scanf("%d", &s);
	if (s == 111 || s == 0) {
		if (s == 111) {
			a = 3;
		}
		else {
			a = 0;
		}
	}
	else if (s == 110 || s == 101 || s == 11) {
		a = 2;
	}
	else if (s == 100 || s == 10 || s == 1) {
		a = 1;
	}
	else {
		printf("%s", b);
	}
	printf("%d", a);
	return 0;
}