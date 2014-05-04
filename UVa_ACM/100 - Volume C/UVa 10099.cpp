#include <iostream>
#include <string.h>
using namespace std;

int map[101][101];

int main() {
	int n, r, i, j, k, l, t;
	for (t = 1; cin >> n >> r, n || r; t++)
	{
		memset(map, 0, sizeof(map));
		for (i = 1; i <= r; i++) cin >> j >> k >> l, map[k][j] = map[j][k] = l;
		for (k = 1; k <= n; k++)
			for (i = 1; i <= n; i++)
				for (j = 1; j <= n; j++)
					map[i][j] = max(map[i][j], min(map[i][k], map[k][j]));
		cin >> i >> j >> k;
		cout << "Scenario #" << t << "\nMinimum Number of Trips = " << ((k%(map[i][j]-1)) ? k/(map[i][j]-1)+1 : k/(map[i][j]-1) ) << endl << endl;
	}
}