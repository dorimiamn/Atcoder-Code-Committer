#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {
	string s, t, u;
	cin >> s;
	int digit = s.size() - 2;
	t = s[0];
	u = to_string(digit);
	t = t + u;
	t = t + s[digit + 1];
	cout << t << endl;
	return 0;
}