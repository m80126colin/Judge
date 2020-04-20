/**
 *  @judge Google Code Jam
 *  @id Qualification Round 2020 pB
 *  @name Nesting Depth
 *  @contest Google Code Jam Qualification Round 2020
 * 
 *  @tag Greedy, String Manipulation
 */
#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long int LL;

const int MAX = 10;
string L[MAX], R[MAX];

void init() {
	L[0] = R[0] = "";
	for (int i = 1; i < MAX; i++) {
		L[i] = L[i - 1] + "(";
		R[i] = R[i - 1] + ")";
	}
}

string solve(string s) {
	string res = "";
	int pre = 0;
	for (const auto &ch : s) {
		int d = ch - '0';
		if (pre < d)
			res += L[d - pre];
		else if (pre > d)
			res += R[pre - d];
		res += ch;
		pre = d;
	}
	res += R[pre];
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t;
	string s;
	cin >> t;
	init();
	for (int i = 1; i <= t; i++) {
		cin >> s;
		cout << "Case #" << i << ": " << solve(s) << endl;
	}
}