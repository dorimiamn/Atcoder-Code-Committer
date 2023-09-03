#include <iostream>
using namespace std;

int main() {
	int a = 0, b = 0 , sum, product, reminder;
	cin >> a >> b;
	sum = a + b;
	product = a * b;
	reminder = a - b;
	if (sum > product) {
		if (sum > reminder) {
			cout << sum << endl;
		}
		else {
			cout << reminder << endl;
		}
	}
	else if (product > reminder) {
		cout << product << endl;
	}
	else{
		cout << reminder << endl;
	}
	return 0;
}