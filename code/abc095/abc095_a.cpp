#include <iostream>
#include<string>

using namespace std;

int main() {
	string s;
	cin >> s;
	int counter = 0;
	if (s[0] == 'o')counter++;
	if (s[1] == 'o')counter++;
	if (s[2] == 'o')counter++;
	cout << 700 + counter * 100 << endl;
	return 0;
}