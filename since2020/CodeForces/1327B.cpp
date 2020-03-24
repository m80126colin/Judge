/**
 * 	@judge CodeForces
 *  @id 1327B
 *  @name Princesses and Princes
 *  @contest Educational Codeforces Round 84
 * 
 *  @tag Greedy, Graph Theory
 */
#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;

int n, p;
vector<vector<int>> g;
vector<int> pk, ps;

void solve() {
	pk = vector<int>(p + 1, 1);
	ps = vector<int>(n, 1);
	for (int i = 0; i < n; i++)
		for (const auto & x: g[i])
			if (pk[x]) {
				pk[x] = ps[i] = 0;
				break;
			}
	int a1, a2;
	for (a1 = 0; a1 < n; a1++)
		if (ps[a1])
			break;
	for (a2 = 1; a2 <= p; a2++)
		if (pk[a2])
			break;
	if (a1 == n) {
		cout << "OPTIMAL" << endl;
		return ;
	}
	cout << "IMPROVE" << endl;
	cout << a1 + 1 << " " << a2 << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t, k;
	for (cin >> t; t; t--) {
		cin >> n;
		g = vector<vector<int>>(n);
		p = 0;
		for (auto && v: g) {
			cin >> k;
			v = vector<int>(k);
			for (auto && x: v) {
				cin >> x;
				p = max(p, x);
			}
		}
		solve();
		g.clear();
	}
}