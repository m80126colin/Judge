#include <stdio.h>

#define MAX 1030
char m[MAX][MAX], str[5] = "abcd";
int dx[4] = {0, 0, 1, 1}, dy[4] = {0, 1, 0, 1};

/* x:  top - bottom */
/* y: left -  right */
void sol(int n, int x, int y, int x0, int y0, int x2, int y2, char ch)
{
	int x1, y1;
	x1 = (x0 + x2) / 2;
	y1 = (y0 + y2) / 2;
	int i, j, a, b;
	int inx[3] = {x0, x1, x2}, iny[3] = {y0, y1, y2};
	if (n > 1) ch = 'e';
	for (i = 0; i < 4; i++)
	{
		a = i / 2;
		b = i % 2;
		if (x <= inx[a + 1] && y <= iny[b + 1])
		{
			if (n > 1)
			{
				for (j = 0; j < 4; j++)
				{
					a = j / 2;
					b = j % 2;
					if (i != j) sol(n - 1, x1 + dx[j], y1 + dy[j], inx[a] + dx[j], iny[b] + dy[j], inx[a + 1], iny[b + 1], str[j]);
					else        sol(n - 1, x         , y         , inx[a] + dx[j], iny[b] + dy[j], inx[a + 1], iny[b + 1], str[j]);
				}
			}
			for (j = 0; j < 4; j++)
				if (i != j) m[x1 + dx[j]][y1 + dy[j]] = ch;
			return ;
		}
	}
	return ;
}

int main()
{
	int n, x, y;
	while (scanf("%d%d%d", &n, &y, &x) != EOF)
	{
		sol(n, x, y, 1, 1, 1 << n, 1 << n, 'e');
		m[x][y] = '*';
		for (int i = 1; i <= (1 << n); i++)
		{
			m[i][(1 << n) + 1] = '\0';
			puts(m[i] + 1);
		}
		puts("");
	}
}