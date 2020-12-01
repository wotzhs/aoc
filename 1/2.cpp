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

	for (int i=0; i<nums.size(); i++) {
		for (int j=i+1; j<nums.size(); j++) {
			int diff = 2020-nums[i]-nums[j];
			if (mp.count(diff)) {
				cout << diff * nums[i]* nums[j] << "\n";
				return 0;
			}
		}
	}
	return 1;
}
