/**
 *  @judge UVa
 *  @id 10957
 *  @tag Sudoku, Backtracking
 */
#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

int s[9][9], cnt;

inline int input()
{
	int i, j;
	for (i = 0; i < 9; i++)
		for (j = 0; j < 9; j++)
			if (scanf("%d", &s[i][j]) == EOF)
				return EOF;
	return 0;
}

inline int CheckRow(int r)
{
	int i, tmp[10];
	memset(tmp, 0, sizeof(tmp));
	for (i = 0; i < 9; i++)
		tmp[ s[r][i] ]++;
	for (i = 1; i <= 9; i++)
		if (tmp[i] > 1) return 0;
	return 1;
}

inline int CheckColumn(int c)
{
	int i, tmp[10];
	memset(tmp, 0, sizeof(tmp));
	for (i = 0; i < 9; i++)
		tmp[ s[i][c] ]++;
	for (i = 1; i <= 9; i++)
		if (tmp[i] > 1) return 0;
	return 1;
}

inline int CheckBlock(int b)
{
	int i, j, tmp[10];
	memset(tmp, 0, sizeof(tmp));
	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			tmp[ s[(b / 3) * 3 + i][(b % 3) * 3 + j] ]++;
	for (i = 1; i <= 9; i++)
		if (tmp[i] > 1) return 0;
	return 1;
}

inline int Check()
{
	int i;
	for (i = 0; i < 9; i++)
	{
		if (!CheckRow(i)) return 0;
		if (!CheckColumn(i)) return 0;
		if (!CheckBlock(i)) return 0;
	}
	return 1;
}

int CheckD(int x, int y)
{
	int bx = (x / 3) * 3, by = (y / 3) * 3;
	int i, j;
	for (i = 0; i < 9; i++)
	{
		if (i != x && s[i][y] == s[x][y]) return 0;
		if (i != y && s[x][i] == s[x][y]) return 0;
	}
	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			if (bx + i != x && by + j != y && s[bx + i][by + j] == s[x][y])
				return 0;
	return 1;
}

inline void Backtracking(int x, int y)
{
	if (cnt > 1) return ;
	if (x >= 9)
	{
		cnt++;
		return ;
	}
	int nx, ny;
	ny = y + 1;
	nx = x;
	if (ny >= 9)
	{
		nx++;
		ny = 0;
	}
	if (s[x][y] == 0)
	{
		for (s[x][y] = 1; s[x][y] <= 9; s[x][y]++)
			if (CheckD(x, y)) Backtracking(nx, ny);
		s[x][y] = 0;
	}
	else // not zero
	{
		if (!Check()) return ;
		Backtracking(nx, ny);
	}
	return ;
}

int Sudoku()
{
	if (!Check()) return -1; // illegal
	cnt = 0;
	Backtracking(0, 0);
	return cnt;
}

int main()
{
	int t, ans;
	for (t = 1; input() != EOF; t++)
	{
		ans = Sudoku();
		printf("Case %d: ", t);
		if (ans < 0) puts("Illegal.");
		else if (ans == 0) puts("Impossible.");
		else if (ans == 1) puts("Unique.");
		else puts("Ambiguous.");
	}
}