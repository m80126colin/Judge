#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <string>
#define MAX 1010
using namespace std;

struct era
{
	int last, year;
	char name[20];
}tai[MAX];
int n, q;

int bi_search(int left, int right, int num)
{
	if (left >= right) return -1;
	if (left + 1 == right)
	{
		if (tai[left].year <= num) return left;
		return -1;
	}
	int middle = (left + right) / 2;
	if (num < tai[middle].year && num >= tai[middle - 1].year)
		return middle - 1;
	if (num >= tai[middle].year)
		return bi_search(middle, right, num);
	return bi_search(left, middle, num);
}

bool cmp(era l, era r)
{
	return l.year < r.year;
}

int main()
{
	int i, tmp, pl;
	while (scanf("%d%d",&n,&q), (n||q))
	{
		for (i = 0; i < n; i++)
		{
			scanf("%s%d%d", &tai[i].name, &tai[i].last, &tai[i].year);
			tai[i].year -= tai[i].last;
			tai[i].year++;
		}
		sort(tai, tai+n, cmp);
		/*for (i = 0; i < n; i++)
			printf("%s %d %d\n", tai[i].name, tai[i].last, tai[i].year);*/
		for (i = 0; i < q; i++)
		{
			scanf("%d", &tmp);
			pl = bi_search(0, n, tmp);
			//printf("%d\n", pl);
			if (pl == -1)
				puts("Unknown");
			else
			{
				if (tmp - tai[pl].year <= tai[pl].last - 1)
					printf("%s %d\n", tai[pl].name, tmp - tai[pl].year + 1);
				else puts("Unknown");
			}
		}
	}
}