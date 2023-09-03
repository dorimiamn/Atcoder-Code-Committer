#include <iostream>
#include <string>

using namespace std;

int main() {
	string s;
	cin >> s;
	s.erase(s.begin() + 3);
	s.insert(s.begin() + 3, '8');
	cout << s << endl;
	return 0;
}