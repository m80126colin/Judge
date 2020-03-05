#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

int main()
{
	int a, b, ctr, carry;
	while (cin >> a >> b && (a || b))
	{
		carry = 0;
		for (ctr = 0; a || b || carry; a /= 10, b /= 10)
		{
			if (a % 10 + b % 10 + carry >= 10)
			{
				ctr++;
				carry = 1;
			}
			else carry = 0;
		}
		if (ctr)
		{
			if (ctr > 1) printf("%d carry operations.\n", ctr);
			else puts("1 carry operation.");
		}
		else puts("No carry operation.");
	}
}