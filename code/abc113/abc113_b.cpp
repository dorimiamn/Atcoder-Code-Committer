#include <iostream>

using namespace std;

int main() {
	float K = 0.006, ans, LL = 0, UL = 0;
	int N, T, A, H[1000], a, ULN = 0 , LLN = 0;
	cin >> N >> T >> A;
	LL = T - 100000 * K;
	UL = 5000;
	for (int i = 0; i < N; i++) {
		cin >> H[i];
	}
	for (int i = 0; i < N; i++) {
		ans = T - H[i] * K;
		if (ans >= A &&UL>ans) {
			UL = ans;
			ULN = i + 1;
		}
		if (ans < A && LL < ans) {
			LL = ans;
			LLN = i + 1;
		}
	}
	if (A < 0) A = -A;
	if (UL < 0)UL = -UL;
	if (LL < 0)LL = -LL;
	if (UL < A) UL = A - UL;
	else UL = UL - A;
	if (LL > A)LL = LL - A;
	else LL = A - LL;
	if (UL >= LL) {
		cout << LLN << endl;
	}
	else {
		cout << ULN << endl;
	}
}