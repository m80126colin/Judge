/**
 *  @judge CodeForces
 *  @id 1324B
 *  @name Yet Another Palindrome Problem
 *  @contest Codeforces Round #627
 * 
 *  @tag Palindrome
 */
#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> a;
map<int, int> M;

bool solve() {
	M.clear();
	for (int i = 0; i < a.size(); i++) {
		if (!M[a[i]])
			M[a[i]] = i + 1;
		else if (i - M[a[i]] > 0)
			return true;
	}
	return false;
}

int main() {
	int t;
	for (cin >> t; t; t--) {
		cin >> n;
		a = vector<int>(n, 0);
		for (auto && x : a)
			cin >> x;
		cout << (solve() ? "YES" : "NO") << endl;
		a.clear();
	}
}