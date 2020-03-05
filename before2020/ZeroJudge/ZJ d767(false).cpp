/*
Problem: d767
Language: CPP
Result: NA (score:98) on ZeroJudge
Author: m80126colin at 2010-08-23 09:10:07
Solution: LCA, Tarjan's Algorithm
*/
#include <iostream>
using namespace std;

int n,q,pa[30001],a,b,i,j,k,ct[30001];

int ox() {
	int x;
	for (x=0;x<=j;x++) {
		if (b==ct[x]) return x;
	}
	return -1;
}

int main() {
	scanf("%d %d",&n,&q);
	for (i=1;i<=n;i++) {
		while (scanf("%d",&a),a) pa[a]=i;
	}
	for (i=1;i<=q;i++) {
		scanf("%d %d",&a,&b);
		ct[0]=a;
		for (j=1;a;j++) {
			a=pa[a];
			ct[j]=a;
		}
		j--;
		for (k=0;ox()&(1<<31);k++) b=pa[b];
		printf("%d %d\n",b,k+ox());
	}
}