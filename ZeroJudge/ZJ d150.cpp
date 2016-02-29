#include <iostream>
#include <algorithm>
using namespace std;

bool cmp(int x,int y) {
	return x>y;
}

int main() {
	int t,n,i,p[20001];
	for (cin>>t;t;t--) {
		for (cin>>n,i=1;i<=n;i++) scanf("%d",&p[i]);
		sort(p+1,p+n+1,cmp);
		for (p[0]=0,i=3;i<=n;i+=3) p[0]+=p[i];
		cout<<p[0]<<endl;
	}
}