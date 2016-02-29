#include <stdio.h>
#include <string.h>
inline int judge(char ch) {
	return (ch=='R') - (ch=='F');
}
int main() {
	//freopen("a.out","w",stdout);
	int t,ctr,len,i,j,k,seg[51],dseg[51],minn,maxn;
	char s[51];
	for (scanf("%d",&t),ctr=1;ctr<=t;ctr++) {
		scanf("%s",&s);
		len = strlen(s);
		dseg[0]=judge(s[0]);
		minn=maxn=seg[0]=0;
		for (i=1;i<len;i++) {
			dseg[i]=judge(s[i]);
			seg[i]=seg[i-1];
			if (dseg[i-1]>0) seg[i]++;
			if (dseg[i]<0) seg[i]--;
			if (seg[i]<minn) minn=seg[i];
			if (seg[i]>maxn) maxn=seg[i];
		}
		printf("Case #%d:\n",ctr);
		for (i=maxn;i>=minn;i--) {
			putchar('|'),putchar(' ');
			for (j=0;j<len;j++) {
				if (seg[j]==i) {
					for (k=j-1;k>=0;k--) {
						if (seg[k]==seg[j]) break;
						else putchar(' ');
					}
					if (dseg[j]) {
						if (dseg[j]>0) putchar('/');
						else putchar('\\');
					}
					else putchar('_');
				}
			}
			puts("");
		}
		putchar('+'),putchar('-');
		for (j=0;j<=len;j++) putchar('-');
		puts(""),puts("");
	}
}