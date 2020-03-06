/**
 *  @judge UVa
 *  @id 10035
 *  @tag 1.0, Ad-hoc, Addition
 */
#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
	int a, b, carry, ans;
	while (scanf("%d%d", &a, &b), (a || b))
	{
		for (ans = carry = 0; a || b; a /= 10, b /= 10)
			if (carry = (a % 10 + b % 10 + carry) / 10)
				ans++;
		if (ans == 0) puts("No carry operation.");
		else if (ans == 1) puts("1 carry operation.");
		else printf("%d carry operations.\n", ans);
	}
}