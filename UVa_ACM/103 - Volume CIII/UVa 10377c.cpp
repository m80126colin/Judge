#include <stdio.h>
int main() {
	int t,a,b,i,j,x,y,dir,dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};
	char map[61][61],face[5]="NESW",ch;
	for (scanf("%d",&t);t;t--) {
		scanf("%d%d%c",&a,&b,&ch);
		for (i=0;i<a;i++)
			for (j=0;j<=b;j++)
				scanf("%c",&map[i][j]);
		scanf("%d%d%c",&x,&y,&ch);
		x--,y--;
		dir=0;
		while (scanf("%c",&ch),ch!='Q') {
			if (ch=='R') dir=(dir+1)%4;
			else if (ch=='L') dir=(dir+3)%4;
			else if (ch=='F') {
				if (map[x+dx[dir]][y+dy[dir]]!='*') {
					x+=dx[dir];
					y+=dy[dir];
				}
			}
		}
		printf("%d %d %c\n",x+1,y+1,face[dir]);
		if (t>1) puts("");
	}
}