#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string line, key, value;
	int ans=0;
	unordered_map<string, string> fields;

	const string required[] = {"byr", "iyr", "eyr", "hgt", "hcl", "ecl", "pid"};
	const unordered_map<string, bool> validEyeColours = {
		{"amb", true},
		{"blu", true},
		{"brn", true},
		{"gry", true},
		{"grn", true},
		{"hzl", true},
		{"oth", true},
	};

	while(getline(cin, line)) {
		bool valid=true, foundKey=false;

		for (int i=0; i<line.size(); i++) {
			if (line[i] == ' ') { 
				fields[key] = value;
				key = ""; value = ""; foundKey = false;
				continue;
			}

			if (line[i] == ':') { 
				foundKey = true;
				continue; 
			}

			if (!foundKey) key += line[i];
			else value += line[i];

			if (i == line.size()-1) {
				fields[key] = value;
				key = ""; value = ""; foundKey = false;
				continue;
			}
		}
		if (fields.size() >= 7) { 
			for (string field: required) {
				if (!fields.count(field)) {
					valid = false;
					break;
				}

				if (field == "byr") {
					const int v = stoi(fields[field]);
					if (v < 1920 || v > 2002) {
						valid = false;
						break;
					}
				}

				if (field == "iyr") {
					const int v = stoi(fields[field]);
					if (v < 2010 || v > 2020) {
						valid = false;
						break;
					}
				}
				
				if (field == "eyr") {
					const int v = stoi(fields[field]);
					if (v < 2020 || v > 2030) {
						valid = false;
						break;
					}
				}

				if (field == "hgt") {
					string unit;
					unit = fields[field][fields[field].size()-1] + unit;
					unit = fields[field][fields[field].size()-2] + unit;
					
					if (unit != "cm" && unit != "in") {
						valid = false;
						break;
					}

					const int v = stoi(fields[field].substr(0, fields[field].size()-2));
					if (unit == "cm" && (v < 150 || v > 193)) {
						valid = false;
						break;
					}
					
					if (unit == "in" && (v <59 || v > 76)) {
						valid = false;
						break;
					}
				}

				if (field == "hcl") {
					string v = fields[field];
					if (v.size() > 7) {
						valid = false;
						break;
					}

					if (v[0] != '#') {
						valid = false;
						break;
					}

					for (int i=1; i<v.size(); i++) {
						if (v[i] - '0' >= 0 && v[i] - '0' <= 9) {
							continue;
						}

						if (v[i] - 'a' >= 0 && v[i] - 'a' <= 5) {
							continue;
						}

						valid= false;
						break;
					}
				}

				if (field == "ecl") {
					if (!validEyeColours.count(fields[field])) {
						valid = false;
						break;
					}
				}

				if (field == "pid") {
					const string v = fields[field];
					if (v.size() != 9) {
						valid = false;
						break;
					}

					for (int i=0; i<v.size(); i++) {
						if (v[i] - '0' < 0 || v[i] - '0' > 9) {
							valid = false;
							break;
						}
					}
				}
			}

			if (valid) { 
				ans++; 
				fields.clear();
			}

		}

		if (line.size() < 1) {
			fields.clear();
		}
	}

	cout << ans << "\n";
}
