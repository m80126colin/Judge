#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	int num[] = {0, 1, 2, 5, 14, 42, 132, 429, 1430, 4862, 16796, 58786, 208012, 742900, 2674440, 9694845, 35357670, 129644790, 477638700, 1767263190};
	while (scanf("%d", &n) != EOF)
		printf("%d\n", lower_bound(num, num + 20, n) - num);
}