#include <iostream>

using namespace std;

int main() {
	int N, B, res = 0, L;
	cin >> N;
	for (int i = 0; i <= 6; i++) {
		B = 1;
		L = 0;
		while ( L < i) {
			B = B * 2;
			L++;
		}
		if (N >= B) {
			res = B;
		}
		else {
			break;
		}
	}
	cout << res << endl;
	return 0;
}