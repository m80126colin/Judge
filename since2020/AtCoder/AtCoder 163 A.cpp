/**
 *  @judge AtCoder
 *  @id abc163_a
 *  @name Circle Pond
 *  @contest AtCoder Beginner Contest 163
 * 
 *  @tag Math
 */
#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	double r;
	while (cin >> r)
		cout << fixed << r * 8.0 * atan(1.0) << endl;
}