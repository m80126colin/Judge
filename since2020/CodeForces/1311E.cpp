/**
 *  @judge CodeForces
 *  @id 1311E
 *  @name Construct the Binary Tree
 *  @contest CodeForces Round #624 div.3
 * 
 *  @tag Tree, Ad-hoc
 */
#include <iostream>
using namespace std;

#define MAX 5010

int mn[MAX], mx[MAX], node[MAX], n, d;

void solve() {
	for (int i = 0; i <= n; i++)
		node[i] = 0;
	node[0] = 1;
	// construction
	int tot = 0, qn = 1, q = 0;
	for (int i = 2; i <= n; i++) {
		if (i / qn >= 2) {
			qn *= 2;
			q++;
		}
		node[q]++;
		tot += q;
	}
	for (; tot < d; tot++) {
		for (int j = n - 1; j; j--) {
			if (node[j - 1] > 1 && node[j] / node[j - 1] < 2) {
				node[j]++;
				node[j - 1]--;
				break;
			}
		}
	}
	int p;
	/*for (int i = 0; i <= n; i++) {
		cerr << "node[" << i << "]: " << node[i] << endl;
	}*/
	for (int i = 1; i <= n; i++) {
		if (i - 2 >= 0)
			p = node[i - 2] + 1;
		else
			p = 1;
		int x = node[i];
		// cerr << "x: " << x << endl;
		node[i] += node[i - 1];
		for (int j = 0; j < x; j++) {
			cout << p + j / 2 << " ";
		}
	}
	cout << endl;
}

int main() {
	int t, q = 1, qn = 2;
	mn[1] = mx[1] = 0;
	for (int i = 2; i < MAX; i++) {
		if (i / qn > 1) {
			qn *= 2;
			q++;
		}
		mn[i] = mn[i - 1] + q;
		mx[i] = mx[i - 1] + (i - 1);
	}
	for (cin >> t; t; t--) {
		cin >> n >> d;
		bool flag = mx[n] >= d && d >= mn[n];
		cout << (flag ? "YES" : "NO") << endl;
		if (flag)
			solve();
	}
}