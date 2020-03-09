/**
 *  @judge ZeroJudge
 *  @id d263
 *  @source UVa 989
 * 
 *  @tag Simple, DFS
 */
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <ctype.h>
#define M 10
using namespace std;

int sudoku[M][M];
bool region[M][M][M], row[M][M], col[M][M];
int n, m;

inline bool ismatch(int i, int j)
{
	if (region[i/n][j/n][sudoku[i][j]] || row[i][sudoku[i][j]] || col[j][sudoku[i][j]]) return 0;
	return 1;
}

inline int DFS(int a)
{
	if (a == m * m) return 1;
	int i = a / m, j = a % m;
	if (sudoku[i][j])
	{
		if (DFS(a + 1)) return 1;
	}
	else
	{
		for (sudoku[i][j] = 1; sudoku[i][j] <= m; sudoku[i][j]++)
		{
			if (ismatch(i, j))
			{
				region[i/n][j/n][sudoku[i][j]] = 1;
				row[i][sudoku[i][j]] = 1;
				col[j][sudoku[i][j]] = 1;
				if (DFS(a + 1)) return 1;
				region[i/n][j/n][sudoku[i][j]] = 0;
				row[i][sudoku[i][j]] = 0;
				col[j][sudoku[i][j]] = 0;
			}
		}
		sudoku[i][j] = 0;
	}
	return 0;
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

int main()
{
	bool ox;
	int i, j, ctr = 0;
	while (scanf("%d", &n) != EOF)
	{
		m = n * n;
		memset(region, 0, sizeof(region));
		memset(row, 0, sizeof(row));
		memset(col, 0, sizeof(col));
		ox = 0;
		for (i = 0; i < m; i++)
		{
			for (j = 0; j < m; j++)
			{
				getd(sudoku[i][j]);
				if (sudoku[i][j])
				{
					if (!ismatch(i, j)) ox = 1;
					region[i/n][j/n][sudoku[i][j]] = row[i][sudoku[i][j]] = col[j][sudoku[i][j]] = 1;
				}
			}
		}
		if (ctr++) puts("");
		if (!ox && DFS(0))
		{
			for (i = 0; i < m; i++)
			{
				for (j = 0; j < m; j++)
				{
					if (j) putchar(' ');
					printf("%d", sudoku[i][j]);
				}
				puts("");
			}
		}
		else puts("NO SOLUTION");
	}
}