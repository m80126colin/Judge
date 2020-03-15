/**
 *  @judge CodeForces
 *  @id 1324C
 *  @name Frog Jumps
 *  @contest Codeforces Round #627
 * 
 *  @tag Greedy, Minimax Problem
 */
#include <bits/stdc++.h>
using namespace std;

string s;

int solve() {
	int pos, ans;
	pos = ans = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'R') {
			ans = max(ans, i + 1 - pos);
			pos = i + 1;
		}
	}
	return max(ans, (int)s.size() + 1 - pos);
}

int main() {
	int t;
	for (cin >> t; t; t--) {
		cin >> s;
		cout << solve() << endl;
	}
}