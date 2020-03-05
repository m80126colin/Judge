#include <iostream>
#include <algorithm>
using namespace std;

struct poi{
	int x;
	int y;
	int t;
};

bool cmp(poi x,poi y) {
	return x.t<y.t;
}

int main() {
	poi a[1001];
	int n,i,j;
	while (cin>>n) {
		for (i=1;i<=n;i++) {
			cin>>a[i].x>>a[i].y;
			a[i].t=0;
			for (j=1;j<i;j++) {
				a[j].t+=abs(a[i].x-a[j].x)+abs(a[i].y-a[j].y);
				a[i].t+=abs(a[i].x-a[j].x)+abs(a[i].y-a[j].y);
			}
		}
		sort(a+1,a+n+1,cmp);
		cout<<a[1].x<<" "<<a[1].y<<endl<<a[1].t<<endl;
	}
}