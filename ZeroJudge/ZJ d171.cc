#include <iostream>
#include <math.h>
using namespace std;

int main() {
	int n,m;
	while (scanf("%d %d",&n,&m)!=EOF) {
		n=(double) m*log10((double) n)+1;
		printf("%d\n",n);
	}
}