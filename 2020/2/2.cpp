#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	string range, target, input;
	int ans=0;

	while(cin >> range >> target >> input) {
		int i=0;
		string mn, mx;

		for (; i<range.size() && range[i]-'0' >= 0 && range[i]-'0' <= 9; i++) {
			mn += range[i];
		}

		i++;

		for (; i<range.size() && range[i]-'0' >= 0 && range[i]-'0' <= 9; i++) {
			mx += range[i];
		}

		bool matched=false;

		if (input[stoi(mn)-1] == target[0]) {
			matched = !matched;
		}

		if (input[stoi(mx)-1] == target[0]) {
			matched = !matched;
		}

		if (matched) {
			ans++;
		}
	}

	cout << ans << "\n";
}
