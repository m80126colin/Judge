/**
 *  @judge UVa
 *  @id 414
 *  @tag Easy, Ad hoc, Encoding
 */
#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n, cnt, i, j, mx, a[20];
	string s;
	while (scanf("%d", &n), n)
	{
		cin.ignore(1);
		for (i = mx = 0; i < n; i++)
		{
			getline(cin, s);
			for (j = a[i] = 0; j < 25; j++)
				if (s[j] == 'X') a[i]++;
			if (a[i] > mx) mx = a[i];
		}
		for (i = cnt = 0; i < n; i++) cnt += mx - a[i];
		printf("%d\n", cnt);
	}
}