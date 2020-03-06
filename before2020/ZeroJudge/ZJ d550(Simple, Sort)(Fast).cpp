/**
 *  @judge ZeroJudge
 *  @id d550
 *  @tag Simple, Sort
 */
#include <stdio.h>
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
	while (scanf("%d%d", &n, &m) != EOF) {
		for (i = 0; i < n; i++) {
			ind[i] = i;
			for (j = 0; j < m; j++)
				scanf("%d", &mat[i][j]);
		}
		sort(ind, ind + n, cmp);
		for (i = 0; i < n; i++) {
			for (j = 0; j < m; j++)
				printf("%d ", mat[ind[i]][j]);
			puts("");
		}
	}
}