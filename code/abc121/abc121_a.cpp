#include <iostream>

using namespace std;

int main() {
	int H, W, h, w;
	cin >> H >> W >> h >> w;
	int minuscells = h * W + w * H - w * h;
	int cells = H * W-minuscells;
	cout << cells << endl;
}