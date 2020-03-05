#include <iostream>
#include <math.h>
using namespace std;

int main() {
	int n,p,t,a,b;
	for (cin>>t;t;t--) {
		scanf("%d %d",&n,&p);
		a=ceil((double) ((double) (n/2)*p*6-1)/10+(n-n/2)*p+1);
		b=ceil((double) (n*p*812-1)/1000+1);
		if (a>b) printf("8-12=-4\n");
		else if (a<b) printf(": )\n");
		else printf("SAME\n");
	}
}