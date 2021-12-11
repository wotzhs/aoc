#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string op;
	char sign;
	int ans=0, x;
	vector<pair<string, int>> v;

	while(cin >> op >> sign >> x) { 
		v.emplace_back(make_pair(op, sign == '-' ? -x : x));
	}

	vector<bool> visited(v.size());

	for (int i=0; i<v.size();) {
		if (visited[i]) break;
		visited[i] = true;

		if(v[i].first == "acc") ans += v[i].second;

		if(v[i].first == "jmp") {
			i = i+v[i].second;
			continue;
		}

		i++;
	}

	cout << ans << "\n";
	return 0;
}
