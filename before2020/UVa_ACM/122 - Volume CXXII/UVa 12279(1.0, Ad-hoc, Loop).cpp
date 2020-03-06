/**
 *  @judge UVa
 *  @id 12279
 *  @tag 1.0, Ad hoc, Loop
 */
#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
	int ans = 0, n, i, cnt, tmp;
	for (cnt = 1; scanf("%d", &n), n; cnt++)
	{
		for (i = ans = 0; i < n; i++)
		{
			scanf("%d", &tmp);
			ans += (tmp != 0) - (tmp == 0);
		}
		printf("Case %d: %d\n", cnt, ans);
	}
}