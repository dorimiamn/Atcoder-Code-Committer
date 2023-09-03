#include <iostream>
using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	if (b/a >= c) {
		cout << c << endl;
	}
	else if (b/a < c) {
		cout << b / a << endl;
	}
	return 0;
}