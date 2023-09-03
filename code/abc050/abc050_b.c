#include <stdio.h>

int add(int a[100], int b) {
	int all = 0;
	for (int c = 0; c < b; c++) {
		all = a[c] + all;
	}
	return all;
}

int main() {
	int N;
	int T[100];
	int M;
	int TM[100];
	int P[100];
	int X[100];
	scanf("%d", &N);
	for (int a=0; a < N; a++) {
		scanf("%d", &T[a]);
	}
	int all = add(T, N);
	scanf("%d", &M);
	for (int a=0; a < M; a++) {
		scanf("%d %d", &P[a], &X[a]);
	}
	for (int a = 0; a < M; a++) {
		int key = P[a] - 1;
		int sum = X[a]-T[key];
		int num = all + sum;
		printf("%d\n", num);
	}
	return 0;
}