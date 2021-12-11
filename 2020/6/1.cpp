#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string line;
	int ans=0;

	unordered_map<char, int> responses;
	while(cin) {
		getline(cin, line);
		for (char ch: line) {
			responses[ch]++;
		}

		if (line.size() < 1) {
			ans += responses.size();
			responses.clear();
		}
	}

	cout << ans << "\n";
}
