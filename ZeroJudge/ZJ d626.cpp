/*
Problem: d626
Language: C++
Result: AC (2ms, 706KB) on ZeroJudge
Author: m80126colin at 2010-07-13 16:55:33
Solution: Flood or DFS
*/
#include <iostream>
using namespace std;

int n;
bool ox[101][101],ox2[101][101];

inline void flood(int x,int y) {
	if (ox[x][y]||ox2[x][y]) return;
	ox2[x][y]=1;
	if (x-1) flood(x-1,y);
	if (y-1) flood(x,y-1);
	if (x+1<=n) flood(x+1,y);
	if (y+1<=n) flood(x,y+1);
}

int main() {
	int i,j;
	char ch;
	scanf("%d\n",&n);
	for (i=1;i<=n;i++) {
		for (j=1;j<=n;j++) {
			ch=getchar();
			while (ch=='\n'||ch==' ') ch=getchar();
			ox[i][j]=ch=='+';
		}
	}
	flood(1,1);
	for (i=1;i<=n;i++) {
		for (j=1;j<=n;j++) putchar((ox2[i][j]|ox[i][j]?'+':'-'));
		puts("");
	}
}