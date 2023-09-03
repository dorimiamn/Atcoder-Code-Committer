#include <iostream>
#include <string>

using namespace std;

int main() {
	//Aは前二桁、Bは後ろ二桁
	string y = "YYMM", m = "MMYY", ym = "AMBIGUOUS", n = "NA";
	int S, A, B;
	cin >> S;
	A = S / 100;
	B = S - A * 100;
	if (A <= 12 && A != 0) {
		if (B <= 12 && B != 0) {
			cout << ym << endl;
			return 0;
		}
		cout << m << endl;
		return 0;
	}
	if (B <= 12 && B != 0) {
		cout << y << endl;
		return 0;
	}
	cout << n << endl;
	return 0;
}