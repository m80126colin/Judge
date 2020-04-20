/**
 *  @judge Google Kick Start
 *  @id Round A 2020 pA
 *  @name Allocation
 *  @contest Google Kick Start Round A 2020
 * 
 *  @tag Greedy, Sortings
 */
#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;

int n, b;
vector<int> a, dp, cnt;

int solve() {
	int tot, ans;
	tot = ans = 0;
	sort(a.begin(), a.end());
	for (const auto &x : a)
		if (tot + x <= b) {
			tot += x;
			ans ++;
		}
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cin >> n >> b;
		a = vector<int>(n);
		for (auto && x: a)
			cin >> x;
		cout << "Case #" << i << ": " << solve() << endl;
		a.clear();
	}
}