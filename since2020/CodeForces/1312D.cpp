/**
 *  @judge CodeForces
 *  @id 1312D
 *  @name Count the Arrays
 *  @contest Educational Codeforces Round 83
 * 
 *  @tag Combinatorics, Congruence Modulus
 */
#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
const LL MOD = 998244353;

auto extgcd(LL a, LL b) {
	if (a % b == 0)
		return make_tuple(b, 0LL, 1LL);
	LL g, x, y;
	tie(g, x, y) = extgcd(b, a % b);
	return make_tuple(g, y, x - (a / b) * y);
}

LL inv(LL a) {
	LL y;
	tie(ignore, ignore, y) = extgcd(MOD, a);
	return (y + MOD) % MOD;
}

LL modComb(LL a, LL b) {
	LL ans = 1, c = min(b, a - b);
	for (auto i = 1; i <= c; i++) {
		ans = (ans * (a - i + 1)) % MOD;
		ans = (ans * inv(i)) % MOD;
	}
	return ans;
}

LL modExp(LL a, LL b) {
	LL ans = 1LL, aa = a;
	for (auto x = b; x > 0; x >>= 1) {
		if (x & 1)
			ans = (ans * aa) % MOD;
		aa = (aa * aa) % MOD;
	}
	return ans;
}

LL solve(LL n, LL m) {
	LL ax = modComb(m, n - 1) * (n - 2) % MOD;
	LL ay = modExp(2LL, n - 3);
	return ax * ay % MOD;
}

int main() {
	LL n, m;
	while (cin >> n >> m) {
		cout << solve(n, m) << endl;
	}
}