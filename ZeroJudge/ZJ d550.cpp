/*
Problem: d550
Language: C++
Result: AC (375ms, 5327KB) on ZeroJudge
Author: m80126colin at 2010-07-09 13:40:13
Solution: Straight Forward
*/
#include <iostream>
#include <algorithm>
using namespace std;

int n,m,s[10000][200],h[10000];

bool cmp(int x,int y) {
	int i;
	for (i=0;i<m;i++) {
		if (s[x][i]!=s[y][i]) return s[x][i]<s[y][i];
	}
	return 1;
}

int main() {
	int i,j;
	while (~scanf("%d%d",&n,&m)) {
		for (i=0;i<n;i++) {
			h[i]=i;
			for (j=0;j<m;j++) scanf("%d",&s[i][j]);
		}
		sort(h,h+n,cmp);
		for (i=0;i<n;i++) {
			for (j=0;j<m;j++) printf("%d ",s[h[i]][j]);
			printf("\n");
		}
	}
}