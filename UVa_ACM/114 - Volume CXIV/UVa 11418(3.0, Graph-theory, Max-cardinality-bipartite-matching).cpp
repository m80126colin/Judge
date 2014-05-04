#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

#define MAX 110
int nx, ny;
int mx[MAX], my[MAX];
bool r[MAX][MAX], visited[MAX];
char rstr[MAX][MAX][MAX], tmp[MAX];

int DFS(int i)
{
	int j;
	for (j = 0; j < ny; j++)
	{
		if (!visited[j] && r[i][j])
		{
			visited[j] = 1;
			if (my[j] == -1 || DFS(my[j]))
			{
				mx[i] = j;
				my[j] = i;
				return 1;
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
		if (DFS(i)) sum++;
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
		memset(r, false, sizeof(r));
		scanf("%d", &nx);
		for (i = 0; i < nx; i++)
		{
			for (scanf("%d", &j); j; j--)
			{
				scanf("%s", tmp);
				Adjust(tmp);
				r[i][tmp[0] - 'A'] = 1;
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