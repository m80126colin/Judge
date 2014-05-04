#include <stdio.h>
#include <ctype.h>
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

inline void getd(int &d)
{
	char ch;
	while (!isdigit(ch = getchar())) ;
	d = 0;
	do {
		d = d * 10 + ch - '0';
	} while (isdigit(ch = getchar()));
	return;
}

int main() {
	int i, j;
	while (scanf("%d%d", &n, &m) != EOF) {
		for (i = 0; i < n; i++) {
			ind[i] = i;
			for (j = 0; j < m; j++)
				getd(mat[i][j]);
		}
		sort(ind, ind + n, cmp);
		for (i = 0; i < n; i++) {
			for (j = 0; j < m; j++)
				printf("%d ", mat[ind[i]][j]);
			puts("");
		}
	}
}