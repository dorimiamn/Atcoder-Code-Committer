#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N, M, l = 0, r = 100000;
	cin >> N >> M;
	int L[100000], R[100000];
	for (int i = 0; i < M; i++) {
		cin >> L[i] >> R[i];
	}
	for (int i = 0; i < M; i++) {
		if (l < L[i]) l = L[i];
		if (r > R[i]) r = R[i];
	}
	int ans = r - l + 1;
	if (ans < 0){
		cout << "0" << endl;
	}
	else {
		cout << ans << endl;
	}
	return 0;
}