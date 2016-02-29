#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

string s;

int main()
{
	int n, ctr, t, i;
	for (scanf("%d", &t), ctr = 1; ctr <= t; ctr++)
	{
		scanf("%d", &n);
		/*
		-5 -> 001111
		-4 -> 001100
		-3 -> 001101
		-2 -> 000010
		-1 -> 000011
		 0 -> 000000	-> 0
		 1 -> 000001	-> 1
		 2 -> 000110	-> 10
		 3 -> 000111	-> 11
		 4 -> 000100	-> 100
		 5 -> 000101	-> 101
		 6 -> 011010	-> 110
		 7 -> 011011	-> 111
		 8 -> 011000	-> 1000
		 9 -> 011001	-> 1001
		10 -> 011110	-> 1010
		11 -> 011111	-> 1011
		*/
		for (s = ""; n; n >>= 2)
		{
			i = (n % 4 + 4) % 4;
			if (i < 2)
			{
				if (i == 0) s += "00";
				else if (i == 1) s += "10";
			}
			else
			{
				n += 2;
				if (i == 2) s += "01";
				else s += "11";
			}
		}
		printf("Case #%d: ", ctr);
		for (i = s.size() - 1; i >= 0 && s[i] == '0'; i--) ;
		if (i < 0) putchar('0');
		for (; i >= 0; i--) putchar(s[i]);
		puts("");
	}
}