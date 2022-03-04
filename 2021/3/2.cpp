#include <bits/stdtr1c++.h>
using namespace std;

int main() {
	string bin;
	int zeros=0, ones=0;
	vector<string> bins, o_filtered, c_filtered; 
	while(cin >> bin) {
		bins.push_back(bin);
	}

	vector<string> o_bins = bins;
	vector<string> c_bins = bins;
	
	int n = bins[0].size();
	vector<int> counts(n, 0);

	for (int i=0; i<n; i++) {
		for (string bin: o_bins) {
			bin[i] == '0' ? zeros++ : ones++;
		}

		zeros > ones ? counts[i] = 0 : counts[i] = 1;

		for (string bin: o_bins) {
			if (bin[i] - '0' == counts[i]) {
				o_filtered.push_back(bin);
			}
		}

		zeros = 0, ones = 0;

		for (string bin: c_bins) {
			bin[i] == '0' ? zeros++ : ones++;
		}

		zeros > ones ? counts[i] = 0 : counts[i] = 1;

		zeros = 0, ones = 0;

		for (string bin: c_bins) {
			if (bin[i] - '0' != counts[i]) {
				c_filtered.push_back(bin);
			}
		}

		o_bins = o_filtered, c_bins = c_filtered;
		o_filtered.clear(), c_filtered.clear();

	}

	cout << "o_bin: " << o_bins[0] << "\n";
	cout << "c_bin: " << c_bins[0] << "\n";

	int o=0, c=0;
	for (int i=o_bins[0].size()-1; i>=0; i--) {
		if (o_bins[0][i]-'0' == 1) {
			o += pow(2, o_bins[0].size()-1-i);
		}

		if (c_bins[0][i]-'0' == 1) {
			c += pow(2, c_bins[0].size()-1-i);
		}
	}

	cout << "ans: " << o*c << "\n";

	return 0;
}
