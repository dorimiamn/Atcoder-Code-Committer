#include<iostream>
using namespace std;

int main() {
	int a, b, c = 0, d = 0, e = 0;
	cin >> a;
	cin >> b;
	for (int n = 0; n <= 999; n++) {
		c = c + n;
		d = d + e;
		e = n;
		if (d - a == c - b) {
			cout << d - a << endl;
			return 0;
		}
	}
}