/**
 *  @judge CodeForces
 *  @id 1305C
 *  @name Kuroni and Impossible Calculation
 *  @contest Ozon Tech Challenge 2020
 * 
 *  @tag Math, Modulus
 */
#include <iostream>
#include <cmath>
using namespace std;

#define MAX 200010
#define BUK 1010

int n, m, a[MAX], b[BUK];

int solve() {
	if (n > m)
		return 0;
	for (int j = 0; j < m; j++)
		b[j] = 0;
	for (int i = 0; i < n; i++) {
		int j = a[i] % m;
		if (b[j])
			return 0;
		b[j] = 1;
	}
	int ans = 1;
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			ans = (abs(a[i] - a[j]) % m * ans) % m;
	return ans;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	cout << solve() << endl;
}