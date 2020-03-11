/**
 *  @judge CodeForces
 *  @id 1312B
 *  @name Bogosort
 *  @contest Educational Codeforces Round 83
 * 
 *  @tag Sortings
 */
#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> b;

void solve() {
	sort(b.begin(), b.end(), [](int L, int R) { return L > R; });
	for (const auto &x : b)
		cout << x << " ";
	cout << endl;
}

int main() {
	int t;
	for (cin >> t; t; t--) {
		cin >> n;
		b = vector<int>(n, 0);
		for (auto && x : b)
			cin >> x;
		solve();
	}
}