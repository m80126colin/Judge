/**
 *  @judge Google Kick Start
 *  @id Round A 2020 pB
 *  @name Plates
 *  @contest Google Kick Start Round A 2020
 * 
 *  @tag Bounded Knapsack
 */
#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;

int n, k, p;
vector<vector<int>> plates;
vector<int> dp;

int solve() {
	int M, ans = 0;
	dp = vector<int>(p + 1, -1);
	M = 1;
	dp[0] = 0;
	for (const auto & ps : plates) {
		for (int j = M - 1; j >= 0; j--) {
			if (dp[j] >= 0) {
				for (int i = 0; i < k + 1 && i + j <= p; i++) {
					dp[i + j] = max(dp[i + j], dp[j] + ps[i]);
					M = max(M, i + j + 1);
				}
			}
		}
	}
	ans = dp[p];
	dp.clear();
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cin >> n >> k >> p;
		plates = vector<vector<int>>(n);
		for (auto && ps : plates) {
			ps = vector<int>(k + 1, 0);
			for (int i = 1; i < ps.size(); i++) {
				cin >> ps[i];
				ps[i] += ps[i - 1];
			}
		}
		cout << "Case #" << i << ": " << solve() << endl;
		plates.clear();
	}
}