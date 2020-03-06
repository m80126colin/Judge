/**
 *  @judge UVa
 *  @id 275
 *  @tag Simple, Cycle finding, Floyd cycle finding algorithm
 */
#include <stdio.h>
#include <iostream>
using namespace std;

int a, b, count;

inline int f(int x)
{
	return (x * 10) % b;
}

int iscycle(int x)
{
	while (x % 2 == 0)
		x /= 2;
	while (x % 5 == 0)
		x /= 5;
	return x != 1;
}

void Putchar(char ch)
{
	if (count >= 50)
	{
		puts("");
		count = 0;
	}
	putchar(ch);
	count++;
}

int gcd(int a, int b)
{
	if (b) return gcd(b, a % b);
	return a;
}

int main()
{
	int turtle, rabbit, cycle, t;
	while (scanf("%d%d", &a, &b), (a || b))
	{
		t = gcd(a, b);
		a /= t;
		b /= t;
		count = 0;
		if (iscycle(b))
		{
			//---floyd cycle finding algorithm---
			turtle = f(a);
			rabbit = f( f(a) );
			while (turtle != rabbit)
			{
				turtle = f(turtle);
				rabbit = f( f(rabbit) );
			}
			rabbit = a;
			while (turtle != rabbit)
			{
				turtle = f(turtle);
				rabbit = f(rabbit);
			}
			turtle = f(turtle);
			cycle = 1;
			while (turtle != rabbit)
			{
				turtle = f(turtle);
				cycle++;
			}
			//----------------------------------
			Putchar('.');
			rabbit = a;
			while (turtle != rabbit)
			{
				Putchar(rabbit * 10 / b + '0');
				rabbit = f(rabbit);
			}
			do
			{
				Putchar(rabbit * 10 / b + '0');
				rabbit = f(rabbit);
			} while (turtle != rabbit);
			puts("");
			printf("The last %d digits repeat forever.\n", cycle);
		}
		else
		{
			Putchar('.');
			while (a)
			{
				Putchar(a * 10 / b + '0');
				a = f(a);
			}
			puts("\nThis expansion terminates.");
		}
		puts("");
	}
}