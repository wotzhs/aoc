#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string line, key;
	int ans=0;
	unordered_map<string, bool> fields;

	const string required[] = {"byr", "iyr", "eyr", "hgt", "hcl", "ecl", "pid"};

	while(getline(cin, line)) {
		bool findNextKey=false, valid=true;
		if (line.size() < 1) { 
			for (string field: required) {
				if (!fields.count(field)) {
					valid = false;
					break;
				}
			}

			if (valid) ans++;

			fields.clear();
			continue;
		}

		for (int i=0; i<line.size(); i++) {
			if (findNextKey) {
				if (line[i] == ' ') { 
					findNextKey = false;
					i++;
				}
				else continue;
			}

			if (line[i] == ':') { 
				fields[key] = true;
				findNextKey = true; 
				key = "";
				continue; 
			}

			key += line[i];
		}
	}

	cout << ans << "\n";
}
