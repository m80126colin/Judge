#include <stdio.h>
typedef struct point Point;
struct point {
	double x,y;
};
int input(Point p[4]) {
	int i;
	for (i=0;i<4;i++) {
		if (scanf("%lf%lf",&p[i].x,&p[i].y)==EOF) return 0;
	}
	return 1;
}
int same(Point p1,Point p2) {
	return (p1.x==p2.x) && (p1.y==p2.y);
}
inline void swap(Point *p1,Point *p2) {
	double temp;
	temp=p1->x;
	p1->x=p2->x;
	p2->x=temp;
	temp=p1->y;
	p1->y=p2->y;
	p2->y=temp;
	return;
}
int main() {
	Point p[4];
	while (input(p)) {
		if (same(p[0],p[2])) swap(&p[0],&p[1]);
		else if (same(p[0],p[3])) swap(&p[0],&p[1]),swap(&p[2],&p[3]);
		else if (same(p[1],p[3])) swap(&p[2],&p[3]);
		printf("%.3lf %.3lf\n",p[0].x+p[3].x-p[2].x,p[0].y+p[3].y-p[2].y);
	}
}