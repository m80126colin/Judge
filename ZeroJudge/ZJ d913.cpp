#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

int a[6][7], te[6];

int main()
{
	int i, j;
	for (i = 0; i < 6; i++)
	{
		for (j = 0; j < 7; j++)
			 scanf("%d", &a[i][j]);
	}
	for (i = 0; i < 6; i++)
		te[i] = i + 1;
	do
	{
		int cnt, cor;
		cor = 0;
		for (i = 0; i < 6; i++)
		{
			cnt = 0;
			for (j = 0; j < 6; j++)
			{
				if (te[j] == a[i][j]) cnt++;
			}
			if (6 == j && cnt == a[i][6]) cor++;
		}
		if (cor == 6)
		{
			for (i = 0; i < 6; i++)
				printf("%d ", te[i]);
			puts("");
			break;
		}
	} while (next_permutation(te, te + 6));
}