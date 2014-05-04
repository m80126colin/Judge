/*
Problem: d767
Language: CPP
Result: AC (198ms, 811KB) on ZeroJudge
Author: m80126colin at 2010-08-23 13:19:45
Solution: LCA, Lowest Common Ancestor
*/
#include <iostream>
#include <math.h>
using namespace std;

int n,q,pa[30001],a,b,i,j,tmp; //pa: father, tmp: square root of deepth
int l[30001],s[30001]; //l: seperate Layer, s: seperate Section

inline int fl(int x) { //construct layer
	if (x==pa[x]) return l[x];
	if (l[x]) return l[x];
	return l[x]=fl(pa[x])+1;
}

inline int dfs(int x) { //construct section
	if (s[x]) return s[x];
	if (l[x]%tmp) s[x]=dfs(pa[x]);
	else s[x]=pa[x];
	return s[x];
}

inline int ance(int x,int y) { //find LCA
	while (s[x]!=s[y]) (l[x]>l[y])?x=s[x]:y=s[y]; //find the common section
	while (x!=y) (l[x]>l[y])?x=pa[x]:y=pa[y]; //find the common ancestor
	return x;
}

int main() {
	scanf("%d %d",&n,&q);
	for (i=1;i<=n;i++) while (scanf("%d",&a),a) pa[a]=i; //construct father
	for (i=1;i<=n;i++) if (!pa[i]) pa[i]=i;
	for (i=1;i<=n;i++) tmp=max(fl(i),tmp);
	tmp=sqrt((double) tmp+1);
	for (i=1;i<=n;i++) dfs(i);
	for (i=1;i<=q;i++) {
		scanf("%d %d",&a,&b);
		j=ance(a,b);
		printf("%d %d\n",j,l[a]+l[b]-2*l[j]);
	}
}