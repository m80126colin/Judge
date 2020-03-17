/**
 *  @judge CodeForces
 *  @id 1323B
 *  @name Count Subrectangles
 *  @contest Codeforces Round #626
 * 
 *  @tag Tree Planting
 */
#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;

int n, m, k;
vector<int> xs, ys;

LL count(int a, int b) {
	LL ax, ay;
	ax = ay = 0;
	for (const auto &x : xs)
		if (x >= a)
			ax += x - a + 1;
	for (const auto &y : ys)
		if (y >= b)
			ay += y - b + 1;
	return ax * ay;
}

vector<int> shrink(const vector<int> &vs) {
	int cnt = 0;
	vector<int> res;
	for (const auto &v : vs) {
		if (v == 1)
			cnt++;
		else if (cnt > 0) {
			res.push_back(cnt);
			cnt = 0;
		}
	}
	if (vs.back() > 0)
		res.push_back(cnt);
	sort(res.begin(), res.end());
	return res;
}

LL solve() {
	xs = shrink(xs);
	ys = shrink(ys);
	// count
	LL ans = 0;
	int sqk = sqrt((double) k + 0.1);
	for (int x = 1; x <= sqk; x++) {
		if (k % x == 0) {
			ans += count(x, k / x);
			if (x * x != k)
				ans += count(k / x, x);
		}
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n >> m >> k;
	xs = vector<int>(n);
	ys = vector<int>(m);
	for (auto &&x : xs) cin >> x;
	for (auto &&y : ys) cin >> y;
	cout << solve() << endl;
}