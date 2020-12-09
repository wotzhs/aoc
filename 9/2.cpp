#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int ans, tmp=0, input, i=25, l=0, r=0, mn=INT_MAX, mx=INT_MIN;
	vector<int> numbers;
	unordered_map<int, bool> mp;

	while(cin >>input) {
		numbers.emplace_back(input);
	}

	for (; i<numbers.size(); i++) {
		bool matched = false;

		for (int j=i-25; j<i && !matched; j++) {
			mp[numbers[j]] = true;
			matched = mp.count(numbers[i] - numbers[j]);
		}

		mp.clear();

		if (!matched) {
			ans = numbers[i];
			break;
		}
	}

	while (tmp != ans && l<i) {
		if (tmp < ans) tmp += numbers[r++]; 
		else tmp -= numbers[l++];
	}

	while (l<r) {
		if (numbers[l] < mn) mn = numbers[l];
		if (numbers[l] > mx) mx = numbers[l];
		l++;
	}

	cout << mn + mx << "\n";

	return 0;
}
