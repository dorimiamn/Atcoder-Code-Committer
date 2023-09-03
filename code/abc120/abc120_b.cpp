#include <iostream>
using namespace std;

int main() {
	int a, b, k,max,min,count=0;
	cin >> a >> b >> k;
	if (a < b) {
		max = b;
		min = a;
	}
	else {
		max = a;
		min = b;
	}
	for (int loop = min; 0< loop; loop--) {
		if (a%loop == 0 && b%loop == 0) {
			count++;
			if (count == k) {
				cout << loop << endl;
			}
		}
	}
}
//K番目に「大きい」もの、小さいもの順ではない