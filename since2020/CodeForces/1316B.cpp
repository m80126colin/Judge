/**
 * @judge CodeForces
 * @id 1316B
 * @name String Modification
 * @contest CodeCraft-20 (Div. 2)
 * 
 * @tag String Manipulation
 */
#include <iostream>
#include <algorithm>
using namespace std;

int n;
string s;

int solve() {
	char ch = s[0];
	for (int i = 1; i < n; i++)
		if (s[i] < ch)
			ch = s[i];
	int ans = 1;
	string current = s;
	for (int k = 0; k < n; k++) {
		if (s[k] == ch) {
			string tmp = s.substr(0, k);
			if (((k + 1) % 2 == 1) ^ (s.size() % 2 == 0))
				reverse(tmp.begin(), tmp.end());
			tmp = s.substr(k) + tmp;
			if (tmp < current) {
				current = tmp;
				ans = k + 1;
			}
		}
	}
	cout << current << endl;
	return ans;
}

int main() {
	int t;
	for (cin >> t; t; t--) {
		cin >> n >> s;
		cout << solve() << endl;
	}
}