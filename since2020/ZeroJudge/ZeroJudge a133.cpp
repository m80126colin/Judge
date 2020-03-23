/**
 *  @judge ZeroJudge
 *  @id a133
 *  @name The Twin Towers
 *  @source UVa 10066
 *
 *  @tag Longest Common Subsequence
 */
#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> as, bs;
vector<vector<int>> dp;

int solve() {
	int pre, nxt;
	for (int i = 0; i < n; i++) {
		pre = i & 1;
		nxt = (i + 1) & 1;
		for (int j = 0; j < m; j++)
			if (as[i] == bs[j])
				dp[nxt][j + 1] = dp[pre][j] + 1;
			else
				dp[nxt][j + 1] = max(dp[nxt][j], dp[pre][j + 1]);
	}
	return dp[n & 1][m];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	for (int t = 1; cin >> n >> m; t++) {
		if (n == 0 && m == 0)
			return 0;
		as = vector<int>(n);
		bs = vector<int>(m);
		for (auto &&a : as) cin >> a;
		for (auto &&b : bs) cin >> b;
		dp = vector<vector<int>>(2, vector<int>(101, 0));
		cout << "Twin Towers #" << t << endl;
		cout << "Number of Tiles : " << solve() << endl << endl;
		as.clear();
		bs.clear();
		dp.clear();
	}
}