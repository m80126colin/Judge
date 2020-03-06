/**
 *  @judge Light
 *  @id 1000
 *  @tag Easy, a+b problem, stdio
 */
#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
	int t, cnt, a, b;
	for (scanf("%d", &t), cnt = 1; cnt <= t; cnt++)
	{
		scanf("%d%d", &a, &b);
		printf("Case %d: %d\n", cnt, a + b);
	}
}