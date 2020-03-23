/**
 *  @judge CodeForces
 * 	@id 1326A
 *  @name Bad Ugly Numbers
 * 
 *  @tag String Manipulation
 */
#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;

const int MAX = 100010;

string s = "";
int n;

string solve() {
	if (n == 1)
		return "-1";
	return s.substr(0, n);
}

int main() {
	int t;
	s = "2" + string(MAX - 1, '3');
	for (cin >> t; t; t--) {
		cin >> n;
		cout << solve() << endl;
	}
}