#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;

#define MAX 110
int nx, ny;
int mx[MAX], my[MAX];
int edge[MAX][MAX], visited[MAX], path[MAX];
char rstr[MAX][MAX][MAX], tmp[MAX];

int BFS(int i)
{
	int u, v;
	queue<int> Q;
	Q.push(i);
	path[i] = -1;
	while (!Q.empty())
	{
		u = Q.front();
		Q.pop();
		for (v = 0; v < ny; v++)
		{
			if (edge[u][v] && !visited[v])
			{
				visited[v] = 1;
				Q.push(my[v]);
				if (my[v] == -1) // find path
				{
					int du = u, dv = v;
					while (du != -1)
					{
						int tmp = mx[du];
						mx[du] = dv;
						my[dv] = du;
						du = path[du];
						dv = tmp;
					}
					return 1;
				}
				else path[my[v]] = u;
			}
		}
	}
	return 0;
}

int match()
{
	int i, sum = 0;
	memset(mx, -1, sizeof(mx));
	memset(my, -1, sizeof(my));
	for (i = 0; i < nx; i++)
	{
		memset(visited, 0, sizeof(visited));
		if (BFS(i)) sum++;
	}
	return sum;
}

void Adjust(char *str)
{
	int i, len = strlen(str);
	for (i = 0; i < len; i++)
	{
		if (i)
		{
			if (str[i] >= 'A' && str[i] <= 'Z')
				str[i] = str[i] - 'A' + 'a';
		}
		else
		{
			if (str[i] >= 'a' && str[i] <= 'z')
				str[i] = str[i] - 'a' + 'A';
		}
	}
	return ;
}

int main()
{
	int t, cnt, i, j, ans;
	for (scanf("%d", &t), cnt = 1; cnt <= t; cnt++)
	{
		memset(edge, false, sizeof(edge));
		scanf("%d", &nx);
		for (i = 0; i < nx; i++)
		{
			for (scanf("%d", &j); j; j--)
			{
				scanf("%s", tmp);
				Adjust(tmp);
				edge[i][tmp[0] - 'A'] = 1;
				strcpy(rstr[i][tmp[0] - 'A'], tmp);
			}
		}
		ny = nx;
		ans = match();
		printf("Case #%d:\n", cnt);
		for (j = 0; j < ny; j++)
			puts(rstr[my[j]][j]);
	}
}