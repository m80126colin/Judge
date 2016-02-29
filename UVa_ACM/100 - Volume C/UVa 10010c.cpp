#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main() {
	int t,m,n,i,j,k,h1,ctr,cx,cy,len;
	int x[8]={1,1,0,-1,-1,-1,0,1},y[8]={0,1,1,1,0,-1,-1,-1};
	char arr[50][51],s[51];
	for (scanf("%d",&t);t;t--) {
		scanf("%d%d",&m,&n);
		for (i=0;i<m;i++) scanf("%s",arr[i]);
		for (i=0;i<m;i++) {
			for (j=0;j<n;j++) arr[i][j]=tolower(arr[i][j]);
		}
		for (scanf("%d",&k);k;k--) {
			scanf("%s",&s);
			len=strlen(s);
			for (i=0;i<len;i++) s[i]=tolower(s[i]);
			for (i=0;i<m;i++) {
				for (j=0;j<n;j++) {
					if (arr[i][j]==s[0]) {
						for (h1=0;h1<8;h1++) {
							cx=i,cy=j;
							for (ctr=0;ctr<len;ctr++) {
								if (cx<0||cx>=m || cy<0||cy>=n || arr[cx][cy]!=s[ctr]) break;
								else cx+=x[h1],cy+=y[h1];
							}
							if (ctr==len) {
								printf("%d %d\n",i+1,j+1);
								i=m,j=n,h1=8;
							}
						}
					}
				}
			}
		}
		if (t>1) puts("");
	}
}