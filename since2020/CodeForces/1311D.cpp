/**
 *  @judge CodeForces
 *  @id 1311D
 *  @name Three Integers
 *  @contest CodeForces Round #624 div.3
 * 
 *  @tag Math, Ad-hoc
 */
#include <iostream>
using namespace std;

int x, y, z;

int calDA(int a, int B) {
	int ans, L, R;
	ans = 1 - a;
	for (int i = 1; i * i <= B; i++) {
		if (B % i == 0) {
			L = i, R = B / i;
			if (abs(a - L) < abs(ans))
				ans = - (a - L);
			if (abs(a - R) < abs(ans))
				ans = - (a - R);
		}
	}
	return ans;
}

int calDC(int c, int B) {
	if (B - c % B < c % B)
		return B - c % B;
	return - c % B;
}

int setTriple(int a, int b, int c) {
	x = a, y = b, z = c;
}

int solve(int a, int b, int c) {
	int ans, tmp, da, dc;
	da = calDA(a, b);
	dc = calDC(c, b);
	ans = abs(da) + abs(dc);
	setTriple(a + da, b, c + dc);
	for (int db = 1; db <= max(c - b, b - a); db++) {
		da = calDA(a, b + db);
		dc = calDC(c, b + db);
		tmp = abs(da) + db + abs(dc);
		if (tmp < ans) {
			ans = tmp;
			setTriple(a + da, b + db, c + dc);
		}
		if (b - db > 0) {
			da = calDA(a, b - db);
			dc = calDC(c, b - db);
			tmp = abs(da) + db + abs(dc);
			if (tmp < ans) {
				ans = tmp;
				setTriple(a + da, b - db, c + dc);
			}
		}
	}
	return ans;
}

int main() {
	int t, a, b, c;
	for (cin >> t; t; t--) {
		cin >> a >> b >> c;
		cout << solve(a, b, c) << endl;
		cout << x << " " << y << " " << z << endl;
	}
}