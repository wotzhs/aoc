#include <bits/stdc++.h>

using namespace std;

int main() {
	int ans=0, curr=0, next=0;
	cin >> curr;
	while (cin >> next) {
		if (next > curr) {
			ans++;
		}
		curr = next;
	}

	cout << "ans: " << ans << "\n";

	return 0;
}
