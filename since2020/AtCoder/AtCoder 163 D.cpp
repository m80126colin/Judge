/**
 *  @judge AtCoder
 *  @id abc163_d
 *  @name Sum of Large Numbers
 *  @contest AtCoder Beginner Contest 163
 * 
 *  @tag Combinatorics
 */
#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;

LL n, k;
LL MOD = 1000000007LL;

LL solve() {
	LL x, tmp, ans = 0;
	for (x = k; x <= n + 1; x++)
		ans = (ans + x * (n - x + 1) + 1) % MOD;
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); 
	cout.tie(nullptr);
	while (cin >> n >> k)
		cout << solve() << endl; 
}