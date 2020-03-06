/**
 *  @judge UVa
 *  @id 11689
 *  @tag 1.0, Ad hoc, Cola
 */
#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
	int N, e, f, c, ans;
	for (scanf("%d", &N); N; N--)
	{
		scanf("%d%d%d", &e, &f, &c);
		e += f;
		ans = 0;
		while (e >= c)
		{
			ans += e / c;
			e = e / c + e % c;
		}
		printf("%d\n", ans);
	}
}