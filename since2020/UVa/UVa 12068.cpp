/**
 *  @judge UVa
 *  @id 12068
 *  @name Harmonic Mean
 * 
 *  @tag Greatest Common Divisor
 */
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ULL;

int n;
vector<ULL> as;

ULL gcd(ULL a, ULL b) {
	if (a % b == 0)
		return b;
	return gcd(b, a % b);
}

tuple<ULL, ULL> solve() {
	ULL resa, resb, tmp = 1;
	for (const auto &a : as)
		tmp *= a;
	resa = tmp * n;
	resb = 0;
	for (const auto &a : as)
		resb += tmp / a;
	ULL g = gcd(resa, resb);
	return make_tuple(resa / g, resb / g);
}

int main() {
	int s;
	ULL a, b;
	cin >> s;
	for (int i = 1; i <= s; i++) {
		cin >> n;
		as = vector<ULL>(n, 0);
		for (auto && a : as)
			cin >> a;
		tie(a, b) = solve();
		cout << "Case " << i << ": " << a << "/" << b << endl;
		as.clear();
	}
}