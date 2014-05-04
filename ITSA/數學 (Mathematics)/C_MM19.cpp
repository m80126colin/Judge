#include <stdio.h>
int main(){
	int a;
	while (scanf("%d",&a)!=EOF) {
		if (a <= 800) printf("%.1lf\n",(double) a*0.9);
		else if (a < 1500) printf("%.1lf\n",(double) a*0.81);
		else printf("%.1lf\n",(double) a*0.711);
	}
}