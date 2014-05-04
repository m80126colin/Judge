#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string>
using namespace std;

char B[10][10];
int cx, cy;

int Pawn(int x, int y, int w, int p)
{
	if ((x + w == cx && y - 1 == cy) || (x + w == cx && y + 1 == cy)) return 1;
	return 0;
}

int King(int x, int y, int p)
{
	int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
	int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
	int i;
	for (i = 0; i < 8; i++)
		if (x + dx[i] == cx && y + dy[i] == cy)
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
				break;
			if (tx == cx && ty == cy)
				return 1;
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
				break;
			if (tx == cx && ty == cy)
				return 1;
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
		if (tx == cx && ty == cy)
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
				if (B[i][j] == 'P' && Pawn(i, j, -1, 0)) return 1;
				else if (B[i][j] == 'K' && King(i, j, 0)) return 1;
				else if (B[i][j] == 'B' && Bishop(i, j, 0)) return 1;
				else if (B[i][j] == 'R' && Rook(i, j, 0)) return 1;
				else if (B[i][j] == 'Q' && (Bishop(i, j, 0) || Rook(i, j, 0))) return 1;
				else if (B[i][j] == 'N' && kNight(i, j, 0)) return 1;
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
	int t, s, i, j, k;
	string BB;
	for (t = 1; cin >> BB; t++)
	{
		memset(B, 0, sizeof(B));
		i = j = 1;
		for (k = 0; k < BB.size(); k++)
		{
			if (BB[k] >= '0' && BB[k] <= '9')
			{
				for (s = BB[k] - '0'; s; s--)
				{
					B[i][j] = '.';
					j++;
				}
			}
			else if (BB[k] == '/')
			{
				i++;
				j = 1;
			}
			else
			{
				B[i][j] = BB[k];
				j++;
			}
		}
		int ans = 0;
		for (cx = 1; cx <= 8; cx++)
			for (cy = 1; cy <= 8; cy++)
				if (B[cx][cy] == '.' && !Judge())
					ans++;
		printf("%d\n", ans);
	}
}