#include <stdio.h>
int abs(int x) {
	if (x<0) return -x;
	return x;
}
int main() {
	int l,i,z,r,d,minmum;
	char ch;
	while (scanf("%d",&l),l) {
		minmum=l;
		z=r=d=0;
		for (i=0;i<=l;i++) {
			ch=getchar();
			if (ch=='Z') z++;
			else if (ch=='R') {
				if ((r&&d)&&minmum>abs(r-d)) minmum=abs(r-d);
				r=i;
				if ((r&&d)&&minmum>abs(r-d)) minmum=abs(r-d);
			}
			else if (ch=='D') {
				if ((r&&d)&&minmum>abs(r-d)) minmum=abs(r-d);
				d=i;
				if ((r&&d)&&minmum>abs(r-d)) minmum=abs(r-d);
			}
		}
		if (z) puts("0");
		else printf("%d\n",minmum);
	}
}