#include <iostream>
using namespace std;

struct tt{
	int h,m,s;
};

int main() {
	tt a,b;
	while (scanf("%d:%d:%d",&a.h,&a.m,&a.s)!=EOF) {
		scanf("%d:%d:%d",&b.h,&b.m,&b.s);
		b.s-=a.s;
		if (b.s<0) b.m--,b.s+=60;
		b.m-=a.m;
		if (b.m<0) b.h--,b.m+=60;
		b.h-=a.h;
		if (b.h<0) b.h+=24;
		printf("%02d:%02d:%02d\n",b.h,b.m,b.s);
	}
}