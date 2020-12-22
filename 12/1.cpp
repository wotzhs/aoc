#include <bits/stdc++.h>

using namespace std;

const int NORTH = 0;
const int EAST = 1;
const int SOUTH = 2;
const int WEST = 3;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	char input_dir;
	int unit, curr_dir=1;
	pair<int, int> coord;

	while (cin >> input_dir >> unit) {
		if (input_dir == 'F') {
			if (curr_dir == NORTH) coord.second -= unit;
			if (curr_dir == SOUTH) coord.second += unit;
			if (curr_dir == EAST) coord.first += unit;
			if (curr_dir == WEST) coord.first -= unit;
		}

		if (input_dir == 'N') coord.second -= unit;
		if (input_dir == 'S') coord.second += unit;
		if (input_dir == 'E') coord.first += unit;
		if (input_dir == 'W') coord.first -= unit;

		if (unit == 0 || unit == 360) continue;
		if (input_dir == 'L') curr_dir = (curr_dir+(360-unit)/90)%4;
		if (input_dir == 'R') curr_dir = (curr_dir+unit/90)%4;
	}
	cout << abs(coord.first) + abs(coord.second) << "\n";
}
