/**
 *  @judge CodeForces
 *  @id 1328C
 *  @name Ternary XOR
 *  @contest Codeforces Round #629 (Div. 3)
 * 
 *  @tag Greedy, Binary Operations
 */
#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;

auto solve(int n, string a) {
	bool flag = false;
	string s1(n, '0'), s2(n, '0');
	for (int i = 0; i < n; i++) {
		if (flag)
			s2[i] = a[i];
		else if (a[i] == '1') {
			s1[i] = a[i];
			flag = true;
		}
		else
			s1[i] = s2[i] = (a[i] - '0') / 2 + '0';
	}
	return make_tuple(s1, s2);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t, n;
	string a, s1, s2;
	for (cin >> t; t; t--) {
		cin >> n >> a;
		tie(s1, s2) = solve(n, a);
		cout << s1 << endl << s2 << endl;
	}
}