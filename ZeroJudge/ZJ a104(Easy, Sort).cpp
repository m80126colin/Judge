#include <stdio.h>
#include <iostream>
using namespace std;

#define MAX 1010
int a[MAX], n;

int main()
{
	int i, j;
	while (scanf("%d", &n) != EOF)
	{
		for (i = 0; i < n; i++) scanf("%d", &a[i]);
		for (i = 0; i < n; i++)
			for (j =i + 1; j < n; j++)
				if (a[i] > a[j]) swap(a[i], a[j]);
		for (i = 0; i < n; i++) printf("%d ", a[i]);
		puts("");
	}
}