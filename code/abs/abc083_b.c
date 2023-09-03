#include <stdio.h>

int add(int a,int b,int c,int d) {
	int addnum = a + b + c + d;
	return addnum;
}
int originadd(int a, int b, int c, int d) {
	int originadd = a * 1000 + b * 100 + c * 10 + d;
	return originadd;
}

int main(){
	int a=0, b=0, n=0,i=0,o=0,y=0,u=0,all=0;
	scanf("%d %d %d", &n, &a, &b);
	if (n == 10000) {
		if (a == 1) {
			all = all + 10000;
		}
			for (o = 0; o <= 9; o++) {
				for (i = 0; i <= 9; i++) {
					for (u = 0; u <= 9; u++) {
						for (y = 0; y <= 9; y++) {
							int x = add(o, i, u, y);
							if (x >= a && x <= b) {
								int X = originadd(o, i, u, y);
								all = all + X;
							}
						}
					}
				}
			}
		}
	else if (n <= 9999 && n >= 1000) {
		for (o = 0; o <= 9; o++) {
			for (i = 0; i <= 9; i++) {
				for (u = 0; u <= 9; u++) {
					for (y = 0; y <= 9; y++) {
						int x = add(o, i, u, y);
						if (o * 1000 + i * 100 + u * 10 + y > n) {
							break;
						}else if (x >= a && x <= b) {
							int X = originadd(o, i, u, y);
							all = all + X;
						}
					}
				}
			}
		}
	}
	else if (n <= 999 && n >= 100) {
		o = 0;
		for (i = 0; i<= 9; i++) {
			for (u = 0; u <= 9; u++) {
				for (y = 0; y <= 9; y++) {
					int x = add(o, i, u, y);
					if (i * 100 + u * 10 + y > n ) {
						break;
					}else if (x >= a && x <= b) {
						int X = originadd(o, i, u, y);
						all = all + X;
					}
				}
			}
		}
	}
	else if (n <= 99 && n >= 10) {
		o = 0, i = 0;
		for (u = 0; u <= 9; u++) {
			for (y = 0; y <= 9; y++) {
				int x = add(o, i, u, y);
				if (u * 10 + y > n) {
					break;
				}
				else if (x >= a && x <= b) {
					int X = originadd(o, i, u, y);
					all = all + X;
				}
			}
		}
	}
	else if (n <= 9 && n >= 1) {
		o = 0, i = 0, u = 0;
		for (y = 0; y <= n; y++) {
			int x = add(o, i, u, y);
			if (x >= a && x <= b) {
				int X = originadd(o, i, u, y);
				all = all + X;
			}
		}
	}
	printf("%d", all);
    return 0;
}