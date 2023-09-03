#include <iostream>
using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b;
	if (a < b) {
		a = b + a;
		b = a - b;
		a = a - b;
	}
	if (a < b + 2) {
		c = a + b;
		cout << c << endl;
		return 0;
	}
	else {
		c = a + a - 1;
		cout << c << endl;
		return 0;
	}
	return 0;
}