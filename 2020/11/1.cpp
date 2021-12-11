#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int ans;
	string line;
	vector<vector<char>> grid;
	queue<pair<char, pair<int, int>>> q;
	vector<int> cross = {-1,0,1,0,-1}, diags = {-1,1,1,-1,-1};

	while(getline(cin, line)) {
		vector<char> row(line.size());
		for (int i=0; i<line.size(); i++) row[i] = line[i];
		grid.emplace_back(row);
	}

	for (int i=0; i<grid.size(); i++) {
		for (int j=0; j<grid[0].size(); j++) {
			if (grid[i][j] == 'L') q.emplace(make_pair('L', make_pair(i, j)));
		}
	}

	while (q.size()) {
		int n = q.size();
		queue<pair<char, pair<int, int>>> tmpQ;
		for (int x=0; x<n; x++) {
			auto curr = q.front();
			q.pop();

			if (curr.first == '#') {
				int occupied=0;
				for (int i=0; i<cross.size()-1; i++) {
					if (
						curr.second.first + cross[i] >= 0 && 
						curr.second.second + cross[i+1] >= 0 &&
						curr.second.first + cross[i] < grid.size() &&
						curr.second.second + cross[i+1] < grid[0].size() &&
						grid[curr.second.first+cross[i]][curr.second.second+cross[i+1]] == '#'
					) 
						occupied++; 
					if (
						curr.second.first + diags[i] >= 0 && 
						curr.second.second + diags[i+1] >= 0 &&
						curr.second.first + diags[i] < grid.size() &&
						curr.second.second + diags[i+1] < grid[0].size() &&
						grid[curr.second.first+diags[i]][curr.second.second+diags[i+1]] == '#'
					) 
						occupied++;
				}

				if (occupied >= 4) tmpQ.emplace(make_pair('L', make_pair(curr.second.first, curr.second.second)));
			}

			if (curr.first == 'L') {
				bool empty=true;
				for (int i=0; i<cross.size()-1; i++) {
					if (
						curr.second.first + cross[i] >= 0 && 
						curr.second.second + cross[i+1] >= 0 &&
						curr.second.first + cross[i] < grid.size() &&
						curr.second.second + cross[i+1] < grid[0].size() &&
						grid[curr.second.first+cross[i]][curr.second.second+cross[i+1]] == '#'
					) {
						empty = false;
						break;
					}

					if (
						curr.second.first + diags[i] >= 0 && 
						curr.second.second + diags[i+1] >= 0 &&
						curr.second.first + diags[i] < grid.size() &&
						curr.second.second + diags[i+1] < grid[0].size() &&
						grid[curr.second.first+diags[i]][curr.second.second+diags[i+1]] == '#'
					) {

						empty = false;
						break;
					}
				}

				if (empty) tmpQ.emplace(make_pair('#', make_pair(curr.second.first, curr.second.second)));
			}
		}

		while (tmpQ.size()) {
			auto curr = tmpQ.front(); tmpQ.pop();
			grid[curr.second.first][curr.second.second] = curr.first;
			q.emplace(make_pair(curr.first, make_pair(curr.second.first, curr.second.second)));
		}
	}
	
	for (int i=0; i<grid.size(); i++) {
		for (int j=0; j<grid[i].size(); j++) {
			if (grid[i][j] == '#') ans++;
		}
	}

	cout << ans << "\n";
}
