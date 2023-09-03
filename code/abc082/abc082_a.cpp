#include <iostream>
using namespace std;

int main() {
	int a, b;
	cin >> a >> b;
	int ans = a + b;
	if (ans % 2 == 0) {
		ans = ans / 2;
		cout << ans << endl ;
		return 0;
	}
	else {
		ans = ans / 2;
		cout << ans + 1 << endl;
		return 0;
	}
	return 0;
}