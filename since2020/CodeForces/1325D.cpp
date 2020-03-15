/**
 *  @judge CodeForces
 *  @id 1325D
 *  @name Ehab the Xorcist
 *  @contest Codeforces Round #628
 * 
 *  @tag Math, Greedy, Binary Operations
 */
#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long int ULL;
ULL u, v;

int main() {
	cin >> u >> v;
	if (u > v || (u != 0 && v == 0) || (v - u) % 2)
		cout << "-1" << endl;
	else if (u == 0 && v == 0)
		cout << "0" << endl;
	else if (u == v)
		cout << "1" << endl << u << endl;
	else {
		ULL t = (v - u) / 2;
		if ((u & t) == 0) {
			cout << "2" << endl;
			cout << t << " " << u + t << endl;
		}
		else {
			cout << "3" << endl;
			cout << t << " " << t << " " << u << endl;
		}
	}
}