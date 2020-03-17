/**
 *  @judge CodeForces
 *  @id 1311F
 *  @name Moving Points
 *  @contest CodeForces Round #624 div.3
 * 
 *  @tag Monotonicity, Range Query
 */
#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;

int n;
vector<int> pos, rev;
vector<tuple<int, LL>> point;
vector<LL> bit, node;

void update(vector<LL> &tree, int idx, LL d) {
	for (int i = idx + 1; i < tree.size(); i += i & (-i))
		tree[i] += d;
}

LL query(const vector<LL> &tree, int idx) {
	LL res = 0;
	for (int i = idx + 1; i; i -= i & (-i))
		res += tree[i];
	return res;
}

bool cmp(int L, int R) {
	if (get<0>(point[L]) != get<0>(point[R]))
		return get<0>(point[L]) < get<0>(point[R]);
	return get<1>(point[L]) < get<1>(point[R]);
}

LL solve() {
	pos = rev = vector<int>(n);
	bit = node = vector<LL>(n + 1, 0);
	// indexed position
	for (int i = 0; i < n; i++)
		pos[i] = i;
	sort(pos.begin(), pos.end(), [](int L, int R) {
		return get<1>(point[L]) < get<1>(point[R]);
	});
	for (int i = 0; i < n; i++)
		rev[pos[i]] = i;
	// sort by velocity
	LL ans = 0;
	sort(pos.begin(), pos.end(), cmp);
	for (const auto &k : pos) {
		int p = rev[k];
		LL x = get<1>(point[k]);
		ans += query(node, p) * x - query(bit, p);
		update(bit, p, x);
		update(node, p, 1);
	}
	return ans;
}

int main() {
	cin >> n;
	point = vector<tuple<int, LL>>(n);
	for (auto && p : point)
		cin >> get<1>(p);
	for (auto && p : point)
		cin >> get<0>(p);
	cout << solve() << endl;
}