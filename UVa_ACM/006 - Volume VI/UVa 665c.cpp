#include <stdio.h>
int main() {
	int n,k,i,j,h1,t,p,left[50],right[50],temp,ox;
	int coin[101],group[100];
	char result[2];
	for (scanf("%d",&t);t;t--) {
		scanf("%d%d",&n,&k);
		for (i=1;i<=n;i++) coin[i]=i,group[i]=0;
		for (i=0;i<k;i++) {
			scanf("%d",&p);
			for (j=0;j<p;j++) scanf("%d",&left[j]);
			for (j=0;j<p;j++) scanf("%d",&right[j]);
			scanf("%s",result);
			if (result[0] == '=') {
				for (j=1;j<p;j++) {
					temp = coin[left[j]];
					for (h1=1;h1<=n;h1++) {
						if (coin[h1] == temp) coin[h1] = coin[left[0]];
					}
				}
				for (j=0;j<p;j++) {
					temp = coin[right[j]];
					for (h1=1;h1<=n;h1++) {
						if (coin[h1] == temp) coin[h1] = coin[left[0]];
					}
				}
			}
		}
		for (i=1;i<=n;i++) group[coin[i]]++;
		ox=0;
		for (i=1;i<=n;i++) {
			if (group[i]==1) ox++,temp=i;
		}
		if (ox==1) printf("%d\n",temp);
		else puts("0");
		if (t>1) puts("");
	}
}