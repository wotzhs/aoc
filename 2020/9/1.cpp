#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int input;
	vector<int> numbers;
	unordered_map<int, bool> mp;

	while(cin >>input) {
		numbers.emplace_back(input);
	}

	for (int i=25; i<numbers.size(); i++) {
		bool matched = false;

		for (int j=i-25; j<i && !matched; j++) {
			mp[numbers[j]] = true;
			matched = mp.count(numbers[i] - numbers[j]);
		}

		mp.clear();

		if (!matched) {
			cout << numbers[i] << "\n";
			break;
		}
	}
	return 0;
}
