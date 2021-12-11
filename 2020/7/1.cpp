#include <bits/stdc++.h>

using namespace std;

void dfs(unordered_map<string, vector<string>> radj, unordered_map<string, bool> &visited, string bag, int &ans) {
	if (!visited[bag] && radj.count(bag)) {
		ans++;
		visited[bag] = true;
		for (string color: radj[bag]) {
			dfs(radj, visited, color, ans);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string line, word;
	int ans=0;
	unordered_map<string, vector<string>> radj;
	unordered_map<string, bool> visited;

	while(getline(cin, line)) {
		istringstream ss(line);
		string outer, inner;
		bool foundOuter=false;

		while (ss >> word) {
			if (word == "contain") {
				foundOuter = true;
				continue;
			} 

			if (!foundOuter && word.substr(0,3) != "bag") {
				outer += word;
			}

			if (foundOuter) {
				if (word.size() == 1) continue;
				if (word.substr(0, 3) == "bag") {
					if (inner != "noother") {
						radj[inner].emplace_back(outer);
					} 
					if (!radj.count(outer)) radj[outer] = {};

					inner = "";
					continue;
				} 
				inner += word;
			}
		}
	}

	for (string bag: radj["shinygold"]) {
		dfs(radj, visited, bag, ans);
	}

	cout << ans << "\n";
}
