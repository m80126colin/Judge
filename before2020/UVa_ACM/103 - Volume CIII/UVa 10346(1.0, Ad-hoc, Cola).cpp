/**
 *  @judge UVa
 *  @id 10346
 *  @tag 1.0, Ad-hoc, Cola
 */
#include <stdio.h>
#include <iostream>
using namespace std;

int cola(int n, int k)
{
	int ans = n;
	do
	{
		ans += n / k;
		n = n % k + n / k;
	} while (n >= k);
	return ans;
}

int main()
{
	int n, k;
	while (scanf("%d%d", &n, &k) != EOF)
		printf("%d\n", cola(n, k));
}