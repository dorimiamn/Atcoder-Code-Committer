#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	vector<int> AT;
	int N, V[20], C[20], T[20], ANS = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> V[i];
	}
	for (int i = 0; i < N; i++) {
		cin >> C[i];
	}
	for (int i = 0; i < N; i++) {
		T[i] = V[i] - C[i];
		if (T[i] >= 0) {
			AT.push_back(T[i]);
		}
	}
	int counter = AT.size();
	for (int i = 0; i < counter; i++) {
		ANS = ANS + AT[i];
	}
	cout << ANS << endl;
	return 0;
}