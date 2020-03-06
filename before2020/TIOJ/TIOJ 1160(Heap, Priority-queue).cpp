/**
 *  @judge TIOJ
 *  @id 1160
 *  @tag Heap, Priority queue
 */
#include <stdio.h>
#include <ctype.h>
#include <vector>
#include <iostream>
#include <map>
using namespace std;

struct node
{
	int num, tim;
	node() {}
	node(int n, int t): num(n), tim(t) {}
};
vector <node> heap;
map <int, int> hash;

inline void adjust(int x)
{
	int y;
	for (y = x >> 1; y && (heap[y].tim < heap[x].tim || (heap[y].tim == heap[x].tim && heap[y].num > heap[x].num)); y >>= 1)
	{
		swap(hash[heap[y].num], hash[heap[x].num]);
		swap(heap[y], heap[x]);
		x = y;
	}
	return ;
}

inline int getd(int &d)
{
	char ch;
	while (!isdigit(ch = getchar()));
	d = 0;
	do {
		d *= 10; d += ch - '0';
	} while (isdigit(ch = getchar()));
	return 1;
}

int main()
{
	int n, i;
	while (scanf("%d", &n) != EOF) {
		heap.clear();
		heap.push_back(node(0, 0));
		heap.push_back(node(n, 1));
		hash.clear();
		printf("%d %d\n", heap[1].tim, heap[1].num);
		hash[n] = 1;
		while (getd(n), n)
		{
			if ((i = hash[n]) == 0) 
				i = hash[n] = heap.size(), heap.push_back(node(n, 1));
			else heap[i].tim++;
			adjust(i);
			printf("%d %d\n", heap[1].tim, heap[1].num);
		}
	}
}