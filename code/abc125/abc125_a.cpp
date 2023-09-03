#include <iostream>

using namespace std;

int main() {
	int A, B, T, count = 0;
	cin >> A >> B >> T;
	for (int i = 1; i <= T; i++) {
		if (i % A == 0) {
			count = count + B;
		}
	}
	cout << count << endl;
	return 0;
}