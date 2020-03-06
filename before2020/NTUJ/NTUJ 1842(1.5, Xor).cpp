/**
 *  @judge NTUJ
 *  @id 1842
 *  @tag 1.5, Xor
 */
#include <cstdio>
#include <iostream>
#include <map>
using namespace std;

#define N 10010
int a[N], b[N], n;
map<int , int> M;

int input()
{
	M.clear();
	if (scanf("%d", &n) == EOF)
		return 0;
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &b[i]);
		M[b[i]]++;
	}
	return 1;
}

int sol()
{
	int ans = 0;
	for (int i = 0; i < n; i++)
		ans ^= (a[i] ^ b[i]);
	for (int i = 0; i < n; i++)
		M[a[i] ^ ans]--;
	map<int, int>::iterator it;
	for (it = M.begin(); it != M.end(); it++)
		if (it->second != 0)
			return -1;
	return ans;
}

int main()
{
	while (input())
		printf("%d\n", sol());
}