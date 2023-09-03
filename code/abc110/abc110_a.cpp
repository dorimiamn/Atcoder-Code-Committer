#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	vector<int> Array(3);
	cin >> Array[0] >> Array[1] >> Array[2];
	sort(Array.begin(), Array.end());
	int ans = Array[0] + Array[1] + Array[2] * 10;
	cout << ans << endl;
}