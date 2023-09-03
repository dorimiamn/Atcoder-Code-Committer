#include <iostream>

using namespace std;

int main() {
	int N, K;
	char S[51];
	cin >> N >> K >> S;
	K--;
	if (S[K] == 'A') {
		S[K] = 'a';
	}
	else if (S[K] == 'B') {
		S[K] = 'b';
	}
	else if (S[K] == 'C') {
		S[K] = 'c';
	}
	cout << S << endl;
	return 0;
}