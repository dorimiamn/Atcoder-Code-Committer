#include<iostream>
using namespace std;

int main() {
	int a,b;
	scanf("%d%d", &a,&b);
	if (a > 8 || b > 8) {
		printf(":(");
		return 0;
	}
	else {
		printf("Yay!");
		return 0;
	}
}