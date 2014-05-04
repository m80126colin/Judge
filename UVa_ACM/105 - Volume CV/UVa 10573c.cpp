#include <stdio.h>
#include <math.h>
const double pi = 2.0*acos(0.0);
int main() {
	char ch;
	int t,n,m;
	for (scanf("%d",&t);t;t--) {
		scanf("%d%c",&n,&ch);
		if (ch=='\n') {
			printf("%.4lf\n",pi*n*n/8.0);
		}
		else {
			scanf("%d",&m);
			printf("%.4lf\n",pi*2.0*n*m);
		}
	}
}