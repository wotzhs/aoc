#include <bits/stdc++.h>

using namespace std;

int main() {
	int h=0, d=0, unit;
	string direction;

	while(cin >> direction >> unit) {
		if (direction == "forward") h += unit;
		if (direction == "down") d += unit;
		if (direction == "up") d -= unit;
	}

	cout << "ans: " << h * d << "\n";

	return 0;
}
