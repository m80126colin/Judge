#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

#define N 10010
int a[N];

int main() {
	int i, j, h;
	memset(a, 0, sizeof(a));
	while (scanf("%d%d%d", &i, &h, &j) != EOF)
	{
		for (i; i < j; i++)
			if (h > a[i])
				a[i] = h;
	}
	printf("1 %d", a[1]);
	for (i = 2; i < 10000; i++)
	{
		if (a[i] != a[i - 1])
			printf(" %d %d", i, a[i]);
	}
	puts("");
}