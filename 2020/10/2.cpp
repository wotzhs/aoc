#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int input, ones=0, threes=1;
	vector<int> adapters;

	while(cin >> input) {
		adapters.emplace_back(input);
	}
	sort(adapters.begin(), adapters.end());
	adapters.emplace_back(*adapters.end()+3);
	int ways[adapters.size()][adapters.size()];

	memset(ways, adapters.size(), 0);

	for (int i=0; i<adapters.size(); i++) {
		for (int j=i; i<adapters.size(); i++) {
			if ()
		}
	}

	cout << ans + 1 << "\n";
}
