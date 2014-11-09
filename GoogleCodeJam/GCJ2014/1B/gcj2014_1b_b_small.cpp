#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("B-small-attempt0.out", "w+", stdout);
	int a, b, k, t, cnt, res;
	for (scanf("%d", &t), cnt = 1; cnt <= t; cnt++)
	{
		res = 0;
		scanf("%d%d%d", &a, &b, &k);
		for (int i = 0; i < a; i++)
			for (int j = 0; j < b; j++)
				if ((i & j) < k)
					res++;
		printf("Case #%d: %d\n", cnt, res);
	}
}