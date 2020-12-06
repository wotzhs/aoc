#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string line;
	int ans=-1;
	set<int> seats;

	while(cin >> line) {
		int rlo=0, rhi=127, clo=0, chi=7, rmid, cmid, seat;
		for (int i=0; i<line.size()-1; i++) {
			char ch = line[i];
			rmid = rlo+(rhi-rlo)/2;
			cmid = clo+(chi-clo)/2;
			if (ch == 'F') rhi = rmid;
			if (ch == 'B') rlo = rmid+1;
			if (ch == 'R') clo = cmid+1;
			if (ch == 'L') chi = cmid;
		}

		if (line[line.size()-1] == 'R') cmid = chi;
		else cmid = clo;

		seat = rmid * 8 + cmid;
		seats.emplace(seat);
		if (seat > ans) ans = seat;
	}

	for (int i=*seats.begin(); i<*seats.end(); i++) {
		if (!seats.count(i)) cout << i << "\n";
	}

	return 1;
}
