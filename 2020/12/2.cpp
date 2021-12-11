#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	char input_dir;
	int unit;
	pair<int, int> ship; // e/w, n/s
	pair<int, int> waypoint = make_pair(10, -1); // e/w, n/s

	while (cin >> input_dir >> unit) {
		if (input_dir == 'F') {
			ship.first += waypoint.first * unit;
			ship.second += waypoint.second * unit;
			continue;
		}

		if (input_dir == 'N') waypoint.second -= unit;
		if (input_dir == 'S') waypoint.second += unit;
		if (input_dir == 'E') waypoint.first += unit;
		if (input_dir == 'W') waypoint.first -= unit;

		if (unit == 90) {
			swap(waypoint.first, waypoint.second);
			if (input_dir == 'L') waypoint.second *= -1;
			if (input_dir == 'R') waypoint.first *= -1; 
		}

		if (unit == 180) {
			waypoint.first *= -1;
			waypoint.second *= -1;
		}

		if (unit == 270) {
			swap(waypoint.first, waypoint.second);
			if (input_dir == 'L') waypoint.first *= -1;
			if (input_dir == 'R') waypoint.second *= -1;
		}
	}

	cout << abs(ship.first) + abs(ship.second) << "\n";
}
