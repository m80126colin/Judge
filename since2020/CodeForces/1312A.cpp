/**
 *  @judge CodeForces
 *  @id 1312A
 *  @name Two Regular Polygons
 *  @contest Educational Codeforces Round 83
 * 
 *  @tag Geometry
 */
#include <iostream>
using namespace std;

int n, m;

int main() {
	int t;
	for (cin >> t; t; t--) {
		cin >> n >> m;
		if (n % m == 0)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}