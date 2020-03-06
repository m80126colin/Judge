/**
 *  @judge CodeForces
 *  @id 1311B
 *  @name WeirdSort
 *  @contest CodeForces Round #624 div.3
 * 
 *  @tag Sortings
 */
#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 110

int a[MAX], p[MAX], n, m;

int solve() {
	sort(p, p + m);
	int pos = 0;
	for (int j = 1; j < m; j++) {
		if (p[j] == p[j - 1] + 1)
			continue;
		sort(a + p[pos] - 1, a + p[j - 1] + 1);
		pos = j;
	}
	sort(a + p[pos] - 1, a + p[m - 1] + 1);
	for (int i = 0; i < n - 1; i++) {
		if (a[i] > a[i + 1])
			return false;
	}
	return true;
}

int main() {
	int t;
	for (cin >> t; t; t--) {
		cin >> n >> m;
		for (int i = 0; i < n; i++)
			cin >> a[i];
		for (int j = 0; j < m; j++)
			cin >> p[j];
		if (solve())
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}