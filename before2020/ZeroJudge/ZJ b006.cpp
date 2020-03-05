#include <iostream>
#include <algorithm>
using namespace std;

struct cube{
	int a;
	int b;
};

bool cmp(cube x,cube y) {
	if (x.a==y.a) return x.b>y.b;
	return x.a>y.a;
}

int main() {
	int n,i,a[30001];
	cube c[30001];
	while (cin>>n) {
		for (i=1;i<=n;i++) {
			cin>>c[i].a>>c[i].b;
			if (c[i].a<c[i].b) swap(c[i].a,c[i].b);
		}
		sort(c+1,c+n+1,cmp);
		for (a[1]=1,i=2;i<=n;i++) {
			if (c[i].a<=c[i-1].a&&c[i].b<=c[i-1].b) a[i]=a[i-1]+1;
			else a[i]=a[i-1];
		}
		cout<<a[n]<<endl;
	}
}