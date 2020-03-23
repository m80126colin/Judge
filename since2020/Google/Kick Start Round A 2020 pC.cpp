/**
 *  @judge Kick Start
 *  @id Round A 2020 pC
 *  @contest Google Kick Start Round A 2020
 *  @tag Minimax Problem
 */
#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
int n, k;
vector<int> m;

int test(int y) {
	int res = 0;
	for (const auto &x : m) {
		res += ceil((double) x / y) - 1;
		if (res > k)
			return 0;
	}
	return 1;
}

int solve() {
	int L, R;
	L = R = 0;
	for (const auto &x : m)
		R = max(R, x);
	sort(m.begin(), m.end());
	while (L + 1 < R) {
		int M = (L + R) / 2;
		if (test(M))
			R = M;
		else
			L = M;
	}
	return R;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t, a0, a1;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cin >> n >> k;
		m = vector<int>(n - 1);
		cin >> a0;
		for (auto && x : m) {
			cin >> a1;
			x = a1 - a0;
			a0 = a1;
		}
		cout << "Case #" << i << ": " << solve() << endl;
		m.clear();
	}
}