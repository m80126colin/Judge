#include <stdio.h>
int main() {
	int t,ctr,n,r,map[101][101],i,j,k,mm,s,e;
	for (scanf("%d",&t),ctr=1;ctr<=t;ctr++) {
		scanf("%d%d",&n,&r);
		for (i=0;i<n;i++)
			for (j=0;j<n;j++)
				map[i][j]= (i==j) ? 0 : 1e9;
		for (i=0;i<r;i++){
			scanf("%d%d",&j,&k);
			map[j][k]=map[k][j]=1;
		}
		scanf("%d%d",&s,&e);
		for (k=0;k<n;k++)
			for (i=0;i<n;i++)
				for (j=0;j<n;j++)
					map[i][j] = (map[i][j] > map[i][k] + map[k][j]) ? map[i][k]+map[k][j] : map[i][j] ;
		mm=0;
		for (k=0;k<n;k++) mm = (map[s][k] + map[k][e] > mm && map[s][k] + map[k][e] < 1e9) ? map[s][k]+map[k][e] : mm ;
		printf("Case %d: %d\n",ctr,mm);
	}
}