#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

#define MAX 1010
struct node
{
	int key, left, right;
};
int n;
node m[MAX];

void insert(int x, int y)
{
	if (m[x].key > m[y].key)
	{
		if (m[x].left) insert(m[x].left, y);
		else m[x].left = y;
	}
	else if (m[x].key < m[y].key)
	{
		if (m[x].right) insert(m[x].right, y);
		else m[x].right = y;
	}
	return ;
}

void print(int x)
{
	printf("%d ", m[x].key);
	if (m[x].left) print(m[x].left);
	if (m[x].right) print(m[x].right);
	return ;
}

int main()
{
	int i;
	while (scanf("%d", &n) != EOF)
	{
		memset(m, 0, sizeof(m));
		for (i = 0; i < n; i++)
		{
			scanf("%d", &m[i].key);
			if (i) insert(0, i);
		}
		print(0);
		puts("");
	}
}