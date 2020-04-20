/**
 *  @judge CodeForces
 *  @id 1328A
 *  @name Divisibility Problem
 *  @contest Codeforces Round #629 (Div. 3)
 * 
 *  @tag Modulus
 */
#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
int a, b;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t;
	for (cin >> t; t; t--) {
		cin >> a >> b;
		cout << ((-a) % b + b) % b << endl;
	}
}