/**
 *  @judge UVa
 *  @id 10810
 *  @tag Merge sort, Inversion pair
 */
// useful hint:
// 10
// 324 123 123 123 213 435 678 234 879 234
// ans: 11
#include <stdio.h>
#include <iostream>
using namespace std;

#define MAX 500010
int a[MAX];

long long MergeSort(int left, int right)
{
	if (left + 1 >= right) return 0;
	int middle = (left + right) / 2;
	long long cnt = MergeSort(left, middle) + MergeSort(middle, right);
	int i, j, k, *na = new int[right - left];
	for (i = left, j = middle, k = 0; i < middle || j < right; k++)
	{
		if (i >= middle)
			na[k] = a[j], j++;
		else if (j >= right)
			na[k] = a[i], i++;
		else if (a[j] < a[i])
		{
			na[k] = a[j], j++;
			cnt += j - (left + k) - 1;
		}
		else na[k] = a[i], i++;
	}
	for (k = 0; k < right - left; k++)
		a[left + k] = na[k];
	delete [] na;
	return cnt;
}

int main()
{
	int i, n;
	while (scanf("%d", &n), n)
	{
		for (i = 0; i < n; i++)
			scanf("%d", &a[i]);
		printf("%lld\n", MergeSort(0, n));
	}
}