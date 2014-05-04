#include <stdio.h>
struct graph{
	char ch;
	double rad,x1,y1,x2,y2;
};
typedef struct graph Graph;
int input(char *ch) {
	for (*ch=getchar() ; *ch==' '||*ch=='\n' ; *ch=getchar());
	return 1;
}
int main() {
	int i,ox,numofgraph,numofpoint;
	double x,y;
	Graph r[11];
	char ch;
	numofgraph=numofpoint=0;
	while ( input(&ch)&& ch!='*') {
		numofgraph++;
		r[numofgraph].ch=ch;
		if (ch=='r') scanf("%lf%lf%lf%lf",&r[numofgraph].x1,&r[numofgraph].y1,&r[numofgraph].x2,&r[numofgraph].y2);
		else scanf("%lf%lf%lf",&r[numofgraph].x1,&r[numofgraph].y1,&r[numofgraph].rad);
	}
	while (scanf("%lf%lf",&x,&y)&&(x!=9999.9||y!=9999.9)) {
		numofpoint++;
		for (ox=0,i=1;i<=numofgraph;i++) {
			if (r[i].ch=='r') {
				if (x>r[i].x1&&x<r[i].x2&&y<r[i].y1&&y>r[i].y2) printf("Point %d is contained in figure %d\n",numofpoint,i),ox=1;
			}
			else {
				if ((x-r[i].x1)*(x-r[i].x1)+(y-r[i].y1)*(y-r[i].y1) < r[i].rad*r[i].rad) printf("Point %d is contained in figure %d\n",numofpoint,i),ox=1;
			}
		}
		if (!ox) printf("Point %d is not contained in any figure\n",numofpoint);
	}
}