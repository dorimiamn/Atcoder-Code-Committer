#include <stdio.h>

int main(){
	int a, b, c, x=0;
	scanf("%d", &a);
	scanf("%d", &b);
	scanf("%d", &c);
	scanf("%d", &x);
	int A = 500;
	int B = 100;
	int C = 50;
	int count = 0;
	for (int t = 0; t <= a; t++) {
		for (int r = 0; r <= b; r++) {
			for (int e = 0; e <= c; e++) {
				if (x - (A*t + B * r + C * e) == 0 ) {
					count++;
				}
			}
		}
	}
	printf("\n%d", count);
    return 0;
}