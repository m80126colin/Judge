/**
 *  @judge ZeroJudge
 *  @id a233
 *  @name Power Strings
 *  @source UVa 10298
 * 
 *  @tag String Manipulation, Integer Factorisation, Search
 */
#include <bits/stdc++.h>
using namespace std;

string s;

bool test(int x) {
	for (int i = x; i < s.size(); i += x)
		for (int j = 0; j < x; j++)
			if (s[j] != s[i + j])
				return false;
	return true;
}

int solve() {
	int n = sqrt((double) s.size() + 0.001);
	vector<int> divisor;
	for (int i = 1; i <= n; i++) {
		if (s.size() % i == 0) {
			divisor.push_back(i);
			divisor.push_back(s.size() / i);
		}
	}
	sort(divisor.begin(), divisor.end());
	for (const auto &i : divisor)
		if (test(i))
			return s.size() / i;
	return 1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	while (cin >> s, s != ".")
		cout << solve() << endl;
}