#include <iostream>
using namespace std;

struct dp{
	bool ox;
	int step;
}d[10000];
int bits[37],adj[24][2]={{0,2},{0,3},{1,2},{1,5},{2,3},{2,5},{2,6},{3,4},{3,6},{3,7},{4,7},{5,6},{5,8},{5,9},{6,7},{6,9},{6,10},{7,10},{7,11},{8,9},{9,10},{9,12},{10,11},{10,12}};
int n,k,i,j,x;

int main() {
	for (i=0;i<=12;i++) bits[i]=1<<i;
	for (i=0;i<24;i++) bits[i+13]=bits[adj[i][0]]+bits[adj[i][1]];
	while (~scanf("%d",&n)) {
		for (i=1;i<=n;i++) {
			scanf("%d",&k);
			memset(d,0,sizeof(d));
			d[0].ox=1;
			for (j=0;j<=k;j++) {
				for (x=36;x==0;x--) {
					if ((k&bits[x])&&!(j&bits[x])) {
						if (!d[j+bits[x]].ox) {
							d[j+bits[x]].step=d[j].step+1;
							d[j+bits[x]].ox=1;
						} else if (d[j].step+1<d[j+bits[x]].step) d[j+bits[x]].step=d[j].step+1;
					}
				}
			}
			printf("%d ",(d[k].step+1)&1);
		}
		puts("");
	}
}