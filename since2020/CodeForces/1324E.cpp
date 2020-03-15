/**
 *  @judge CodeForces
 *  @id 1324E
 *  @name Sleeping Schedule
 *  @contest Codeforces Round #627
 * 
 *  @tag Dynamic Programming
 */
#include <bits/stdc++.h>
using namespace std;

#define MAX 2010
int n, h, L, R, a[MAX], dp[2][MAX];

int solve() {
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < h; j++)
			dp[i][j] = -1;
	dp[0][0] = 0;
	for (int i = 0; i < n; i++) {
		int next = (i & 1) ^ 1;
		for (int j = 0; j < h; j++)
			dp[next][j] = -1;
		for (int j = 0; j < h; j++) {
			if (dp[i & 1][j] >= 0)
				for (int k = 0; k < 2; k++) {
					int target = (j + a[i] - k) % h;
					dp[next][target] = max(dp[next][target], dp[i & 1][j] + (L <= target && target <= R ? 1 : 0));
				}
		}
	}
	int ans = 0;
	for (int j = 0; j < h; j++)
		ans = max(ans, dp[n & 1][j]);
	return ans;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cin >> n >> h >> L >> R;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	cout << solve() << endl;
}