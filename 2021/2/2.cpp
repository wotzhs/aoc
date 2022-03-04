#include <bits/stdc++.h>

using namespace std;

int main() {
	int h=0, d=0, a=0, unit;
	string direction;

	while(cin >> direction >> unit) {
		if (direction == "forward") {
			h += unit;
			d += a*unit;
		}

		if (direction == "down") a += unit;
		if (direction == "up") a -= unit;
	}

	cout << "ans: " << h * d << "\n";

	return 0;
}
