/**
 *  @judge UVa
 *  @id 10196
 *  @tag Simple, Simulation, Ad-hoc, Board game, Chess
 */
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string>
using namespace std;

char B[10][10];
string check = "Kk";

int Input()
{
	int i, j;
	memset(B, 0, sizeof(B));
	for (i = 1; i <= 8; i++)
	{
		for (j = 1; j <= 8; j++)
			if ((B[i][j] = getchar()) == EOF)
				return EOF;
		getchar();
	}
	getchar();
	for (i = 1; i <= 8; i++)
		for (j = 1; j <= 8; j++)
			if (B[i][j] != '.')
				return 1;
	return EOF;
}

int Pawn(int x, int y, int w, int p)
{
	if (B[x + w][y - 1] == check[p] || B[x + w][y + 1] == check[p])
		return 1;
	return 0;
}

int King(int x, int y, int p)
{
	int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
	int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
	int i;
	for (i = 0; i < 8; i++)
		if (B[x +dx[i]][y + dy[i]] == check[p])
			return 1;
	return 0;
}

int Bishop(int x, int y, int p)
{
	int dx[4] = {-1, -1, 1, 1};
	int dy[4] = {-1, 1, -1, 1};
	int i, j, tx, ty;
	char b;
	for (i = 0; i < 4; i++)
	{
		tx = x, ty = y;
		for (j = 1; 1; j++)
		{
			tx += dx[i];
			ty += dy[i];
			if (tx < 0 || tx > 8 || ty < 0 || ty > 8) break;
			b = B[tx][ty];
			if ((b >= 'A' && b <= 'Z') || (b >= 'a' && b <= 'z'))
			{
				if (b == check[p]) return 1;
				else break;
			}
		}
	}
	return 0;
}

int Rook(int x, int y, int p)
{
	int dx[4] = {-1, 0, 0, 1};
	int dy[4] = {0, 1, -1, 0};
	int i, j, tx, ty;
	char b;
	for (i = 0; i < 4; i++)
	{
		tx = x, ty = y;
		for (j = 1; 1; j++)
		{
			tx += dx[i];
			ty += dy[i];
			if (tx < 0 || tx > 8 || ty < 0 || ty > 8) break;
			b = B[tx][ty];
			if ((b >= 'A' && b <= 'Z') || (b >= 'a' && b <= 'z'))
			{
				if (b == check[p]) return 1;
				else break;
			}
		}
	}
	return 0;
}

int kNight(int x, int y, int p)
{
	int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
	int dy[8] = {1, 2, -2, -1, 1, 2, -2, -1};
	int i, tx, ty;
	for (i = 0; i < 8; i++)
	{
		tx = x + dx[i];
		ty = y + dy[i];
		if (tx < 0 || tx > 8 || ty < 0 || ty > 8) continue;
		if (B[tx][ty] == check[p])
			return 1;
	}
	return 0;
}

int Judge()
{
	int i, j;
	for (i = 1; i <= 8; i++)
		for (j = 1; j <= 8; j++)
		{
			if (B[i][j] >= 'A' && B[i][j] <= 'Z')
			{
				if (B[i][j] == 'P' && Pawn(i, j, -1, 1)) return 1;
				else if (B[i][j] == 'K' && King(i, j, 1)) return 1;
				else if (B[i][j] == 'B' && Bishop(i, j, 1)) return 1;
				else if (B[i][j] == 'R' && Rook(i, j, 1)) return 1;
				else if (B[i][j] == 'Q' && (Bishop(i, j, 1) || Rook(i, j, 1))) return 1;
				else if (B[i][j] == 'N' && kNight(i, j, 1)) return 1;
			}
			else if (B[i][j] >= 'a' && B[i][j] <= 'z')
			{
				if (B[i][j] == 'p' && Pawn(i, j, 1, 0)) return -1;
				else if (B[i][j] == 'k' && King(i, j, 0)) return -1;
				else if (B[i][j] == 'b' && Bishop(i, j, 0)) return -1;
				else if (B[i][j] == 'r' && Rook(i, j, 0)) return -1;
				else if (B[i][j] == 'q' && (Bishop(i, j, 0) || Rook(i, j, 0))) return -1;
				else if (B[i][j] == 'n' && kNight(i, j, 0)) return -1;
			}
		}
		return 0;
}

int main()
{
	int t, s;
	for (t = 1; Input() != EOF; t++)
	{
		s = Judge();
		if (s > 0) printf("Game #%d: black king is in check.\n", t);
		else if (s < 0) printf("Game #%d: white king is in check.\n", t);
		else printf("Game #%d: no king is in check.\n", t);
	}
}