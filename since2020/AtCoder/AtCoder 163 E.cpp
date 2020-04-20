/**
 *  @judge AtCoder
 *  @id abc163_e
 *  @name Active Infants
 *  @contest AtCoder Beginner Contest 163
 * 
 *  @tag Dynamic Programming, Monotonicity
 */
#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;

int n;
vector<LL> a;
vector<vector<LL>> dp;

LL solve() {
	if (n == 1)
		return 0;
	vector<pair<LL, LL>> order;
	dp = vector<vector<LL>>(n + 1, vector<LL>(n + 1, 0));
	for (int i = 0; i < n; i++)
		order.emplace_back(a[i], i);
	sort(order.begin(), order.end(), [](pair<LL, LL> L, pair<LL, LL> R) {
		if (L.first != R.first)
			return L.first > R.first;
		return L.second < R.second;
	});
	for (int i = 1; i <= n; i++) {
		dp[0][i] = dp[0][i - 1] + abs(order[i - 1].second - n + i) * order[i - 1].first;
		dp[i][0] = dp[i - 1][0] + abs(order[i - 1].second - i + 1) * order[i - 1].first;
	}
	for (int i = 2; i <= n; i++)
		for (int L = 1; L < i; L++) {
			int R = i - L;
			dp[L][R] = max(
				dp[L][R],
				max(dp[L - 1][R] + abs(order[i - 1].second - L + 1) * order[i - 1].first,
					dp[L][R - 1] + abs(order[i - 1].second - n + R) * order[i - 1].first)
			);
		}
	LL ans = dp[0][n];
	for (int L = 0; L <= n; L++)
		ans = max(ans, dp[L][n - L]);
	dp.clear();
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	while (cin >> n) {
		a = vector<LL>(n);
		for (auto &&x : a)
			cin >> x;
		cout << solve() << endl;
		a.clear();
	}
}