#include <bits/stdc++.h>

using namespace std;

int main() {
	int g=0, e=0;
	string s, g_bin, e_bin;
	vector<int> v;
	while (cin >> s) {
		for (uint i=0; i<s.size(); i++) {
			if (v.size() > i) {
				(s[i] == '1') ? v[i]++ : v[i]--;
			} else {
				(s[i] == '1') ? v.push_back(1): v.push_back(0);
			}
		}
	}

	for (int i: v) {
		(i>0) ? g_bin += "1" : g_bin += "0";
	}

	cout << "g_bin: " << g_bin << "\n";

	for (int i=g_bin.size()-1; i>=0; i--) {
		if (g_bin[i] == '1') {
			g += pow(2, s.size()-i-1);
		} else {
			e += pow(2, s.size()-i-1);
		}
	}

	cout << "g: " << g << " e: " << e << "\n";

	cout << "ans: " << g * e << "\n";
	return 0;
}
