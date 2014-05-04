#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	static int n,m,i,j,k,l,map[1001][1001];
	while (cin>>n>>m,n||m) {
		memset(map,0,sizeof(map));
		for (i=1;i<=m;i++) {
			scanf("%d %d %d",&j,&k,&l);
			map[k][j]=map[j][k]=max(l,map[j][k]);
		}
		for (k=1;k<=n;k++)
			for (i=1;i<=n;i++)
				for (j=1;j<=n;j++)
					map[i][j]=max(map[i][j],min(map[i][k],map[k][j]));
		scanf("%d %d",&i,&j);
		printf("%d\n",map[i][j]);
	}
}