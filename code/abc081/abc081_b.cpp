#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<int> a(200);
	int N, counter = 0;
	bool f = true;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a[i];
		if (a[i] % 2 != 0) {
			f = false;
		}
	}
	while (f==true) {
		for (int i = 0; i < N; i++) {
			a[i] = a[i] / 2;
			if (a[i] % 2 == 1) {
				f = false;
			}
		}
		counter++;
	}
	cout << counter << endl;
}