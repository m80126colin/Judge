#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n, k, c, t;
	while (scanf("%d%d", &n, &k) != EOF)
	{
		t = n;
		for (c = 0; n + c >= k; t += n)
		{
			n += c;
			c = n % k;
			n /= k;
		}
		printf("%d", t);
		if (cin.peek() != EOF) puts("");
	}
}