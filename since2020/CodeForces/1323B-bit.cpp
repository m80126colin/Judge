/**
 *  @judge CodeForces
 *  @id 1323B
 *  @name Count Subrectangles
 *  @contest Codeforces Round #626
 * 
 *  @tag Range Query Problem
 */
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

#define MAX 40010

int n, m, k, a[MAX], b[MAX];
vector<int> rx, ry;

long long cntA[MAX], totA[MAX], cntB[MAX], totB[MAX];

inline int posA(int a) {
	return n + 1 - a;
}
inline int posB(int b) {
	return m + 1 - b;
}

void update(long long *arr, int x, long long d) {
	for (; x < MAX; x += x & (-x))
		arr[x] += d;
}

long long prefix(long long *arr, int x) {
	long long ans = 0;
	for (; x > 0; x -= x & (-x))
		ans += arr[x];
	return ans;
}

long long sum(int a, int b) {
	return (prefix(totA, posA(a)) - prefix(cntA, posA(a)) * (a - 1)) * (prefix(totB, posB(b)) - prefix(cntB, posB(b)) * (b - 1));
}

long long solve() {
	// init
	for (int i = 0; i <= n + 1; i++)
		cntA[i] = totA[i] = 0;
	for (int j = 0; j <= m + 1; j++)
		cntB[j] = totB[j] = 0;
	//
	for (int i = 0; i < n; i++) {
		if (a[i + 1] == 0 || (i == n - 1 && a[i] > 0)) {
			update(cntA, posA(a[i]), 1);
			update(totA, posA(a[i]), a[i]);
		}
		else a[i + 1] = a[i] + 1;
	}
	for (int j = 0; j < m; j++) {
		if (b[j + 1] == 0 || (j == m - 1 && b[j] > 0)) {
			update(cntB, posB(b[j]), 1);
			update(totB, posB(b[j]), b[j]);
		}
		else b[j + 1] = b[j] + 1;
	}
	//
	int sqk = sqrt((double) k + 0.1);
	long long ans = 0;
	for (int x = 1; x <= sqk; x++) {
		if (k % x == 0) {
			int a = x, b = k / x;
			ans += sum(a, b);
			if (x * x != k) {
				ans += sum(b, a);
			}
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