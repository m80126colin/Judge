/**
 *  @judge CodeForces
 *  @id 1323B
 *  @name Count Subrectangles
 *  @contest Codeforces Round #626
 * 
 *  @tag Range Query
 */
#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;

int n, m, k;
vector<int> xs, ys;
vector<LL> cntA, totA, cntB, totB;

inline int posA(int a) {
	return n + 1 - a;
}
inline int posB(int b) {
	return m + 1 - b;
}

void update(vector<LL> &vs, int x, LL d) {
	for (; x < vs.size(); x += x & (-x))
		vs[x] += d;
}

LL query(const vector<LL> &vs, int x) {
	LL ans = 0;
	for (; x > 0; x -= x & (-x))
		ans += vs[x];
	return ans;
}

LL count(int a, int b) {
	return (query(totA, posA(a)) - query(cntA, posA(a)) * (a - 1)) * (query(totB, posB(b)) - query(cntB, posB(b)) * (b - 1));
}

void shrink(const vector<int> &vs, vector<LL> &cnt, vector<LL> &tot) {
	int c = 0;
	vector<int> res;
	for (const auto &v : vs) {
		if (v == 1)
			c++;
		else if (c > 0) {
			res.push_back(c);
			c = 0;
		}
	}
	if (vs.back() > 0)
		res.push_back(c);
	for (const auto &x : res) {
		update(cnt, vs.size() + 1 - x, 1);
		update(tot, vs.size() + 1 - x, x);
	}
	return ;
}

LL solve() {
	cntA = totA = vector<LL>(n + 1);
	cntB = totB = vector<LL>(m + 1);
	shrink(xs, cntA, totA);
	shrink(ys, cntB, totB);
	//
	LL ans = 0;
	int sqk = sqrt((double) k + 0.1);
	for (int x = 1; x <= sqk; x++) {
		if (k % x == 0) {
			int a = x, b = k / x;
			ans += count(a, b);
			if (x * x != k) {
				ans += count(b, a);
			}
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