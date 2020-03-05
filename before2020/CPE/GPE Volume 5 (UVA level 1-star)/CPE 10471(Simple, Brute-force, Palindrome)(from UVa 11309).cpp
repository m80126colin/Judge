#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;

int t, s, h, m;

bool ans()
{
	h = s/60;
	m = s%60;
	int a = h * 100 + m, b[4], i;
	for (i = 0; i < 4; i++)
	{
		b[i] = a%10;
		a /= 10;
	}
	for (i = 3; i >= 0; i--)
	{
		if (b[i]) break;
	}
	for (a = 0; a <= i; a++)
	{
		if (b[a] != b[i-a]) return 0;
	}
	return 1;
}

int main()
{
	int n;
	for (scanf("%d", &n); n; n--)
	{
		scanf("%d:%d", &h, &m);
		t = h * 60 + m;
		for (s = (t + 1) % 1440; s != t; s++)
		{
			if (s >= 1440) s %= 1440;
			if (ans())
			{
				printf("%02d:%02d\n", h, m);
				break;
			}
		}
	}
}