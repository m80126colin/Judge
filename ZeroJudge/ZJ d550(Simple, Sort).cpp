#include <iostream>
#include <algorithm>
#define N 10010
#define M 210
using namespace std;

int n, m;
int mat[N][M];
int ind[N];

bool cmp(int i, int j) {
	int k;
	for (k = 0; k < m; k++)
		if (mat[i][k] != mat[j][k])
			return mat[i][k] < mat[j][k];
	return 1;
}

int main() {
	int i, j;
	while (cin >> n >> m) {
		for (i = 0; i < n; i++) {
			ind[i] = i;
			for (j = 0; j < m; j++)
				cin >> mat[i][j];
		}
		sort(ind, ind + n, cmp);
		for (i = 0; i < n; i++) {
			for (j = 0; j < m; j++)
				cout << mat[ind[i]][j] << " ";
			cout << endl;
		}
	}
}