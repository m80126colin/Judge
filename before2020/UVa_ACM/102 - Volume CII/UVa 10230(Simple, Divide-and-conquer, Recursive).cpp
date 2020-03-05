#include <stdio.h>

#define MAX 1030
char m[MAX][MAX];

/* x:  top - bottom */
/* y: left -  right */
void sol(int n, int x, int y, int x0, int y0, int x2, int y2, char ch)
{
	if (n == 0) return ;
	int x1, y1;
	x1 = (x0 + x2) / 2;
	y1 = (y0 + y2) / 2;
	if (n != 1) ch = 'e';
	if (x <= x1)
	{
		if (y <= y1) /* top-left */
		{
			sol(n - 1, x     , y     , x0    , y0    , x1, y1, 'a');
			sol(n - 1, x1    , y1 + 1, x0    , y1 + 1, x1, y2, 'b');
			sol(n - 1, x1 + 1, y1    , x1 + 1, y0    , x2, y1, 'c');
			sol(n - 1, x1 + 1, y1 + 1, x1 + 1, y1 + 1, x2, y2, 'd');
			m[x1    ][y1 + 1] = m[x1 + 1][y1    ] = m[x1 + 1][y1 + 1] = ch;
		}
		else /* top-right */
		{
			sol(n - 1, x1    , y1    , x0    , y0    , x1, y1, 'a');
			sol(n - 1, x     , y     , x0    , y1 + 1, x1, y2, 'b');
			sol(n - 1, x1 + 1, y1    , x1 + 1, y0    , x2, y1, 'c');
			sol(n - 1, x1 + 1, y1 + 1, x1 + 1, y1 + 1, x2, y2, 'd');
			m[x1    ][y1    ] = m[x1 + 1][y1    ] = m[x1 + 1][y1 + 1] = ch;
		}
	}
	else
	{
		if (y <= y1) /* bottom-left */
		{
			sol(n - 1, x1    , y1    , x0    , y0    , x1, y1, 'a');
			sol(n - 1, x1    , y1 + 1, x0    , y1 + 1, x1, y2, 'b');
			sol(n - 1, x     , y     , x1 + 1, y0    , x2, y1, 'c');
			sol(n - 1, x1 + 1, y1 + 1, x1 + 1, y1 + 1, x2, y2, 'd');
			m[x1    ][y1    ] = m[x1    ][y1 + 1] = m[x1 + 1][y1 + 1] = ch;
		}
		else /* bottom-right */
		{
			sol(n - 1, x1    , y1    , x0    , y0    , x1, y1, 'a');
			sol(n - 1, x1    , y1 + 1, x0    , y1 + 1, x1, y2, 'b');
			sol(n - 1, x1 + 1, y1    , x1 + 1, y0    , x2, y1, 'c');
			sol(n - 1, x     , y     , x1 + 1, y1 + 1, x2, y2, 'd');
			m[x1    ][y1    ] = m[x1    ][y1 + 1] = m[x1 + 1][y1    ] = ch;
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