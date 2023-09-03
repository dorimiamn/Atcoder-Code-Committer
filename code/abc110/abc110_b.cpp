#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	int N, M, X, Y, x = -100, y = 100, k = 0;
	cin >> N >> M >> X >> Y;
	for (int i = 0; i < N; i++) {
		cin >> k;
		if (x < k) {
			x = k;
		}
	}
	for (int i = 0; i < M; i++) {
		cin >> k;
		if (y >= k) {
			y = k;
		}
	}
	for (int i = X + 1; i <= Y; i++) {
		if (x < i && y >= i) {
			cout << "No War" << endl;
			return 0;
		}
	}
	cout << "War" << endl;
}