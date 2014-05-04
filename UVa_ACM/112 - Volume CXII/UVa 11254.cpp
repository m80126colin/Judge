#include <iostream>
#include <math.h>
using namespace std;

int main() {
	int n,i,j;
	while (scanf("%d",&n),n>=0) {
		for (i=sqrt((double)2*n);i;i--) {
			if (!((n<<1)%i)) {
				j=2*n/i-i+1;
				if (!(j&1)) break;
			}
		}
		j>>=1;
		printf("%d = %d + ... + %d\n",n,j,j+i-1);
	}
}