#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string op;
	char sign;
	int ans=0, x;
	vector<pair<string, int>> v;
	int lastNop=INT_MIN, lastAcc, lastJmp=INT_MIN;
	bool modded=false;

	while(cin >> op >> sign >> x) { 
		v.emplace_back(make_pair(op, sign == '-' ? -x : x));
	}

	vector<bool> visited(v.size());

	for (int i=0; i<v.size();) {
		if (visited[i]) {
			visited[i] = false;
			if (lastNop != INT_MIN) {
				cout << "backtrack to: " << lastNop << " lastAcc: " << lastAcc << "\n";
				i = lastNop+1;
				ans = lastAcc;
				lastNop = INT_MIN;
				modded = false;
			}

			if (lastJmp != INT_MIN) {
				cout << "backtrack to last jmp: " << lastJmp << " lastAcc: " << lastAcc << "\n";
				i = lastJmp;
				/* cout << "jump to: " << i << "\n"; */
				ans = lastAcc;
				lastJmp = INT_MIN;
				modded = false;
			}

			continue;
		}

		visited[i] = true;

		if(v[i].first == "acc") {
			/* cout << "acc += " << v[i].second << " ans before: " << ans << "\n"; */
			ans += v[i].second;
		}

		if(v[i].first == "nop") {
			if (lastNop == INT_MIN) {
				lastNop = i;
				lastAcc = ans;
			}

			if (!modded) {
				i = i+v[i].second;
				modded = true;
			}
			continue;
		}

		if(v[i].first == "jmp") {
			if (lastJmp == INT_MIN) {
				lastJmp = i+v[i].second;
				lastAcc = ans;
			}

			if (!modded) {
				i++;
				modded = true;
			}
			else i = i+v[i].second;
			
			continue;
		}
		
		i++;
	}

	cout << ans << "\n";
	return 0;
}
