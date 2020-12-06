#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string line;
	int ans=0, line_number=0;
	vector<int> responses(26, 0);

	while(getline(cin, line)) {
		for (char ch: line) {
			responses[ch-'a']++;
		}

		if (line.size() > 0) {
			line_number++;
		}

		if (line.size() < 1) {
			for (int i: responses) {
				if (i != 0 && i == line_number) ans++;
			}
			
			vector<int>(26, 0).swap(responses);
			line_number = 0;
		}
	}

	for (int i: responses) {
		if (i != 0 && i == line_number) ans++;
	}

	cout << ans << "\n";
}
