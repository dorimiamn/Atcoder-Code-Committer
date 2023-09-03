#include<iostream>
using namespace std;

int power(int a) {
	int result = 1;
	for (int b = 0; b < a; b++) {
		result = result * 100;
	}
	return result;
}

int main() {
	int D, N, result,total;
	cin >> D;
	cin >> N;
	if (D == 0) {
		if (N == 100) {
			cout << N + 1 << endl;
			return 0;
		}
		cout << N << endl;
		return 0;
	}
	else {
		if (N == 100) {
			result = power(D);
			total = result * N + result;
			cout << total << endl;
			return 0;
		}
		result = power(D)*N;
		cout << result << endl;
		return 0;
	}
}
