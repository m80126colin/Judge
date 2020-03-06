/**
 * @judge CodeForces
 * @id 1316A
 * @name Grade Allocation
 * @contest CodeCraft-20 (Div. 2)
 * 
 * @tag Simple Math, Ad-hoc
 */
#include <iostream>
using namespace std;

#define MAX 1010

int n, m, stu[MAX];

int solve() {
	int tot = 0;
	for (int i = 0; i < n; i++)
		tot += stu[i];
	return min(tot, m);
}

int main() {
	int t;
	for (cin >> t; t; t--) {
		cin >> n >> m;
		for (int i = 0; i < n; i++)
			cin >> stu[i];
		cout << solve() << endl;
	}
}