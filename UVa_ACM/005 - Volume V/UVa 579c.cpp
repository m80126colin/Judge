#include <stdio.h>
int main() {
	int h,m;
	double ah,am;
	while (scanf("%d:%d",&h,&m) && (h||m)) {
		ah=h*30+m*0.5;
		am=m*6;
		if (ah>am) ah-=am;
		else ah=am-ah;
		if (ah>180) ah=360-ah;
		printf("%.3lf\n",ah);
	}
}