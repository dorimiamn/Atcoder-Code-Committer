#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	int A, B, C;
	cin >> A >> B >> C;
	if (A < B) {
		int i = A;
		A = B;
		B = i;
	}
	if (A>C && C>B) {
		cout << "Yes" << endl;
	}
	else cout << "No" << endl;
	return 0;
}