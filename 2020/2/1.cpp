#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	string range, target, input;
	int ans=0;

	while(cin >> range >> target >> input) {
		int tmp=0, i=0;
		string mn, mx;

		for (; i<range.size() && range[i]-'0' >= 0 && range[i]-'0' <= 9; i++) {
			mn += range[i];
		}

		i++;

		for (; i<range.size() && range[i]-'0' >= 0 && range[i]-'0' <= 9; i++) {
			mx += range[i];
		}

		for (char ch: input) {
			if (ch == target[0]) {
				tmp++;
			}
		}

		if (tmp >= stoi(mn) && tmp <= stoi(mx)) {
			ans++;
		}
	}

	cout << ans << "\n";
}
