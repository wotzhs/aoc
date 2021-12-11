#include <bits/stdc++.h>

using namespace std;

int dfs(unordered_map<string, vector<pair<string, int>>> adj, pair<string, int> p) {
	int sum=0;
	if (adj.count(p.first)) {
		for (pair<string, int> innerP: adj[p.first]) {
			sum += dfs(adj, innerP);
		}
	}
	return p.second + sum*p.second;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string line, word;
	int ans=0, unit;
	unordered_map<string, vector<pair<string, int>>> adj;

	while(getline(cin, line)) {
		istringstream ss(line);
		string outer, inner;
		bool foundOuter=false;

		while (ss >> word) {
			if (word == "contain") {
				foundOuter = true;
				adj[outer] = {};
				continue;
			} 

			if (!foundOuter && word.substr(0,3) != "bag") {
				outer += word;
			}

			if (foundOuter) {
				if (word.size() == 1) {
					unit = stoi(word);
					continue;
				}
				if (word.substr(0, 3) == "bag") {
					if (inner != "noother") {
						adj[outer].emplace_back(make_pair(inner, unit));
					} 

					inner = "";
					unit=0;
					continue;
				} 
				inner += word;
			}
		}
	}

	for (pair<string, int> bag: adj["shinygold"]) {
		ans += dfs(adj, bag);
	}

	cout << ans << "\n";
}
