#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;

int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
const string dir = "NSEW";

int bfs(string s, int x, int y, int st)
{
	if (st == 0)
	{
		if (x == 0 && y == 0)
		{
			puts(s.c_str());
			return 1;
		}
		return 0;
	}
	int i;
	for (i = 0; i < 4; i++)
		if (bfs(dir[i] + s, x - dx[i] * st, y - dy[i] * st, st - 1)) return 1;
	return 0;
}

int main()
{
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("B-small-attempt0.out", "w+", stdout);
	int t, cnt, x, y;
	for (scanf("%d", &t), cnt = 1; cnt <= t; cnt++)
	{
		scanf("%d%d", &x, &y);
		printf("Case #%d: ", cnt);
		for (int i = 1; i < 150; i++)
			if (bfs("", x, y, i)) break;
	}
}