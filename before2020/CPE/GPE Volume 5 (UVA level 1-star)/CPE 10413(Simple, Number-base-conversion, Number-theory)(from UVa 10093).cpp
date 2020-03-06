/**
 *  @judge CPE
 *  @id 10413
 *  @tag Simple, Number base conversion, Number theory
 */
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <iostream>
using namespace std;

int lowalph;

inline int input(int &d)
{
	int s;
	char ch;
	while (!isalnum(ch = getchar()))
		if (ch == EOF) return EOF;
	d = 0;
	do {
		if (ch >= '0' && ch <= '9') s = ch - '0';
		else if (ch >= 'A' && ch <= 'Z') s = ch - 'A' + 10;
		else s = ch - 'a' + 36;
		lowalph = max(lowalph, s);
		d += s;
	} while(isalnum(ch = getchar()));
	return 0;
}

int main()
{
	int i, d;
	for (lowalph = 0; input(d) != EOF; lowalph = 0)
	{
		for (i = max(1, lowalph); i < 62; i++)
			if (0 == d % i) break;
		if (i < 62) printf("%d\n", i + 1);
		else puts("such number is impossible!");
	}
}