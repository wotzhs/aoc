#include <bits/stdc++.h>

using namespace std;

typedef vector<vector<char>> vvc;

bool dfs (int r, int c, int x, int y, vvc &grid) {
	if (
		r + x >= 0 && 
		c + y >= 0 &&
		r + x < grid.size() &&
		c + y < grid[0].size() 
	) {
		if (grid[r+x][c+y] == 'L') return false;
		else if (grid[r+x][c+y] == '#') return true;
		else {
			if (x>0) ++x;
			if (x<0) --x;
			if (y>0) ++y;
			if (y<0) --y;

			if (
				r + x >= 0 && 
				c + y >= 0 &&
				r + x < grid.size() &&
				c + y < grid[0].size()
			) return dfs(r, c, x, y, grid);
		}
	}

	return false;
}

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
					for (int j=0; j<cross.size()-1; j++) {
						if (dfs(curr.second.first, curr.second.second, cross[i], cross[i+1], grid)) {
							occupied++; 
							break;
						}
					}
					for (int j=0; j<cross.size()-1; j++) {
						if (dfs(curr.second.first, curr.second.second, diags[i], diags[i+1], grid)) {
							occupied++; 
							break;
						}
					}
				}

				if (occupied >= 5) tmpQ.emplace(make_pair('L', make_pair(curr.second.first, curr.second.second)));
			}

			if (curr.first == 'L') {
				bool empty=true;
				for (int i=0; i<cross.size()-1; i++) {
					for (int j=0; j<cross.size()-1; j++) {
						if (dfs(curr.second.first, curr.second.second, cross[i], cross[i+1], grid)) {
							empty = false;
							break;
						}
					}
					for (int j=0; j<cross.size()-1; j++) {
						if (dfs(curr.second.first, curr.second.second, diags[i], diags[i+1], grid)) {
							empty = false;
							break;
						}
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
