/**
 *  @judge CodeForces
 * 	@id 1326C
 *  @name Permutation Partitions
 * 
 *  @tag Math, Combinatorics
 */
#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;

#define MAX 200010

LL n, k;
vector<LL> a;

LL solve() {
	LL m = n - k + 1;
	vector<LL> seg;
	for (int i = 0; i < n; i++)
		if (a[i] >= m)
			seg.push_back(i);
	LL ans = 1;
	for (int i = 0; i < seg.size() - 1; i++)
		ans = (ans * (seg[i + 1] - seg[i])) % 998244353LL;
	return ans;
}

int main() {
	cin >> n >> k;
	a = vector<LL>(n);
	for (auto && x : a)
		cin >> x;
	cout << (n + n - k + 1) * k / 2 << " " << solve() << endl;
}