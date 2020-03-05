#include <cstdio>
#include <iostream>
using namespace std;

#define MAX 6
char b[MAX][MAX];
int t;

int won(char ch)
{
	int i, j, win;
	for (i = 0; i < 4; i++)
	{
		for (j = 0, win = 1; j < 4; j++)
		{
			if (b[i][j] != ch && b[i][j] != 'T')
				win = 0, j = 4;
		}
		if (win) return 1;
	}
	for (i = 0; i < 4; i++)
	{
		for (j = 0, win = 1; j < 4; j++)
		{
			if (b[j][i] != ch && b[j][i] != 'T')
				win = 0, j = 4;
		}
		if (win) return 1;
	}
	for (j = 0, win = 1; j < 4; j++)
		if (b[j][j] != ch && b[j][j] != 'T')
			win = 0, j = 4;
	if (win) return 1;
	for (j = 0, win = 1; j < 4; j++)
		if (b[j][3 - j] != ch && b[j][3 - j] != 'T')
			win = 0, j = 4;
	if (win) return 1;
	return 0;
}

int not_yet()
{
	int i, j;
	for (i = 0; i < 4; i++)
		for (j = 0; j < 4; j++)
			if (b[i][j] == '.')
				return 0;
	return 1;
}

int sol()
{
	if (won('X')) return 0;
	else if (won('O')) return 1;
	else if (not_yet()) return 2;
	return 3;
}

int main()
{
	int cnt;
	freopen("A-large.in", "r+", stdin);
	freopen("A-large.out", "w+", stdout);
	char res[4][50] = {"X won", "O won", "Draw", "Game has not completed"};
	for (scanf("%d", &t), cnt = 1; cnt <= t; cnt++)
	{
		for (int i = 0; i < 4 ; i++)
			scanf("%s", b[i]);
		printf("Case #%d: %s\n", cnt, res[sol()]);
	}
}