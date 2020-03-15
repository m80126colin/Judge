/**
 *  @judge CodeForces
 *  @id 1324A
 *  @name Yet Another Tetris Problem
 *  @contest Codeforces Round #627
 * 
 *  @tag Ad-hoc, Basic Operations
 */
#include <bits/stdc++.h>
using namespace std;

vector<int> a;

bool solve() {
	int mx = a[0];
	for (const auto &x : a)
		mx = max(mx, x);
	for (const auto &x : a)
		if ((mx - x) & 1)
			return false;
	return true;
}

int main() {
	int t, n;
	for (cin >> t; t; t--) {
		cin >> n;
		a = vector<int>(n, 0);
		for (auto && x : a)
			cin >> x;
		cout << (solve() ? "YES" : "NO") << endl;
		a.clear();
	}
}