#include <stdio.h>
#include <string.h>
int main() {
	int i,mapx,mapy,cx,cy,cdir,x[4]={0,1,0,-1},y[4]={1,0,-1,0},lost,scent[51][51]={{0}};
	char direct[5]="NESW",s[101],ch;
	scanf("%d%d",&mapx,&mapy);
	while (scanf("%d%d%c%c",&cx,&cy,&ch,&ch)!=EOF) {
		lost=1;
		for (i=0;i<4;i++) if (ch==direct[i]) cdir=i;
		scanf("%s",&s);
		for (i=0;i<strlen(s);i++) {
			if (s[i]=='L') cdir=(cdir+3)%4;
			else if (s[i]=='R') cdir=(cdir+1)%4;
			else if (s[i]=='F'&&lost) {
				if (lost && 0<=cx+x[cdir] && cx+x[cdir]<=mapx && 0<=cy+y[cdir] && cy+y[cdir]<=mapy) {
					cx+=x[cdir],cy+=y[cdir];
				}
				else if (scent[cx][cy]) continue;
				else if (lost) {
					lost=0;
					scent[cx][cy]=1;
				}
			}
		}
		printf("%d %d %c",cx,cy,direct[cdir]);
		if (!lost) printf(" LOST");
		puts("");
	}
}