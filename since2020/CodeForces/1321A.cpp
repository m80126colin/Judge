/**
 *  CodeForces 1321A, Round #625 div.2 A
 *  Contest for Robots
 * 
 *  Tags: Ad-hoc, Math
 */
#include <iostream>
using namespace std;

#define MAX 110

int a[MAX], b[MAX];

int solve(int n) {
	int A, B, C;
	A = B = C = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] == 1)
			A++;
		if (b[i] == 1)
			B++;
		if (a[i] > b[i])
			C++;
	}
	if (C == 0)
		return -1;
	return (B - A + C + C) / C;
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
		cin >> b[i];
	cout << solve(n) << endl;
}