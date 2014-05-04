#include <stdio.h>
int main() {
	int k,x,y,cx,cy,ctr;
	while (scanf("%d%d%d",&k,&x,&y)&&(k||x||y)) {
		ctr=0;
		cx=cy=2048/2;
		while (k) {
			if (cx-k<=x && x<=cx+k && cy-k<=y && y<=cy+k) ctr++;
			if (x==cx||y==cy) break;
			else if (x>cx && y>cy) cx+=k,cy+=k;
			else if (x>cx && y<cy) cx+=k,cy-=k;
			else if (x<cx && y>cy) cx-=k,cy+=k;
			else if (x<cx && y<cy) cx-=k,cy-=k;
			k>>=1;
		}
		printf("%3d\n",ctr);
	}
}