#include <bits/stdc++.h>

using namespace std;

int main() {
	vector<int> nums;
	unordered_map<int, bool> mp;
	string line;
	stringstream ss;
	int x;

	while(getline(cin, line)) {
		ss << line;
		ss >> x;
		nums.push_back(x);
		mp[x] = true;
		stringstream().swap(ss);
	}

	for (int i: nums) {
		int diff = 2020-i;
		if (mp.count(diff)) {
			cout << diff * i << "\n";
			return 0;
		}
	}
	return 1;
}
