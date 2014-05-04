#include <stdio.h>
#include <iostream>
using namespace std;

#define MAX 100010
int n, a[MAX];
long long ans;

void Merge_sort(int left, int right)
{
	if (left + 1 == right) return ;
	int middle = (left + right) / 2;
	Merge_sort(left, middle);
	Merge_sort(middle, right);
	int i, j, k, len;
	int *tmp;
	i = left;
	j = middle;
	len = right - left;
	tmp = new int[len];
	for (k = 0; k < len; k++)
	{
		if (i == middle) tmp[k] = a[j++];
		else if (j == right) tmp[k] = a[i++];
		else if (a[i] <= a[j]) tmp[k] = a[i++];
		else
		{
			tmp[k] = a[j++];
			ans += (middle - i);
		}
	}
	for (k = 0; k < len; k++)
		a[left + k] = tmp[k];
	delete [] tmp;
	return ;
}

int main()
{
	int i;
	while (scanf("%d", &n), n)
	{
		ans = 0;
		for (i = 0; i < n; i++) scanf("%d", &a[i]);
		Merge_sort(0, n);
		if (ans & 1) puts("Marcelo");
		else puts("Carlos");
	}
}