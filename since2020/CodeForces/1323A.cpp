/**
 *  @judge CodeForces
 *  @id 1323A
 *  @name Even Subset Sum Problem
 *  @contest Codeforces Round #626
 * 
 *  @tag Ad-hoc
 */
#include <iostream>
using namespace std;

#define MAX 110

int n, a[MAX];

void solve() {
	for (int i = 0; i < n; i++) {
		if (a[i] % 2 == 0) {
			cout << "1" << endl;
			cout << i + 1 << endl;
			return ;
		}
	}
	int count, prev;
	count = prev = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] % 2 == 1) {
			count ++;
			if (count == 1)
				prev = i + 1;
			else if (count == 2) {
				cout << "2" << endl;
				cout << prev << " " << i + 1 << endl;
				return ;
			}
		}
	}
	cout << "-1" << endl;
	return ;
}

int main() {
	int t;
	for (cin >> t; t; t--) {
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> a[i];
		solve();
	}
}