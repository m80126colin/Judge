/**
 *  @judge CPE
 *  @id 10431
 *  @tag Easy, Ad hoc
 */
#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int x, n, tmp;
	long long sum;
	vector <int> v;
	while (scanf("%d", &x) != EOF)
	{
		cin.ignore();
		for (v.clear(); cin.peek() != '\n'; v.push_back(tmp)) scanf("%d", &tmp);
		for (n = v.size() - 1, sum = 0; n; n--)
			sum = (long long) sum * x + v[v.size() - n - 1] * n;
		printf("%lld\n", sum);
	}
}