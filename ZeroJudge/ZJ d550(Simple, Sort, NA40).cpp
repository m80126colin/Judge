#include <iostream>
#define N 10010
#define M 110
using namespace std;

int mat[N][M];
int ind[N];

int main() {
	int i, j, k;
	int n, m;
	while (cin >> n >> m) {
		for (i = 0; i < n; i++) {
			ind[i] = i;
			for (j = 0; j < m; j++)
				cin >> mat[i][j];
		}
		for (i = 0; i < n; i++)
			for (k = i + 1; k < n; k++)
				for (j = 0; j < m; j++)
					if (mat[ind[i]][j] != mat[ind[k]][j])
					{
						if (mat[ind[i]][j] > mat[ind[k]][j])
							swap(ind[i], ind[k]);
						break;
					}
		for (i = 0; i < n; i++) {
			for (j = 0; j < m; j++) {
				if (j) cout << " ";
				cout << mat[ind[i]][j];
			}
			cout << endl;
		}
	}
}