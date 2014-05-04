#include <stdio.h>
struct rect{
	double x1,y1,x2,y2;
};
typedef struct rect Rect;
int input(char *ch) {
	for (*ch=getchar() ; *ch==' '||*ch=='\n' ; *ch=getchar());
	return 1;
}
int main() {
	int i,ox,numofrect=0,numofpoint=0;
	double x,y;
	Rect r[11];
	char ch;
	while ( input(&ch)&& ch!='*') {
		numofrect++;
		scanf("%lf%lf%lf%lf",&r[numofrect].x1,&r[numofrect].y1,&r[numofrect].x2,&r[numofrect].y2);
	}
	while (scanf("%lf%lf",&x,&y)&&(x!=9999.9||y!=9999.9)) {
		numofpoint++;
		for (ox=0,i=1;i<=numofrect;i++) {
			if (x>r[i].x1&&x<r[i].x2&&y<r[i].y1&&y>r[i].y2) printf("Point %d is contained in figure %d\n",numofpoint,i),ox=1;
		}
		if (!ox) printf("Point %d is not contained in any figure\n",numofpoint);
	}
}