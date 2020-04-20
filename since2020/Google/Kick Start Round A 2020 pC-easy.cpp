/**
 *  @judge Google Kick Start
 *  @id Round A 2020 pC
 *  @name Workout
 *  @contest Google Kick Start Round A 2020
 *  @tag Greedy, Sortings
 */
#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
int n, k;
vector<int> m;

int solve() {
	sort(m.begin(), m.end());
	int t = (m[n - 2] + 1) / 2;
	if (n == 2)
		return t;
	return max(t, m[n - 3]);
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