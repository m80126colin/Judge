/**
 *  @judge CodeForces
 *  @id 1312C
 *  @name Adding Powers
 *  @contest Educational Codeforces Round 83
 * 
 *  @tag Greedy, Number Base Conversion
 */
#include <bits/stdc++.h>
using namespace std;

const int MAX = 110;

long long n, k, kpower[MAX];
vector<long long> a;

void intoKBase(long long x) {
	for (auto &&kp : kpower) {
		if (x <= 0)
			return ;
		kp += x % k;
		x /= k;
	}
	return ;
}

bool solve() {
	for (auto && kp : kpower)
		kp = 0;
	for (const auto &x : a)
		intoKBase(x);
	for (const auto &kp : kpower)
		if (kp > 1)
			return false;
	return true;
}

int main() {
	int t;
	for (cin >> t; t; t--) {
		cin >> n >> k;
		a = vector<long long>(n, 0);
		for (auto && x : a)
			cin >> x;
		cout << (solve() ? "YES" : "NO") << endl;
	}
}