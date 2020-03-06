/**
 *  @judge TIOJ
 *  @id 1513
 *  @tag Bitwise operation
 */
#include <stdio.h>
#include <ctype.h>
#include <iostream>
using namespace std;

inline void getd(unsigned int &d)
{
	char ch;
	while (!isdigit(ch = getchar()));
	d = 0;
	do {
		d *= 10; d += ch - '0';
	} while (isdigit(ch = getchar()));
	return;
}

int main()
{
	unsigned int n, s, t, i;
	while (scanf("%u", &n) != EOF)
	{
		for (i = s = 0; i < n; i++)
			getd(t), s ^= t;
		printf("%u\n", s);
	}
}