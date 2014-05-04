#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

#define MAX 10010
int n, m, L, visited[MAX];
vector<int> edge[MAX];

void input()
{
	int i, a, b;
	scanf("%d%d%d", &n, &m, &L);
	for (i = 1; i <= n; i++)
		edge[i].clear();
	for (i = 0; i < m; i++)
	{
		scanf("%d%d", &a, &b);
		edge[a].push_back(b);
	}
	return ;
}

int DFS(int x)
{
	int ans = 1;
	visited[x] = 1;
	int i, j;
	for (i = 0; i < edge[x].size(); i++)
	{
		j = edge[x][i];
		if (!visited[j]) ans += DFS(j);
	}
	return ans;
}

int sol()
{
	int i, ans, tmp;
	memset(visited, 0, sizeof(visited));
	for (i = ans = 0; i < L; i++)
	{
		scanf("%d", &tmp);
		if (!visited[tmp]) ans += DFS(tmp);
	}
	return ans;
}

int main()
{
	int t;
	for (scanf("%d", &t); t; t--)
	{
		input();
		printf("%d\n", sol());
	}
}