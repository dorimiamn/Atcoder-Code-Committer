#include <stdio.h>

int desion(int count1,int count2, int b[200],int n) {
	count2 = 0;
	for (int c = 1; c <= n; c++) {
		if (b[c] % 2 == 1) {
			printf("%d", count1);
			return 0;
		}
		else {
			b[c] = b[c] / 2;
			count2++;
		}
	}
	if (count2 == n) {
		count1++;
		desion(count1, count2, b, n);
	}
	else {
		printf("%d", count1);
	}
	return 0;
}

int main(){
	int n = 0, b[200], c, i = 0;
	int count1 = 0, count2 = 0;
	scanf("%d", &n);
	for (c = 1; c <= n; c++) {
		scanf("%d", &i);
		b[c] = i;
	}
	desion(count1,count2,b,n);
    return 0;
}