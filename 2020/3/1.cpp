#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string line;
	int ans=0, last=3, width;

	cin >> line;
	width = line.size();

	while(cin >> line) {
		if (line[last] == '#') ans++;
		last += 3;
		last %= width;
	}

	cout << ans << "\n";
}
