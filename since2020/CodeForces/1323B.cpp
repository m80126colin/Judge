/**
 *  @judge CodeForces
 *  @id 1323B
 *  @name Count Subrectangles
 *  @contest Codeforces Round #626
 * 
 *  @tag Tree Planting Problem
 */
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

#define MAX 40010

int n, m, k, a[MAX], b[MAX];
vector<int> rx, ry;

long long count(int a, int b) {
	long long ax, ay;
	ax = ay = 0;
	for (int i = 0; i < rx.size(); i++)
		if (rx[i] >= a)
			ax += rx[i] - a + 1;
	for (int j = 0; j < ry.size(); j++)
		if (ry[j] >= b)
			ay += ry[j] - b + 1;
	return ax * ay;
}

long long solve() {
	//
	for (int i = 1; i < n; i++) {
		if (a[i] == 1)
			a[i] = a[i - 1] + 1;
		else
			rx.push_back(a[i - 1]);
	}
	if (a[n - 1] > 0)
		rx.push_back(a[n - 1]);
	sort(rx.begin(), rx.end());
	//
	for (int j = 1; j < m; j++) {
		if (b[j] == 1)
			b[j] = b[j - 1] + 1;
		else
			ry.push_back(b[j - 1]);
	}
	if (b[m - 1] > 0)
		ry.push_back(b[m - 1]);
	sort(ry.begin(), ry.end());
	int sqk = sqrt((double) k + 0.1);
	long long ans = 0;
	for (int x = 1; x <= sqk; x++) {
		if (k % x == 0) {
			ans += count(x, k / x);
			if (x * x != k)
				ans += count(k / x, x);
		}
	}
	return ans;
}

int main() {
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int j = 0; j < m; j++)
		cin >> b[j];
	cout << solve() << endl;
}