#include <bits/stdc++.h>

using namespace std;

int main() {
	int ans=0, curr=0, w1=0, w2=0, w3=0, w4=0;
	cin >> w1 >> w2 >> w3;
	curr = w1 + w2 + w3;
	while (cin >> w4) {
		if (w2 + w3 + w4 > curr) {
			ans++;
		}
		curr = w2 + w3 + w4;
		w1 = w2, w2 = w3, w3 = w4;
	}

	cout << "ans: " << ans << "\n";

	return 0;
}
