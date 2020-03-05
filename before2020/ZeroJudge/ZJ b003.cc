#include <iostream>
#include <math.h>
using namespace std;

int main() {
	int k,n,s;
	while (scanf("%d",&k)!=EOF) {
		k=abs(k);
		for (n=1,s=(n*(n+1))/2;s%2!=k%2||s<k;s=(n*(n+1))/2) n++;
		printf("%d\n",n);
	}
}