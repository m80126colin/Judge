#include <iostream>
#include <algorithm>
using namespace std;

struct bo{
	int a;
	int b;
};

bool cmp(bo x,bo y) {
	if (x.b==y.b) return x.a>y.a;
	return x.b>y.b;
}

int main() {
	int n,i,t,ti;
	static bo z[10001];
	while (cin>>n&&n) {
		memset(z,0,sizeof(z));
		for (i=1;i<=n;i++) cin>>z[i].a>>z[i].b;
		sort(z+1,z+n+1,cmp);
		t=ti=0;
		for (i=1;i<=n;i++) {
			t+=z[i].a;
			ti>?=t+z[i].b;
		}
		cout<<ti<<endl;
	}
}