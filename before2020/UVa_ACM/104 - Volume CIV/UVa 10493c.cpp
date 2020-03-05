#include <stdio.h>
int main() {
	int n,m;
	while (scanf("%d%d",&n,&m),n||m) {
		if (n-1) {
			if ((m-1)%(n-1)) printf("%d %d Impossible\n",n,m);
			else printf("%d %d %d\n",n,m,m+(m-1)/(n-1));
		}
		else if (m-1) printf("%d %d Impossible\n",n,m);
		else printf("%d %d Multiple\n",n,m);
	}
}