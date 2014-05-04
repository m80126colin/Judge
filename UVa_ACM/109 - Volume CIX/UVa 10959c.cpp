#include <stdio.h>
int main() {
	int i,j,k;
	int t,p,d,num[1000],queue[1000];
	static int walk1[500000],walk2[500000];
	for (scanf("%d",&t);t;t--) {
		scanf("%d%d",&p,&d);
		for (i=0;i<d;i++) scanf("%d%d",&walk1[i],&walk2[i]);
		for (i=0;i<p;i++) num[i]=-1;
		num[0]=0;
		queue[0]=0;
		for (i=0,j=1;i<j;i++) {
			for (k=0;k<d;k++) {
				if (walk1[k]==queue[i]) {
					if (num[walk2[k]]==-1) queue[j++]=walk2[k],num[walk2[k]]=num[queue[i]]+1;
				}
				else if (walk2[k]==queue[i]) {
					if (num[walk1[k]]==-1) queue[j++]=walk1[k],num[walk1[k]]=num[queue[i]]+1;
				}
			}
		}
		for (i=1;i<p;i++) printf("%d\n",num[i]);
		if (t>1) puts("");
	}
}