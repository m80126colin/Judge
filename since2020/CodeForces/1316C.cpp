/**
 * @judge CodeForces
 * @id 1316C
 * @name Primitive Primes
 * @contest CodeCraft-20 (Div. 2)
 * 
 * @tag Math, Prime, Polynomial
 */
#include <iostream>
#include <cstdio>
using namespace std;

#define MAX 1000010

int n, m, p, a[MAX], b[MAX];

int solve() {
	int i = n - 1, j = m - 1;
	while (i + j > 0) {
		if (j > 0 && b[j] % p == 0)
			j--;
		else if (i > 0 && a[i] % p == 0)
			i--;
		else
			return i + j;
	}
	return 0;
}

int main() {
	cin >> n >> m >> p;
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int j = 0; j < m; j++)
		scanf("%d", &b[j]);
	cout << solve() << endl;
}