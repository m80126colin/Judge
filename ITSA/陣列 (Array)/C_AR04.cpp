#include <stdio.h>
#include <string.h>
#include <iostream>
#define MAX 100
using namespace std;

int n, m;
int maze[MAX][MAX];

int isbound(int i, int j) {
	int ans = maze[i-1][j] + maze[i+1][j] + maze[i][j-1] + maze[i][j+1];
	if (ans < 4) return 1;
	return 0;
}

int main() {
	int t, i, j;
	for (scanf("%d", &t); t; t--) {
		memset(maze, 0, sizeof(maze));
		scanf("%d%d", &n, &m);
		for (i = 1; i <= n; i++)
			for (j = 1; j <= m; j++)
				scanf("%d", &maze[i][j]);
		for (i = 1; i <= n; i++) {
			for (j = 1; j <= m; j++) {
				if (maze[i][j] && isbound(i, j)) putchar('0');
				else putchar('_');
				if (j < m) putchar(' ');
			}
			puts("");
		}
		if (t > 1) puts("");
	}
}