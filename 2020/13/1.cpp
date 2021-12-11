#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string busId;
	int ans, timestamp, timestamp2;
	vector<int> busIds;

	cin >> timestamp;
	timestamp2 = timestamp;
	getline(cin, busId); // remove \n from first line

	while(getline(cin, busId, ',')) {
		if (busId != "x") busIds.emplace_back(stoi(busId));
	}

	while(++timestamp2) {
		bool found;
		for (int busId: busIds) {
			if (timestamp2 % busId == 0) {
				cout << (timestamp2 - timestamp) * busId << "\n";
				found = true;
				break;
			}
		}
		if (found) break;
	}
	return 0;
}
