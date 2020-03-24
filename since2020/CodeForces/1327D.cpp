/**
 * 	@judge CodeForces
 *  @id 1327D
 *  @name Infinite Path
 *  @contest Educational Codeforces Round 84
 * 
 *  @tag Number Theory, Cycle Detecting, Searching
 */
#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;

int n;
vector<int> p, c, vis, path;

bool test(int step) {
	int turtle, rare;
	for (turtle = 0; turtle < step; turtle++) {
		for (rare = turtle + step; rare < path.size(); rare += step)
			if (c[path[rare]] != c[path[turtle]])
				break;
		if (rare >= path.size())
			return true;
	}
	return false;
}

int solve() {
	int cycle, ptr, ans = n;
	vis = vector<int>(n, 0);
	for (int i = 0; i < n; i++) {
		if (!vis[i]) {
			vis[i] = 1;
			path.push_back(i);
			for (ptr = p[i]; !vis[ptr]; ptr = p[ptr]) {
				vis[ptr] = 1;
				path.push_back(ptr);
			}
			ans = min(ans, (int) path.size());
			for (ptr = 1; ptr < ans && ptr <= path.size() / 2; ptr++)
				if (path.size() % ptr == 0 && test(ptr))
					ans = min(ans, ptr);
			path.clear();
		}
	}
	vis.clear();
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t;
	for (cin >> t; t; t--) {
		cin >> n;
		p = vector<int>(n);
		c = vector<int>(n);
		for (auto && pp: p) {
			cin >> pp;
			pp--;
		}
		for (auto && cc: c)
			cin >> cc;
		cout << solve() << endl;
		p.clear();
		c.clear();
	}
}