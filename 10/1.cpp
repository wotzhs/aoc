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
	if (adapters[0]-0 == 1) ones++;
	if (adapters[0]-0 == 3) threes++;

	for (int i=1; i<adapters.size()-1; i++) {
		if (adapters[i+1]-adapters[i] == 1) ones++;
		if (adapters[i+1]-adapters[i] == 3) threes++;
	}

	if (adapters[adapters.size()-1]-adapters[adapters.size()-2] == 1) ones++;
	if (adapters[adapters.size()-1]-adapters[adapters.size()-2] == 3) threes++;

	cout << ones * threes << "\n";
}
