#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string line;
	int width, s1=1, s2=3, s3=5, s4=7, s5=1, s5d=2;
	long long ans1=0, ans2=0, ans3=0, ans4=0, ans5=0;

	cin >> line;
	width = line.size();

	while(cin >> line) {
		if (line[s1] == '#') ans1++;
		s1 += 1;
		s1 %= width;

		if (line[s2] == '#') ans2++;
		s2 += 3;
		s2 %= width;

		if (line[s3] == '#') ans3++;
		s3 += 5;
		s3 %= width;

		if (line[s4] == '#') ans4++;
		s4 += 7;
		s4 %= width;

		if (--s5d == 0) {
			if (line[s5] == '#') ans5++;
			s5d = 2;
			s5 += 1;
			s5 %= width;
		}
	}

	cout << ans1 * ans2 * ans3 * ans4 * ans5 << "\n";
}
