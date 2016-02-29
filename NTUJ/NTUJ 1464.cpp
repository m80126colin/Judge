#include <stdio.h>
#include <ctype.h>
#include <iostream>
#define MAX 100010
using namespace std;
struct point{
	int ptr, num;
	long long sum;
}head[MAX];
int a[MAX];
int n, m;

void input(int &d) {
	char ch;
	while (!isdigit(ch = getchar()));
	d = 0;
	do{
		d = d * 10 + ch - '0';
	}while (isdigit(ch = getchar()));
}

int find(int x) {
	return (head[x].ptr) ? find(head[x].ptr): x;
}

inline void union_(int p, int q) {
	int x = find(a[p]);
	int y = find(a[q]);
	if (x == y) return;
	if (head[x].num > head[y].num) swap(x, y);
	head[y].num += head[x].num;
	head[y].sum += head[x].sum;
	head[x].ptr = y;
	return;
}

inline void move_(int p, int q) {
	int x = find(a[p]);
	int y = find(a[q]);
	if (x == y) return;
	head[x].num--;
	head[x].sum -= p;
	a[p] = y;
	head[y].num++;
	head[y].sum += p;
	return;
}

inline void print_(int p) {
	int x = find(a[p]);
	printf("%d %lld\n", head[x].num, head[x].sum);
}

int main() {
	int i, cmd, p, q;
	while (scanf("%d%d",&n,&m)!=EOF) {
		for (i = 1; i <= n; i++) {
			a[i] = i;
			head[i].ptr = 0;
			head[i].num = 1;
			head[i].sum = i;
		}
		for (i = 1; i <= m; i++) {
			scanf("%d", &cmd);
			if (cmd == 1) {
				input(p), input(q);
				union_(p, q);
			}
			else if (cmd == 2) {
				input(p), input(q);
				move_(p, q);
			}
			else if (cmd == 3) {
				input(p);
				print_(p);
			}
		}
	}
}