#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

struct oo {
	int a;
	double b;
};

bool cmp(oo x,oo y) {
	return x.b<y.b ;
}

int main() {
	int t,n,s,x1,x2,y1,y2,i;
	oo z[101];
	for (cin>>t;t;t--) {
		for (cin>>n,i=1;i<=n;i++) {
			scanf("%d %d %d %d %d",&x1,&y1,&x2,&y2,&s);
			z[i].a=i;
			z[i].b=(double) sqrt((double) (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))*s/abs(x1-x2);
		}
		sort(z+1,z+n+1,cmp);
		printf("%d\n",z[1].a);
	}
}