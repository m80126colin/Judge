/**
 * 	@judge CodeForces
 *  @id 1327A
 *  @name Sum of Odd Integers
 *  @contest Educational Codeforces Round 84
 * 
 *  @tag Math
 */
#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;

int n, k;

bool solve() {
	if (n < (LL) k * k)
		return false;
	return (n % 2) ^ (k % 2 == 0);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t;
	for (cin >> t; t; t--) {
		cin >> n >> k;
		cout << (solve() ? "YES" : "NO") << endl;
	}
}