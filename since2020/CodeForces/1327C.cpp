/**
 * 	@judge CodeForces
 *  @id 1327C
 *  @name Game with Chips
 *  @contest Educational Codeforces Round 84
 * 
 *  @tag Ad-hoc
 */
#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;

int n, m, k;
// vector<tuple<int, int>> s, f;

void solve() {
	string left(m - 1, 'L'), right(m - 1, 'R');
	cout << n * m + n + m - 3 << endl;
	cout << string(n - 1, 'U') << left << right;
	for (int i = 0; i < n - 1; i++)
		cout << 'D' << ((i & 1) ? right : left);
	cout << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int x, y;
	cin >> n >> m >> k;
	/*
	s = vector<tuple<int, int>>(k);
	f = vector<tuple<int, int>>(k);
	for (auto & ss: s) {
		cin >> x >> y;
		s.emplace_back(x, y);
	}
	for (auto && ff: f) {
		cin >> x >> y;
		f.emplace_back(x, y);
	}
	*/
	solve();
	/*
	s.clear();
	f.clear();
	*/
}