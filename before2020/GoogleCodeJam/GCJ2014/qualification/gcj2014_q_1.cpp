#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
	//freopen("A-small-attempt0.in", "r+", stdin);
	//freopen("A-small-attempt0.out", "w+", stdout);
	int t, cnt, ans[16], res, ptr, i, row;
	for (scanf("%d", &t), cnt = 1; cnt <= t; cnt++)
	{
		for (i = 0; i < 16; i++)
			ans[i] = 0;
		scanf("%d", &row);
		for (i = 0; i < 16; i++)
		{
			int tmp;
			scanf("%d", &tmp);
			if (i / 4 == row - 1)
				ans[tmp - 1]++;
		}
		scanf("%d", &row);
		for (i = 0; i < 16; i++)
		{
			int tmp;
			scanf("%d", &tmp);
			if (i / 4 == row - 1)
				ans[tmp - 1]++;
		}
		res = ptr = 0;
		for (i = 0; i < 16; i++)
		{
			if (ans[i] == 2)
			{
				res++;
				ptr = i;
			}
		}
		printf("Case #%d: ", cnt);
		if (res == 0) puts("Volunteer cheated!");
		else if (res == 1) printf("%d\n", ptr + 1);
		else puts("Bad magician!");
	}
}